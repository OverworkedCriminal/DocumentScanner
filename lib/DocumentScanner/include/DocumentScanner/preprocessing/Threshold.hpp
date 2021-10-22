#ifndef DOCUMENTSCANNER_PREPROCESSING_THRESHOLD_HPP
#define DOCUMENTSCANNER_PREPROCESSING_THRESHOLD_HPP

#include <opencv2/imgproc.hpp>
#include "DocumentScanner/preprocessing/IPreprocessingStage.hpp"

namespace ds
{
    /**
     * @brief Class is responsible for applying threshold od image
     *
     */
    class Threshold final :public IPreprocessingStage
    {
    private:
        double _threshold;
        double _maxval;
        int _type;

    public:

        /**
         * @brief 
         * 
         * @param threshold threshold value
         * @param maxval maximum value to use with the THRESH_BINARY
         * and THRESH_BINARY_INV thresholding types
         * @param type thresholding type
         * https://docs.opencv.org/4.5.3/d7/d1b/group__imgproc__misc.html#gaa9e58d2860d4afa658ef70a9b1115576
         * 
         */
        Threshold(double threshold, double maxval = 255.0, int type = cv::THRESH_BINARY) noexcept;

        void process(const cv::Mat& input, cv::Mat& output) override;
    };
}

#endif