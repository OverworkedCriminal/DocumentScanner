#ifndef DOCUMENTSCANNER_PREPROCESSING_I_PREPROCESSING_STAGE_HPP
#define DOCUMENTSCANNER_PREPROCESSING_I_PREPROCESSING_STAGE_HPP

#include <opencv2/core/mat.hpp>

namespace ds
{
    /**
     * @brief Interface responsible for processing image before
     * warping document's perspective
     *
     */
    class IPreprocessingStage
    {
    public:
        virtual ~IPreprocessingStage() {}

        /**
         * @brief Process input image and write result into
         * output image
         *
         * @param input 
         * @param output 
         */
        virtual void process(const cv::Mat& input, cv::Mat& output) = 0;
    };    
}

#endif