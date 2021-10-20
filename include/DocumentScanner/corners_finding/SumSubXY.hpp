#ifndef DOCUMENTSCANNER_CORNERSFINDING_SUM_SUB_XY_HPP
#define DOCUMENTSCANNER_CORNERSFINDING_SUM_SUB_XY_HPP

#include "DocumentScanner/corners_finding/ICornersFinder.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for finding corners.
     * The way it happens is firstly are calculated 2 values
     * from points.
     * SUM: x + y
     * SUB: x - y
     * Then corners are selected basing on calculated values
     * TL = min(SUM)
     * TR = max(SUB)
     * BL = min(SUB)
     * BR = max(SUM)
     *
     */
    class SumSubXY final :public ICornersFinder
    {
        void findCorners(std::vector<std::vector<cv::Point>>& input,
                                 std::array<cv::Point2f, 4>& output) override;
    };    
}

#endif