#include "../../head/corners_finding/sumsubxyfactory.h"

#include <DocumentScanner/corners_finding/SumSubXY.hpp>

SumSubXYFactory::SumSubXYFactory()
{

}

std::shared_ptr<ds::ICornersFinder> SumSubXYFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 0);
    return std::make_shared<ds::SumSubXY>();
}
