#include "DocumentScanner/corners_finding/SumSubXY.hpp"


namespace ds
{
    void SumSubXY::findCorners(std::vector<std::vector<cv::Point>>& input,
                               std::array<cv::Point2f, 4>& output)
    {
        int sumMin{ input[0][0].x + input[0][0].y };
        int sumMax{ sumMin };
        int subMin{ input[0][0].x - input[0][0].y };
        int subMax{ subMin };

        cv::Point* sumMinP{ &input[0][0] }, *sumMaxP{ &input[0][0] };
        cv::Point* subMinP{ &input[0][0] }, *subMaxP{ &input[0][0] };

        for (auto& vec : input)
        {
            for (auto& p : vec)
            {
                int sum{ p.x + p.y };
                int sub{ p.x - p.y };

                if (sum > sumMax)
                {
                    sumMax = sum;
                    sumMaxP = &p;
                }
                else if (sum < sumMin)
                {
                    sumMin = sum;
                    sumMinP = &p;
                }

                if (sub > subMax)
                {
                    subMax = sub;
                    subMaxP = &p;
                }
                else if (sub < subMin)
                {
                    subMin = sub;
                    subMinP = &p;
                }
            }
        }
        output[0] = *sumMinP;
        output[1] = *subMaxP;
        output[2] = *subMinP;
        output[3] = *sumMaxP;
    }
}