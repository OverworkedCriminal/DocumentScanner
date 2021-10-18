#include "DocumentScanner/ContoursFinder.hpp"
#include <opencv2/imgproc.hpp>


namespace ds
{
    ContoursFinder::ContoursFinder(int mode, int method)
    {
        _mode = mode;
        _method = method;
    }

    void ContoursFinder::findContours(const cv::Mat& input,
        std::vector<std::vector<cv::Point>>& output) const noexcept
    {
        cv::findContours(input, output, _mode, _method);
    }
}