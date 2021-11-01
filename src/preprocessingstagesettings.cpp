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
    auto& c{ ui->combobox };
    c->addItem(name);
    c->setItemData(c->count() - 1, Qt::AlignCenter, Qt::TextAlignmentRole);
}

void PreprocessingStageSettings::comboboxIndexChanged(int index)
{
    auto& layout{ ui->inputsLayout };
    clearLayout(layout);

    const auto& names{ _paramsNames[index] };
    auto& values{ _paramsValues[index] };

    for (std::size_t i{ 0 }; i < names.size(); ++i)
    {
        auto label{ new QLabel(names[i], this) };
        auto lineEdit{ new QLineEdit(QString::number(values[i]), this) };
        label->setAlignment(Qt::AlignCenter);

        label->setMinimumWidth(STAGE_ARG_INPUT_WIDTH);
        label->setMaximumWidth(STAGE_ARG_INPUT_WIDTH);
        lineEdit->setMinimumWidth(STAGE_ARG_INPUT_WIDTH);
        lineEdit->setMaximumWidth(STAGE_ARG_INPUT_WIDTH);

        lineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

        layout->addWidget(label, 0, i);
        layout->addWidget(lineEdit, 1, i);

        connect(lineEdit, &QLineEdit::textChanged, this,
            [addr=&values[i], index, this](const auto& v) {
                updateValue(addr, v);
                emit valuesChanged(_factories[index]->create(_paramsValues[index]));
            });
    }
    emit valuesChanged(_factories[index]->create(values));
}
