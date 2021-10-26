#ifndef CORNERSFINDINGSTAGESETTINGS_H
#define CORNERSFINDINGSTAGESETTINGS_H

#include <QWidget>
#include "corners_finding/cornersfindingstagefactory.h"

#include <vector>
#include <memory>

namespace Ui {
class CornersfindingStageSettings;
}

class CornersfindingStageSettings : public QWidget
{
    Q_OBJECT

public:
    explicit CornersfindingStageSettings(QWidget *parent = nullptr);
    ~CornersfindingStageSettings();

    /**
     * @brief Adds new value to combobox
     * @param name value to be added
     * @param paramsNames names of parameters used to create
     * processing object (needs to be the same size as paramsValues)
     * @param paramsValues default values used to create
     * processing object (needs to be the same size as paramsNames)
     * @param factory factory object that creates wanted object
     */
    void add(QString&& name,
             std::vector<QString>&& paramsNames,
             std::vector<double>&& paramsValues,
             std::shared_ptr<CornersfindingStageFactory> factory);

private slots:

    /**
     * @brief Slot is called whenever combobox value changes
     * @param index index of currently selected value
     */
    void comboboxIndexChanged(int index);

signals:

    /**
     * @brief Signal is emitted when:
     * 1. combobox value changed
     * 2. value in QLineEdit changed
     * @param obj newly created CornerFinder that
     * should replace old one.
     */
    void valuesChanged(std::shared_ptr<ds::ICornersFinder> obj);

private:
    Ui::CornersfindingStageSettings *ui;
    std::vector<std::vector<QString>> _paramsNames;
    std::vector<std::vector<double>> _paramsValues;
    std::vector<std::shared_ptr<CornersfindingStageFactory>> _factories;
};

#endif // CORNERSFINDINGSTAGESETTINGS_H
