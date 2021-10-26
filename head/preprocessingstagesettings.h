#ifndef PREPROCESSINGSTAGESETTINGS_H
#define PREPROCESSINGSTAGESETTINGS_H

#include <QWidget>
#include <vector>

#include "preprocessing/preprocessingstagefactory.h"

namespace Ui {
class PreprocessingStageSettings;
}

class PreprocessingStageSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PreprocessingStageSettings(QWidget *parent = nullptr);
    ~PreprocessingStageSettings();

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
     * @param factory factory object that creates wanted object
     */
    void add(QString&& name,
             std::vector<QString>&& paramsNames,
             std::vector<double>&& paramsValues,
             std::shared_ptr<PreprocessingStageFactory> factory);

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
     * @param stage newly created preprocessing stage that
     * should replace old one.
     */
    void valuesChanged(std::shared_ptr<ds::IPreprocessingStage> stage);


private:
    Ui::PreprocessingStageSettings *ui;
    std::vector<std::vector<QString>> _paramsNames;
    std::vector<std::vector<double>> _paramsValues;
    std::vector<std::shared_ptr<PreprocessingStageFactory>> _factories;
};

#endif // PREPROCESSINGSTAGESETTINGS_H
