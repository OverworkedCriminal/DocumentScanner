#ifndef THRESHOLDFACTORY_H
#define THRESHOLDFACTORY_H

#include <preprocessing/preprocessingstagefactory.h>

/**
 * @brief Creates ds::Threshold preprocessing stage object
 */
class ThresholdFactory : public PreprocessingStageFactory
{
public:
    ThresholdFactory();

    std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args);
};

#endif // THRESHOLDFACTORY_H
