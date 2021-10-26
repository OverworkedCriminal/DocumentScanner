#include "../../head/corners_finding/minmaxxyfactory.h"

#include <DocumentScanner/corners_finding/MinMaxXY.hpp>

MinMaxXYFactory::MinMaxXYFactory()
{

}

std::shared_ptr<ds::ICornersFinder> MinMaxXYFactory::create(
        const std::vector<double> &args)
{
    assert(args.size() == 0);
    return std::make_shared<ds::MinMaxXY>();
}
