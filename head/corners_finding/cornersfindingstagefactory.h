#ifndef CORNERSFINDINGSTAGEFACTORY_H
#define CORNERSFINDINGSTAGEFACTORY_H

#include <memory>
#include <vector>
#include <DocumentScanner/corners_finding/ICornersFinder.hpp>

/**
 * @brief Abstract Factory made to construct ICornersFinder
 * objects from vectors
 */
class CornersfindingStageFactory
{
public:

    virtual std::shared_ptr<ds::ICornersFinder> create(
            const std::vector<double>& args) = 0;
};

#endif // CORNERSFINDINGSTAGEFACTORY_H
