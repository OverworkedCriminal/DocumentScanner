#ifndef MINMAXXYFACTORY_H
#define MINMAXXYFACTORY_H

#include <corners_finding/cornersfindingstagefactory.h>

/**
 * @brief Creates ds::MinMaxXY corners finding objects
 */
class MinMaxXYFactory : public CornersfindingStageFactory
{
public:
    MinMaxXYFactory();

    std::shared_ptr<ds::ICornersFinder> create(
            const std::vector<double> &args) override;
};

#endif // MINMAXXYFACTORY_H
