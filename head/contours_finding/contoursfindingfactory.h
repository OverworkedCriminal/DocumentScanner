#ifndef CONTOURSFINDINGFACTORY_H
#define CONTOURSFINDINGFACTORY_H

#include <DocumentScanner/ContoursFinder.hpp>

#include <memory>
#include <vector>

/**
 * @brief Creates ds::ContoursFinder objects
 */
class ContoursfindingFactory
{
public:
    ContoursfindingFactory();

    std::shared_ptr<ds::ContoursFinder> create(
            const std::vector<double>& args);
};

#endif // CONTOURSFINDINGFACTORY_H
