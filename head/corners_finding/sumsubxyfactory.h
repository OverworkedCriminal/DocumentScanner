#ifndef SUMSUBXYFACTORY_H
#define SUMSUBXYFACTORY_H

#include "corners_finding/cornersfindingstagefactory.h"

/**
 * @brief Creates ds::SumSubXY corners finding objects
 */
class SumSubXYFactory :public CornersfindingStageFactory
{
public:
    SumSubXYFactory();

    std::shared_ptr<ds::ICornersFinder> create(
            const std::vector<double> &args) override;
};

#endif // SUMSUBXYFACTORY_H
