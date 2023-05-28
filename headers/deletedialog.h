#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H


#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>


class deleteDialog : public QDialog
{
    Q_OBJECT
public:
    explicit deleteDialog(QWidget *parent = nullptr);
    void buildInterface();
    double value();

private slots:
    void onOk();

private:
    QLineEdit *d_line;
};

#endif // DELETEDIALOG_H
