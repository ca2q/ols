#ifndef DELEG_H
#define DELEG_H
#include <QItemDelegate>
#include <QWidget>
 #include <QLineEdit>

class deleg : public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
};

#endif // DELEG_H
