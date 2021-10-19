#include "DocumentScanner/preprocessing/None.hpp"

namespace ds
{
    void None::process(const cv::Mat& input, cv::Mat& output)
    {
        input.copyTo(output);
    }
}