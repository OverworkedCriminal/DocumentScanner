#include "../../head/preprocessing/cannyfactory.h"

#include <DocumentScanner/preprocessing/Canny.hpp>
#include <algorithm>

CannyFactory::CannyFactory()
{

}

std::shared_ptr<ds::IPreprocessingStage> CannyFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 2);
    return std::make_shared<ds::Canny>(
        std::clamp(args[0], 0.0, 255.0),
        std::clamp(args[1], 0.0, 255.0)
    );
}
