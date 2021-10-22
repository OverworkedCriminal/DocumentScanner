#ifndef DOCUMENTSCANNER_CORNERSFINDING_MIN_MAX_XY_HPP
#define DOCUMENTSCANNER_CORNERSFINDING_MIN_MAX_XY_HPP

#include "DocumentScanner/corners_finding/ICornersFinder.hpp"

namespace ds
{
    /**
     * @brief Class responsible for finding corner points.
     * The way it does it is very basic.
     * First it searches for min and max values of X and Y.
     * Then it checks which point is topmost.
     * There are two possible layouts:
     *
     * 1.
     *     POINTS LAYOUT (rotated left)
     *              Y_MIN
     *   X_MIN     
     * 
     * 
     *                X_MAX
     *     Y_MAX
     *
     *
     * 2.
     *     POINTS LAYOUT (rotated right)
     *      Y_MIN
     *                  X_MAX          
     * 
     * 
     *  X_MIN
     *             Y_MAX
     *
     *
     */
    class MinMaxXY final :public ICornersFinder
    {
    public:
        
        /**
         * @brief Finds corner points in vector and write them
         * to output array in order:
         * TL, TR, BL, BR
         *
         * @param input vector of points. (order of elements might be altered)
         * @param output output array of points
         */
        void findCorners(std::vector<std::vector<cv::Point>>& input,
                         std::array<cv::Point2f, 4>& output) override;
    };    
}


#endif