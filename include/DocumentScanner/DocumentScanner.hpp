#ifndef DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP
#define DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP

#include <vector>

#include <opencv2/core/mat.hpp>
#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"



namespace ds
{
    /**
     * @brief Class responsible for scanning documents
     * 
     */
    class DocumentScanner
    {
    private:

        std::vector<IPreprocessingStage> _processingStages;

        /**
         * vector of buffers.
         * Its size should be _processingStages.size() + 1.
         * Element at index 0 is always replaced with input
         * on scan() call.
         */
        std::vector<cv::Mat> _buffers;

    public:

        /**
         * @brief Find document in input image and write it's warped
         * perspective into output image.
         *
         * @param input 
         * @param output 
         */
        void scan(const cv::Mat& input, cv::Mat& output);
    };    
}


#endif