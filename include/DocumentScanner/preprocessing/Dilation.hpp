#ifndef DOCUMENTSCANNER_PREPROCESSING_DILATION_HPP
#define DOCUMENTSCANNER_PREPROCESSING_DILATION_HPP

#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for dilating edges.
     * 
     */
    class Dilation final :public IPreprocessingStage
    {
    private:
        cv::Mat _kernel;

    public:

        /**
         * @brief 
         * 
         * @param krows rows of dilation kernel
         * @param kcols columns of dilation kernel
         */
        Dilation(int krows, int kcols) noexcept;
        
        void process(const cv::Mat& input, cv::Mat& output) noexcept override;
    };
}


#endif