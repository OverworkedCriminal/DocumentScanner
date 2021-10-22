#ifndef DOCUMENTSCANNER_PREPROCESSING_GAUSSIAN_BLUR_HPP
#define DOCUMENTSCANNER_PREPROCESSING_GAUSSIAN_BLUR_HPP

#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for applying Gaussian blur
     */
    class GaussianBlur final :public IPreprocessingStage
    {
    private:
        cv::Size _ksize;
        double _sigmaX;
        double _sigmaY;

    public:

        /**
         * @brief Construct a new Gaussian Blur object
         * 
         * @param ksize Gaussian kernel size. ksize.width and ksize.height can differ but they both must be
         * positive and odd. Or, they can be zero's and then they are computed from sigma.
         * @param sigmaX Gaussian kernel standard deviation in X direction.
         * @param sigmaY Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be
         * equal to sigmaX, if both sigmas are zeros, they are computed from ksize.width and ksize.height,
         * respectively (see #getGaussianKernel for details); to fully control the result regardless of
         * possible future modifications of all this semantics, it is recommended to specify all of ksize,
         * sigmaX, and sigmaY.
         */
        GaussianBlur(const cv::Size& ksize, double sigmaX, double sigmaY) noexcept;
        
        virtual void process(const cv::Mat& input, cv::Mat& output) override;
    };
}


#endif
