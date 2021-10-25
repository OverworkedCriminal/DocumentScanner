#ifndef PREPROCESSINGSTAGEFACTORY_H
#define PREPROCESSINGSTAGEFACTORY_H

#include <DocumentScanner/preprocessing/IPreprocessingStage.hpp>
#include <memory>
#include <vector>

/**
 * @brief Abstract Factory made to conctruct IPreprocessingStage
 * objects from vectors
 */
class PreprocessingStageFactory
{
public:
    virtual ~PreprocessingStageFactory() { }

    virtual std::shared_ptr<ds::IPreprocessingStage> create(
            const std::vector<double>& args) = 0;
};

#endif // PREPROCESSINGSTAGEFACTORY_H
