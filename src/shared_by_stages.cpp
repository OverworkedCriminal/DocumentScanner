#include "shared_by_stages.h"

#include <QWidget>

const int STAGE_ARG_INPUT_WIDTH{ 40 };

void clearLayout(QLayout* layout)
{
    QLayoutItem* child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        delete child->widget();
        delete child;
    }
}

void updateValue(double* oldValueAddr, const QString& value)
{
    bool ok;
    double v{ value.toDouble(&ok) };
    if (ok)
        *oldValueAddr = v;
}
