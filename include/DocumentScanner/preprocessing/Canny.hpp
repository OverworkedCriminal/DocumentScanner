#ifndef EDGE_DETECTOR_CANNY_HPP
#define EDGE_DETECTOR_CANNY_HPP

#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for finding edges on image.
     * It uses Canny algorithm to achieve that goal.
     *
     */
    class Canny final :public IPreprocessingStage
    {
    private:
        double _lowerThreshold;
        double _upperThreshold;
        
    public:

        /**
         * @brief Construct a new Canny Edge Detector object
         * 
         * @param lowerThreshold first threshold for the hysteresis procedure.
         * @param upperThreshold second threshold for the hysteresis procedure.
         */
        Canny(double lowerThreshold, double upperThreshold) noexcept;

        void process(const cv::Mat& input, cv::Mat& output) override;
    };
}


#endif
