#ifndef NONEFACTORY_H
#define NONEFACTORY_H

#include <preprocessing/preprocessingstagefactory.h>

/**
 * @brief Creates ds::None preprocessing stage object.
 */
class NoneFactory : public PreprocessingStageFactory
{
public:
    NoneFactory();

    std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args) override;
};

#endif // NONEFACTORY_H
