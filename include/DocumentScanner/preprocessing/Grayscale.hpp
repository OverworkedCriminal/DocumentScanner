#ifndef DOCUMENTSCANNER_PREPROCESSING_GRAYSCALE_HPP
#define DOCUMENTSCANNER_PREPROCESSING_GRAYSCALE_HPP

#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for converting BGR image to Grayscale
     * 
     */
    class Grayscale final :public IPreprocessingStage
    {
    public:
        Grayscale();

        void process(const cv::Mat& input, cv::Mat& output) override;
    };
}

#endif