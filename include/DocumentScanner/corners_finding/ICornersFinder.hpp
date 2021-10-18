#ifndef DOCUMENTSCANNER_CORNERSFINDING_I_CORNER_FINDER_HPP
#define DOCUMENTSCANNER_CORNERSFINDING_I_CORNER_FINDER_HPP

#include <vector>
#include <array>
#include <opencv2/core.hpp>

namespace ds
{
    class ICornersFinder
    {
    public:
        virtual ~ICornersFinder() {}

        /**
         * @brief Finds corner points in vector and write them
         * to output array in order:
         * TL, TR, BL, BR
         *
         * @param input vector of points. (order of elements might be altered)
         * @param output output array of points
         */
        virtual void findCorners(std::vector<std::vector<cv::Point>>& input,
                                 std::array<cv::Point2f, 4>& output) = 0;

    };
}


#endif