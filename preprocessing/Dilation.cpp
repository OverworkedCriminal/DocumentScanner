#include "DocumentScanner/preprocessing/Dilation.hpp"
#include <opencv2/imgproc.hpp>

namespace ds
{
    Dilation::Dilation(int krows, int kcols) noexcept
    {
        _kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(krows, kcols));
    }

    void Dilation::process(const cv::Mat& input, cv::Mat& output) noexcept
    {
        cv::dilate(input, output, _kernel);
    }
}