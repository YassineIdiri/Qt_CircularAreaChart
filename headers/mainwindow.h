#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../headers/statisticalvalue.h"
#include "../headers/view.h"
#include "../headers/valuedialog.h"
#include <vector>


class mainWindow : public QMainWindow
{
    Q_OBJECT

    public:

    mainWindow(const statisticalValue& s, QWidget *parent = nullptr);
    ~mainWindow();

    statisticalValue d_values;
    view d_view;

    private slots:

    void onEdit();
    void onAdd();
    void onMax();
    void onDelete();
    void onCancel();

};

#endif // MAINWINDOW_H
