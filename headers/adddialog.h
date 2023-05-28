#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>


class addDialog : public QDialog
{
    Q_OBJECT
public:
    explicit addDialog(QWidget *parent = nullptr);
    void buildInterface();
    std::string name();
    double value();

private slots:
    void onOk();

private:
    QLineEdit *d_name;
    QLineEdit *d_value;
};

#endif // ADDDIALOG_H
