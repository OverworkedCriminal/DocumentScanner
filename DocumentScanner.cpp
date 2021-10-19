#include "DocumentScanner/DocumentScanner.hpp"

#include <cassert>
#include <opencv2/imgproc.hpp>

namespace ds
{
    DocumentScanner::DocumentScanner(
        const std::vector<std::shared_ptr<IPreprocessingStage>>& preprocessingStages,
        const std::shared_ptr<ContoursFinder>& contoursFinder,
        const std::shared_ptr<ICornersFinder>& cornersFinder)
    {
        assert(contoursFinder != nullptr);
        assert(cornersFinder != nullptr);

        setProcessingStages(preprocessingStages);
        setContoursFinder(contoursFinder);
        setCornersFinder(cornersFinder);
    }

    
    void DocumentScanner::scan(const cv::Mat& input, cv::Mat& output,
                               const cv::Size& outputSize)
    {
        _buffers[0] = input;
        for (std::size_t i{ 0 }; i < _processingStages.size(); ++i)
            _processingStages[i]->process(_buffers[i], _buffers[i + 1]);

        _contoursFinder->findContours(_buffers.back(), _contours);
        _cornersFinder->findCorners(_contours, _corners);

        std::array<cv::Point2f, 4> warpedCorners {
            cv::Point2f(0.0f, 0.0f),                          // TL
            cv::Point2f(outputSize.width,0.0f),               // TR
            cv::Point2f(0.0f, outputSize.height),             // BL
            cv::Point2f(outputSize.width, outputSize.height)  // BR
        };
        
        cv::Mat transform{ cv::getPerspectiveTransform(_corners, warpedCorners) };
        cv::warpPerspective(input, output, transform, outputSize);
    }

    void DocumentScanner::setProcessingStages(
        const std::vector<std::shared_ptr<IPreprocessingStage>>& stages)
    {
        _processingStages = stages;
        _buffers.resize(_processingStages.size() + 1);
    }

    void DocumentScanner::setContoursFinder(
        const std::shared_ptr<ContoursFinder>& finder)
    {
        _contoursFinder = finder;
    }

    void DocumentScanner::setCornersFinder(
        const std::shared_ptr<ICornersFinder>& finder)
    {
        _cornersFinder = finder;
    }
}
