#include "preprocessingstagesettings.h"
#include "ui_preprocessingstagesettings.h"

#include <QLineEdit>
#include "shared_by_stages.h"

PreprocessingStageSettings::PreprocessingStageSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreprocessingStageSettings)
{
    ui->setupUi(this);
    connect(ui->combobox, &QComboBox::currentIndexChanged,
            this, &PreprocessingStageSettings::comboboxIndexChanged);
}

PreprocessingStageSettings::~PreprocessingStageSettings()
{
    delete ui;
}

void PreprocessingStageSettings::setText(const QString &value)
{
    ui->label->setText(value);
}

void PreprocessingStageSettings::add(QString &&name,
                std::vector<QString> &&paramsNames,
                std::vector<double> &&paramsValues,
                std::shared_ptr<PreprocessingStageFactory> factory)
{
    assert(paramsNames.size() == paramsValues.size());
    _paramsNames.emplace_back(paramsNames);
    _paramsValues.emplace_back(paramsValues);
    _factories.emplace_back(factory);
    ui->combobox->addItem(name);
}

void PreprocessingStageSettings::comboboxIndexChanged(int index)
{
    auto& layout{ ui->inputsLayout };
    clearLayout(layout);

    const auto& names{ _paramsNames[index] };
    auto& values{ _paramsValues[index] };

    for (std::size_t i{ 0 }; i < names.size(); ++i)
    {
        layout->addWidget(new QLabel(names[i], this), 0, i);

        auto lineEdit{ new QLineEdit(QString::number(values[i]), this) };
        layout->addWidget(lineEdit, 1, i);

        connect(lineEdit, &QLineEdit::textChanged, this,
            [addr=&values[i], index, this](const auto& v) {
                updateValue(addr, v);
                emit valuesChanged(_factories[index]->create(_paramsValues[index]));
            });
    }
    emit valuesChanged(_factories[index]->create(values));
}
