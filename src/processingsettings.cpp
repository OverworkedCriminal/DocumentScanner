#include "processingsettings.h"
#include "ui_processingsettings.h"

#include <QLineEdit>

static void clearLayout(QLayout* layout)
{
    QLayoutItem* child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        delete child->widget();
        delete child;
    }
}

ProcessingSettings::ProcessingSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessingSettings)
{
    ui->setupUi(this);
    connect(ui->combobox, &QComboBox::currentIndexChanged,
            this, &ProcessingSettings::comboboxIndexChanged);
}

ProcessingSettings::~ProcessingSettings()
{
    delete ui;
}

void ProcessingSettings::setText(const QString &value)
{
    ui->label->setText(value);
}

void ProcessingSettings::add(QString &&name,
                             std::vector<QString> &&paramsNames,
                             std::vector<double> &&paramsValues)
{
    assert(paramsNames.size() == paramsValues.size());
    _paramsNames.emplace_back(paramsNames);
    _paramsValues.emplace_back(paramsValues);
    ui->combobox->addItem(name);
}

void ProcessingSettings::comboboxIndexChanged(int index)
{
    auto& layout{ ui->inputsLayout };
    clearLayout(layout);

    auto& names{ _paramsNames[index] };
    auto& values{ _paramsValues[index] };

    for (std::size_t i{ 0 }; i < names.size(); ++i)
    {
        layout->addWidget(new QLabel(names[i], this), 0, i);

        auto lineEdit{ new QLineEdit(QString::number(values[i]), this) };
        layout->addWidget(lineEdit, 1, i);

        connect(lineEdit, &QLineEdit::textChanged,
            this,
            [&values, i, this](auto v) { this->inputChanged(&values[i], v); });
    }
    emit valuesChanged(index, _paramsValues[index]);
}

void ProcessingSettings::inputChanged(double* oldValue, const QString& value)
{
    bool ok;
    double v{ value.toDouble(&ok) };
    if (ok)
    {
        *oldValue = v;
        int index{ ui->combobox->currentIndex() };
        emit valuesChanged(index, _paramsValues[index]);
    }
}
