#ifndef CANNYFACTORY_H
#define CANNYFACTORY_H

#include <preprocessing/preprocessingstagefactory.h>

/**
 * @brief Creates ds::Canny preprocessing stage object
 */
class CannyFactory : public PreprocessingStageFactory
{
public:
    CannyFactory();

    std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args) override;
};

#endif // CANNYFACTORY_H
