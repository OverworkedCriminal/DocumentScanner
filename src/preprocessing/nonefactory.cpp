#include "../../head/preprocessing/nonefactory.h"

#include <DocumentScanner/preprocessing/None.hpp>

NoneFactory::NoneFactory()
{

}

std::shared_ptr<ds::IPreprocessingStage> NoneFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 0);
    return std::make_shared<ds::None>();
}
