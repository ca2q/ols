#include "deleg.h"

QWidget* deleg::createEditor(QWidget *parent,
                      const QStyleOptionViewItem &option,
                      const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);                            // delegate lets us set validator
        QDoubleValidator *validator = new QDoubleValidator(lineEdit);           // but in the end validator passes , character
        lineEdit->setValidator(validator);                                      // we need only . characket in our input digits
        return lineEdit;                                                        // so additional check is required
    }                                                                           // could just remove this at all but decided to leave coz its something new for me
