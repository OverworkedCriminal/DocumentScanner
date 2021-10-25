#ifndef DILATIONFACTORY_H
#define DILATIONFACTORY_H

#include <preprocessing/preprocessingstagefactory.h>

/**
 * @brief Creates ds::Dilation preprocessing stage object
 */
class DilationFactory : public PreprocessingStageFactory
{
public:
    DilationFactory();

    std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args) override;
};

#endif // DILATIONFACTORY_H
