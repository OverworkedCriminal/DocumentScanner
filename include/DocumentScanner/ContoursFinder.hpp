#ifndef DOCUMENTSCANNER_CONTOURS_FINDER_HPP
#define DOCUMENTSCANNER_CONTOURS_FINDER_HPP

#include <opencv2/core/mat.hpp>
#include <vector>

namespace ds
{
    class ContoursFinder
    {
    private:
        int _mode;
        int _method;

    public:

        /**
         * @brief 
         * 
         * @param mode Contour retrieval mode. Available modes can be found at:
         * https://docs.opencv.org/4.5.3/d3/dc0/group__imgproc__shape.html#ga819779b9857cc2f8601e6526a3a5bc71
         * @param method Contour approximation method. Available methods can be found at:
         * https://docs.opencv.org/4.5.3/d3/dc0/group__imgproc__shape.html#ga4303f45752694956374734a03c54d5ff
         */
        ContoursFinder(int mode, int method);

        /**
         * @brief Method finds contours on edge exposed image and writes
         * it to the output vector
         *
         * @param input image with exposed edges
         * @param output vector of vectors containing Points
         */
        void findContours(const cv::Mat& input,
            std::vector<std::vector<cv::Point>>& contours) const noexcept;
    };
}


#endif