#include "DocumentScanner/DocumentScanner.hpp"

#include <cassert>
#include <opencv2/imgproc.hpp>

#ifdef DEBUG
#include <opencv2/highgui.hpp>
#define DEBUG_DRAW(name, image) cv::imshow(name, image)
#define DEBUG_DRAW_CONTOURS(name, image, contours) \
    cv::Mat tmp1; \
    image.copyTo(tmp1); \
    for (size_t i{ 0 }; i < contours.size(); ++i) \
        cv::drawContours(tmp1, contours, i, cv::Scalar(0, 255, 255)); \
    DEBUG_DRAW(name, tmp1)
#define DEBUG_DRAW_CORNERS(name, image, corners) \
    const char* cornerNames[4]{"TL", "TR", "BL", "BR" }; \
    cv::Mat tmp2; \
    image.copyTo(tmp2); \
    for (size_t i{ 0 }; i < corners.size(); ++i) \
    { \
        cv::circle(tmp2, corners[i], 3, cv::Scalar(0, 255, 255)); \
        cv::putText(tmp2, cornerNames[i], corners[i], \
                    cv::FONT_HERSHEY_DUPLEX, 1.0, cv::Scalar(255, 255, 255)); \
    } \
    DEBUG_DRAW(name, tmp2)
#else
#define DEBUG_DRAW(name, image)
#define DEBUG_DRAW_CONTOURS(name, image, contours)
#define DEBUG_DRAW_CORNERS(name, image, corners)
#endif

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
        {
            _processingStages[i]->process(_buffers[i], _buffers[i + 1]);
            DEBUG_DRAW(std::to_string(i), _buffers[i + 1]);
        }

        _contoursFinder->findContours(_buffers.back(), _contours);
        DEBUG_DRAW_CONTOURS("Contours", input, _contours);
        
        _cornersFinder->findCorners(_contours, _corners);
        DEBUG_DRAW_CORNERS("Corners", input, _corners);

        const auto& [w, h] { outputSize };
        std::array<cv::Point2f, 4> warpedCorners{
            cv::Point2f(0.0f, 0.0f), // TL
            cv::Point2f(   w, 0.0f), // TR
            cv::Point2f(0.0f, h),    // BL
            cv::Point2f(   w, h)     // BR
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
