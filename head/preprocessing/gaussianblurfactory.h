#ifndef GAUSSIANBLURFACTORY_H
#define GAUSSIANBLURFACTORY_H

#include <preprocessing/preprocessingstagefactory.h>

/**
 * @brief Creates ds::GaussianBlur preprocessing stage object
 */
class GaussianblurFactory : public PreprocessingStageFactory
{
public:
    GaussianblurFactory();

    std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args) override;
};

#endif // GAUSSIANBLURFACTORY_H
