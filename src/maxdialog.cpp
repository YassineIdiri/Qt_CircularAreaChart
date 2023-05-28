#include "../headers/maxdialog.h"

maxDialog::maxDialog(QWidget *parent) : QDialog(parent)
{
    buildInterface();
}

void maxDialog::buildInterface()
{
    auto mainLayout = new QVBoxLayout{};
    auto layoutItem = new QHBoxLayout{};
    auto layoutButtons = new QHBoxLayout{};

    d_max = new QLineEdit{};

    layoutItem->addWidget(new QLabel{"Max :"});
    layoutItem->addSpacing(5);
    layoutItem->addWidget(d_max);


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
    connect(ok, &QPushButton::clicked, this, &maxDialog::onOk);
}

double maxDialog::maxValue()
{
    double Max = d_max->text().toDouble();
    return Max;
}


void maxDialog::onOk()
{
    accept();
}
