#include "../../head/contours_finding/contoursfindingfactory.h"

ContoursfindingFactory::ContoursfindingFactory()
{

}

std::shared_ptr<ds::ContoursFinder> ContoursfindingFactory::create(const std::vector<double> &args)
{
    assert(args.size() == 2);
    return std::make_shared<ds::ContoursFinder>(args[0], args[1]);
}
