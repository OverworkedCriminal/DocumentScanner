#include "contoursfindingstagesettings.h"
#include "ui_contoursfindingstagesettings.h"

#include <opencv2/imgproc.hpp>

ContoursfindingStageSettings::ContoursfindingStageSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContoursfindingStageSettings)
{
    ui->setupUi(this);
    _values.resize(2);
    _values[0] = 0;
    _values[1] = 1;

    auto& modes{ ui->modeCombobox };
    modes->addItem("EXTERNAL");  // 0
    modes->addItem("LIST");      // 1
    modes->addItem("CCOMP");     // 2
    modes->addItem("TREE");      // 3

    // (does not work with 8 bit 1C images)
    // modes->addItem("FLOODFILL"); // 4

    for (int i{ 0 }; i < modes->count(); ++i)
        modes->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);

    auto& methods{ ui->methodCombobox };
    methods->addItem("NONE");      // 1
    methods->addItem("SIMPLE");    // 2
    methods->addItem("TC89 L1");   // 3
    methods->addItem("TC89 KCOS"); // 4

    for (int i{ 0 }; i < methods->count(); ++i)
        methods->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);

    connect(modes, &QComboBox::currentIndexChanged,
        this, [this](int index) {
            this->_values[0] = index;
            emit this->valuesChanged(_factory.create(_values));
        });
    connect(methods, &QComboBox::currentIndexChanged,
        this, [this](int index) {
            this->_values[1] = index + 1;
            emit this->valuesChanged(_factory.create(_values));
        });
}

ContoursfindingStageSettings::~ContoursfindingStageSettings()
{
    delete ui;
}
