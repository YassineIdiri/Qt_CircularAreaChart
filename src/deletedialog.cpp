#include "../headers/deletedialog.h"

deleteDialog::deleteDialog(QWidget *parent) : QDialog(parent)
{
    buildInterface();
}

void deleteDialog::buildInterface()
{
    auto mainLayout = new QVBoxLayout{};
    auto layoutItem = new QHBoxLayout{};
    auto layoutButtons = new QHBoxLayout{};

    d_line = new QLineEdit{};

    layoutItem->addWidget(new QLabel{"Enter the line (1 is the first line) :"});
    layoutItem->addSpacing(5);
    layoutItem->addWidget(d_line);


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
    connect(ok, &QPushButton::clicked, this, &deleteDialog::onOk);
}

double deleteDialog::value()
{
    double v = d_line->text().toDouble()-1;
    return v;
}


void deleteDialog::onOk()
{
    accept();
}
