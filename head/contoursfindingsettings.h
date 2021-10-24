#ifndef CONTOURSFINDINGSETTINGS_H
#define CONTOURSFINDINGSETTINGS_H

#include <QWidget>
#include <vector>

namespace Ui {
class ContoursfindingSettings;
}

class ContoursfindingSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ContoursfindingSettings(QWidget *parent = nullptr);
    ~ContoursfindingSettings();

signals:

    /**
     * @brief Signal is emitted whenever combobox value changes
     * @param values current values in QLineEdit
     */
    void valuesChanged(const std::vector<double>& values);

private:
    Ui::ContoursfindingSettings *ui;
    std::vector<double> _values;
};

#endif // CONTOURSFINDINGSETTINGS_H
