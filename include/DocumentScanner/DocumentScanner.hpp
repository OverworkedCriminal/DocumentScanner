#ifndef DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP
#define DOCUMENTSCANNER_DOCUMENT_SCANNER_HPP

#include <opencv2/core/mat.hpp>

namespace ds
{
    /**
     * @brief Class responsible for scanning documents
     * 
     */
    class DocumentScanner
    {
        
    private:

    public:

        /**
         * @brief Find document in input image and write it's warped
         * perspective into output image.
         *
         * @param input 
         * @param output 
         */
        void scan(const cv::Mat& input, cv::Mat& output);
    };    
}


#endif