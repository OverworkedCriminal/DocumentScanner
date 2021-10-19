#ifndef DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP
#define DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP

#include <vector>
#include <memory>

#include <opencv2/core/mat.hpp>
#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"
#include "DocumentScanner/ContoursFinder.hpp"
#include "DocumentScanner/corners_finding/ICornersFinder.hpp"

namespace ds
{
    /**
     * @brief Class responsible for scanning documents
     * 
     */
    class DocumentScanner
    {
    private:

        std::vector<std::shared_ptr<IPreprocessingStage>> _processingStages;

        /**
         * vector of buffers.
         * Its size should be _processingStages.size() + 1.
         * Element at index 0 is always replaced with input
         * on scan() call.
         */
        std::vector<cv::Mat> _buffers;

        std::vector<std::vector<cv::Point>> _contours;
        std::array<cv::Point2f, 4> _corners;

        std::shared_ptr<ContoursFinder> _contoursFinder;
        std::shared_ptr<ICornersFinder> _cornersFinder;

    public:

        /**
         * @brief 
         *
         * @param preprocessingStages 
         * @param contoursFinder it cannot be a nullptr
         * @param cornersFinder it cannot be a nullptr
         */
        DocumentScanner(
            const std::vector<std::shared_ptr<IPreprocessingStage>>& preprocessingStages,
            const std::shared_ptr<ContoursFinder>& contoursFinder,
            const std::shared_ptr<ICornersFinder>& cornersFinder);


        /**
         * @brief Find document in input image and write it's warped
         * perspective into output image.
         *
         * @param input 
         * @param output 
         */
        void scan(const cv::Mat& input, cv::Mat& output, const cv::Size& outputSize);

        void setProcessingStages(
            const std::vector<std::shared_ptr<IPreprocessingStage>>& stages);

        inline void setContoursFinder(const std::shared_ptr<ContoursFinder>& finder);

        inline void setCornersFinder(const std::shared_ptr<ICornersFinder>& finder);
    };
}


#endif