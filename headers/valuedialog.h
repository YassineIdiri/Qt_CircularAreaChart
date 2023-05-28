#ifndef VALUEDIALOG_H
#define VALUEDIALOG_H

#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

#include "statisticalvalue.h"

class valueDialog: public QDialog
{
    Q_OBJECT
public:
    valueDialog(const statisticalValue& s);
    ~valueDialog();
    statisticalValue values(const statisticalValue& s) const;
    void editValue(const statisticalValue& Value);
    void editNameValue(const statisticalValue& Value);
private:
    std::vector<QDoubleSpinBox*> d_values;
    std::vector<QLineEdit*> d_names;
    void interfaceView(const statisticalValue& s);
private slots:
    void onErase();
};

#endif // VALUEDIALOG_H

