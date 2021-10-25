#include "../../head/preprocessing/gaussianblurfactory.h"

#include <DocumentScanner/preprocessing/GaussianBlur.hpp>

GaussianblurFactory::GaussianblurFactory()
{

}

std::shared_ptr<ds::IPreprocessingStage> GaussianblurFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 4);
    int ksizeX{ (int)std::max(1.0, args[0]) };
    int ksizeY{ (int)std::max(1.0, args[1]) };

    return std::make_shared<ds::GaussianBlur>(
        cv::Size(ksizeX % 2 == 1 ? ksizeX : ksizeX + 1,
                 ksizeY % 2 == 1 ? ksizeY : ksizeY + 1),
        args[2], args[3]);
}
