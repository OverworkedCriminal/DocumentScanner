#include "DocumentScanner/preprocessing/Canny.hpp"

#include <opencv2/imgproc.hpp>

namespace ds
{
    Canny::Canny(double lowerThreshold, double upperThreshold) noexcept
    {
        _lowerThreshold = lowerThreshold;
        _upperThreshold = upperThreshold;
    }

    void Canny::process(const cv::Mat& input, cv::Mat& output)
    {
        cv::Canny(input, output, _lowerThreshold, _upperThreshold);
    }
}
