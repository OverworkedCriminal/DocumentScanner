#include "DocumentScanner/corners_finding/MinMaxXY.hpp"

namespace ds
{
    void MinMaxXY::findCorners(std::vector<std::vector<cv::Point>>& input,
                               std::array<cv::Point2f, 4>& output)
    {
        cv::Point* minX{ &input[0][0] }, * maxX{ &input[0][0] };
        cv::Point* minY{ &input[0][0] }, * maxY{ &input[0][0] };

        for (auto& vec : input)
        {
            for (auto& p : vec)
            {
                if (p.x < minX->x)
                    minX = &p;
                else if (p.x > maxX->x)
                    maxX = &p;

                if (p.y < minY->y)
                    minY = &p;
                else if (p.y > maxY->y)
                    maxY = &p;
            }            
        }
        
        if (maxX->y > minX->y) //    POINTS LAYOUT (rotated left)
        {                      //             Y_MIN
            output[0] = *minX; //  X_MIN     
            output[1] = *minY; //
            output[2] = *maxY; //
            output[3] = *maxX; //               X_MAX
        }                      //    Y_MAX

        else                   //    POINTS LAYOUT (rotated right)
        {                      //     Y_MIN
            output[0] = *minY; //                 X_MAX          
            output[1] = *maxX; //
            output[2] = *minX; //
            output[3] = *maxY; // X_MIN
        }                      //            Y_MAX
    }
}