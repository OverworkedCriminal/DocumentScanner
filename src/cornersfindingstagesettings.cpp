#include "cornersfindingstagesettings.h"
#include "ui_cornersfindingstagesettings.h"

#include "shared_by_stages.h"
#include <QLineEdit>

CornersfindingStageSettings::CornersfindingStageSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CornersfindingStageSettings)
{
    ui->setupUi(this);
    connect(ui->combobox, &QComboBox::currentIndexChanged,
            this, &CornersfindingStageSettings::comboboxIndexChanged);
}

CornersfindingStageSettings::~CornersfindingStageSettings()
{
    delete ui;
}

void CornersfindingStageSettings::add(QString &&name, std::vector<QString> &&paramsNames, std::vector<double> &&paramsValues, std::shared_ptr<CornersfindingStageFactory> factory)
{
    assert(paramsNames.size() == paramsValues.size());
    _paramsNames.emplace_back(paramsNames);
    _paramsValues.emplace_back(paramsValues);
    _factories.emplace_back(factory);
    ui->combobox->addItem(name);
}

void CornersfindingStageSettings::comboboxIndexChanged(int index)
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
                emit valuesChanged(_factories[index]->create(this->_paramsValues[index]));
            });
    }
    emit valuesChanged(_factories[index]->create(values));
}
