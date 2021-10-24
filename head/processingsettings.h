#ifndef PROCESSINGSETTINGS_H
#define PROCESSINGSETTINGS_H

#include <QWidget>
#include <vector>

namespace Ui {
class ProcessingSettings;
}

class ProcessingSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessingSettings(QWidget *parent = nullptr);
    ~ProcessingSettings();

    /**
     * @brief Sets text in QLabel on the left side of the widget
     * @param value value to be set
     */
    void setText(const QString& value);

    /**
     * @brief Adds new value to combobox
     * @param name value to be added
     * @param paramsNames names of parameters used to create
     * processing object (needs to be the same size as paramsValues)
     * @param paramsValues default values used to create
     * processing object (needs to be the same size as paramsNames)
     */
    void add(QString&& name,
             std::vector<QString>&& paramsNames,
             std::vector<double>&& paramsValues);

private slots:

    /**
     * @brief Slot is called whenever combobox value changes
     * @param index index of currently selected value
     */
    void comboboxIndexChanged(int index);

    /**
     * @brief Slot is called whenever value in QLineEdit changes.
     * @param oldValue addres of value to be replaced
     * @param value QString to be cast to double
     */
    void inputChanged(double* oldValue, const QString& value);


signals:

    /**
     * @brief Signal is emitted when:
     * 1. combobox value changed
     * 2. value in QLineEdit changed
     * @param index current index in combobox
     * @param values current values in QLineEdit
     */
    void valuesChanged(int index, const std::vector<double>& values);


private:
    Ui::ProcessingSettings *ui;
    std::vector<std::vector<QString>> _paramsNames;
    std::vector<std::vector<double>> _paramsValues;
};

#endif // PROCESSINGSETTINGS_H
