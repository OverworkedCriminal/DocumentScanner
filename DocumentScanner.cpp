#include "DocumentScanner/DocumentScanner.hpp"

#include <cassert>

namespace ds
{
    DocumentScanner::DocumentScanner(
        const std::shared_ptr<ContoursFinder>& contoursFinder)
    {
        assert(contoursFinder != nullptr);
        _contoursFinder = contoursFinder;
    }

    
    void DocumentScanner::scan(const cv::Mat& input, cv::Mat& output)
    {
        _buffers[0] = input;
        for (std::size_t i{ 0 }; i < _processingStages.size(); ++i)
            _processingStages[i].process(_buffers[i], _buffers[i + 1]);

        // tmp
        _buffers.back().copyTo(output);
        // tmp END
    }
}
