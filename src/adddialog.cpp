#include "../headers/adddialog.h"

addDialog::addDialog(QWidget *parent) : QDialog(parent)
{
    buildInterface();
}

void addDialog::buildInterface()
{
    auto mainLayout = new QVBoxLayout{};
    auto layoutItem = new QHBoxLayout{};
    auto layoutButtons = new QHBoxLayout{};

    d_name = new QLineEdit{};
    d_value = new QLineEdit{};

    layoutItem->addWidget(new QLabel{"Name :"});
    layoutItem->addSpacing(5);
    layoutItem->addWidget(d_name);
    layoutItem->addSpacing(5);
    layoutItem->addWidget(new QLabel{"Value :"});
    layoutItem->addSpacing(5);
    layoutItem->addWidget(d_value);
    layoutItem->addSpacing(5);


    auto ok = new QPushButton{"OK"};
    ok->setDefault(true);
    auto cancel = new QPushButton{"Cancel"};

    layoutButtons->addWidget(ok,0,Qt::AlignCenter);
    layoutButtons->addWidget(cancel,0,Qt::AlignCenter);

    mainLayout->addLayout(layoutItem);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutButtons);
    mainLayout->addStretch();

    setLayout(mainLayout);

    connect(cancel, &QPushButton::clicked, this, &QDialog::reject);
    connect(ok, &QPushButton::clicked, this, &addDialog::onOk);
}
std::string addDialog::name()
{
    QString nom = d_name->text();
    std::string nomString = nom.toStdString();
    return nomString;
}
double addDialog::value()
{
    double val = d_value->text().toDouble();
    return val;
}

void addDialog::onOk()
{
        accept();
}

