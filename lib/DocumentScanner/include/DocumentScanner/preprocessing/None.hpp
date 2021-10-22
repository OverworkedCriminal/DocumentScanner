#ifndef DOCUMENTSCANNER_PREPROCESSING_NONE_HPP
#define DOCUMENTSCANNER_PREPROCESSING_NONE_HPP

#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class for convenience allows skipping preprocessing stage
     * by simply rewriting input to the output.
     *
     */
    class None final :public IPreprocessingStage
    {
    public:
        void process(const cv::Mat& input, cv::Mat& output);
    };    
}

#endif