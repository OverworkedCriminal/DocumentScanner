#include "DocumentScanner/preprocessing/Threshold.hpp"

namespace ds
{
    Threshold::Threshold(double threshold, double maxval, int type) noexcept
    {
        _threshold = threshold;
        _maxval = maxval;
        _type = type;
    }

    void Threshold::process(const cv::Mat& input, cv::Mat& output)
    {
        cv::threshold(input, output, _threshold, _maxval, _type);
    }
}