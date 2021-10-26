#ifndef SHARED_BY_STAGES_H
#define SHARED_BY_STAGES_H

#include <QLayout>

/**
 * @brief Removes each element from layout and frees memory
 * @param layout layout to be cleared
 */
void clearLayout(QLayout* layout);


/**
 * @brief Updates double value from given address with
 * value stored by QString.
 * If conversion fails old value is preserved.
 * @param oldValueAddr
 * @param value QString containing double value
 */
void updateValue(double* oldValueAddr, const QString& value);

#endif // SHARED_BY_STAGES_H
