#include "../../head/preprocessing/thresholdfactory.h"

#include <DocumentScanner/preprocessing/Threshold.hpp>
#include <algorithm>

ThresholdFactory::ThresholdFactory()
{

}

std::shared_ptr<ds::IPreprocessingStage> ThresholdFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 1);
    return std::make_shared<ds::Threshold>(
                std::clamp(args[0], 0.0, 255.0));
}
