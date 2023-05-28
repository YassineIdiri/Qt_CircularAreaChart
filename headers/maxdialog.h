#ifndef MAXDIALOG_H
#define MAXDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>


class maxDialog : public QDialog
{
    Q_OBJECT
public:
    explicit maxDialog(QWidget *parent = nullptr);
    void buildInterface();
    double maxValue();

private slots:
    void onOk();

private:
    QLineEdit *d_max;


};

#endif // MAXDIALOG_H
