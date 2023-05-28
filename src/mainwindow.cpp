#include "../headers/mainwindow.h"
#include "../headers/adddialog.h"
#include "../headers/maxdialog.h"
#include "../headers/deletedialog.h"

mainWindow::mainWindow(const statisticalValue& s, QWidget *parent)
    : QMainWindow(parent),
    d_values{s},
    d_view{this}
{
    d_view.buildInterface(d_values);
    d_view.menu();
    d_view.displayValues(d_values);
    connect(&d_view, &view::edit, this, &mainWindow::onEdit);
    connect(&d_view, &view::add, this, &mainWindow::onAdd);
    connect(&d_view, &view::Max, this, &mainWindow::onMax);
    connect(&d_view, &view::del, this, &mainWindow::onDelete);
    connect(&d_view, &view::cancel, this, &mainWindow::onCancel);
}

mainWindow::~mainWindow()
{
}

void mainWindow::onEdit()
{
    valueDialog dialog {d_values};
    dialog.editValue(d_values);
    dialog.editNameValue(d_values);
    if (dialog.exec() == QDialog::Accepted)
    {
        d_values = dialog.values(d_values);
        d_view.displayValues(d_values);
    }
}

void mainWindow::onAdd()
{
    addDialog d{};
    int r = d.exec();
    if (r == QDialog::Accepted)
    {
        double value = d.value();
        std::string name = d.name();
        if(d.value()<=d_values.maxValue())
        {
            d_values.addValue(name,value);
            d_view.addStat(name,value);
            d_view.displayValues(d_values);
        }
        else
        {
            QMessageBox erreur{QMessageBox::NoIcon,"Error", "Value greater than max", QMessageBox::Ok};
            erreur.exec();
        }
    }
}

void mainWindow::onMax()
{
    maxDialog d{};
    int r = d.exec();
    if (r == QDialog::Accepted)
    {
        double Max = d.maxValue();
        if(d_values.greateValue()<=Max)
        {
            d_values.modifyMax(Max);
            d_view.displayValues(d_values);
        }
        else
        {
            QMessageBox erreur{QMessageBox::NoIcon,"Error", "Some values are greater than the entered max", QMessageBox::Ok};
            erreur.exec();
        }
    }
}

void mainWindow::onDelete()
{
    deleteDialog d{};
    int r = d.exec();
    if (r == QDialog::Accepted)
    {
        double v = d.value();
        if(v <= d_values.nbValues()-1 && v>=0)
        {
            d_values.deleteValue(v);
            d_view.deleteStat(v);
            d_view.displayValues(d_values);
        }
        else
        {
            QMessageBox erreur{QMessageBox::NoIcon,"Error", "Incorrect value", QMessageBox::Ok};
            erreur.exec();
        }
    }
}

void mainWindow::onCancel()
{
    close();
}
