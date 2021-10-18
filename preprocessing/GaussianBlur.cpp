#include "DocumentScanner/preprocessing/GaussianBlur.hpp"

#include <opencv2/imgproc.hpp>

namespace ds
{
    GaussianBlur::GaussianBlur(const cv::Size& ksize, double sigmaX, double sigmaY) noexcept
    {
        _ksize = ksize;
        _sigmaX = sigmaX;
        _sigmaY = sigmaY;
    }

    void GaussianBlur::process(const cv::Mat& input, cv::Mat& output)
    {
        cv::GaussianBlur(input, output, _ksize, _sigmaX, _sigmaY);
    }
}
