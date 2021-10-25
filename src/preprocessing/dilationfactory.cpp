#include "../../head/preprocessing/dilationfactory.h"

#include <DocumentScanner/preprocessing/Dilation.hpp>

DilationFactory::DilationFactory()
{

}

std::shared_ptr<ds::IPreprocessingStage> DilationFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 2);
    return std::make_shared<ds::Dilation>(std::max(1.0, args[0]),
                                          std::max(1.0, args[1]));
}
