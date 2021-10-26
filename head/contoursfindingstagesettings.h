#ifndef CONTOURSFINDINGSTAGESETTINGS_H
#define CONTOURSFINDINGSTAGESETTINGS_H

#include <contours_finding/contoursfindingfactory.h>
#include <QWidget>
#include <vector>

namespace Ui {
class ContoursfindingStageSettings;
}

class ContoursfindingStageSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ContoursfindingStageSettings(QWidget *parent = nullptr);
    ~ContoursfindingStageSettings();

signals:

    /**
     * @brief Signal is emitted whenever combobox value changes
     * @param obj created ds::ContoursFinder object
     */
    void valuesChanged(std::shared_ptr<ds::ContoursFinder> obj);

private:
    Ui::ContoursfindingStageSettings *ui;
    std::vector<double> _values;
    ContoursfindingFactory _factory;
};

#endif // CONTOURSFINDINGSTAGESETTINGS_H
