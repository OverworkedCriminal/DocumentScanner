#include "DocumentScanner/preprocessing/Grayscale.hpp"

#include <opencv2/imgproc.hpp>

namespace ds
{
    Grayscale::Grayscale()
    {
        
    }

    void Grayscale::process(const cv::Mat& input, cv::Mat& output)
    {
        cv::cvtColor(input, output, cv::COLOR_BGR2GRAY);
    }
}