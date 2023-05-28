#include "../headers/view.h"
#include "../headers/mainwindow.h"
#include "../headers/statisticalvalue.h"
#include "../headers/widgetCircularArea.h"

view::view(mainWindow* w, QObject *parent) : QObject{parent}, d_window{w}
{
}

void view::buildInterface(const statisticalValue& Value)
{
    auto mainBox = new QVBoxLayout{};

    auto boxTitle = new QHBoxLayout{};
    auto title = new QLineEdit{"Enter title"};
    boxTitle->addWidget(title);
    title->setStyleSheet("QLineEdit {"
                         "max-width: 200px;"
                         "margin-left: auto;"
                         "margin-right: auto;"
                         "}");

    auto boxW = new QVBoxLayout{};
    d_chart = new widgetCircularArea{Value};
    boxW-> addWidget(d_chart);

    auto box = new QHBoxLayout{};

    auto leftBox = new QHBoxLayout{};
    d_nameBox = new QVBoxLayout{};
    for (int i{0}; i<Value.nbValues(); ++i)
    {
        auto nameValue = new QLabel{"XXXXXXXXXXXX"};
        nameValue->setText(QString::fromStdString(Value.nameValue(i)));
        d_nameBox->addWidget(nameValue);

        d_labelNames.push_back(nameValue);
    }
    leftBox->addLayout(d_nameBox);

    d_valueBox = new QVBoxLayout{};
    for (int i{0}; i<Value.nbValues(); ++i)
    {
        auto value = new QLabel{"XXXXXXXXXXXX"};
        value->setText(QString::number(Value.value(i))+"/"+QString::number(Value.maxValue()));
        d_valueBox->addWidget(value);

        d_labelValues.push_back(value);
    }
    leftBox->addLayout(d_valueBox);

    box->addLayout(leftBox);
    box->addLayout(boxW);

    mainBox->addLayout(boxTitle);
    mainBox->addLayout(box);

    auto buttonBox = new QHBoxLayout{};

    auto editButton = new QPushButton{"Edit"};
    auto cancelButton = new QPushButton{"Cancel"};

    buttonBox->addWidget(editButton);
    buttonBox->addWidget(cancelButton);

    mainBox->addLayout(buttonBox);

    auto centre = new QWidget{};
    centre->setLayout(mainBox);
    d_window->setCentralWidget(centre);
    d_window->setWindowTitle("Circular area chart");

    connect(editButton, &QPushButton::clicked, this, &view::edit);
    connect(cancelButton, &QPushButton::clicked, this, &view::cancel);
}


void view::displayValues(const statisticalValue& v)
{
    d_chart->editValue(v);

    std::vector<QColor> colors = { QColor(Qt::red),QColor(Qt::blue),QColor(Qt::green),QColor(Qt::cyan),
                                  QColor(Qt::magenta),QColor(Qt::darkCyan),QColor(Qt::darkRed),QColor(Qt::darkMagenta),
                                  QColor(Qt::darkBlue),QColor(Qt::darkGreen),QColor(Qt::black),QColor(Qt::darkYellow)};

    for (unsigned int i{0}; i<d_labelValues.size(); ++i)
    {
        d_labelValues[i]->setStyleSheet("color: " + colors[i].name() + ";");
        d_labelValues[i]->setText(QString::number(v.value(i)) +"/" +QString::number(v.maxValue()));

    }

    for (unsigned int i{0}; i<d_labelNames.size(); ++i)
    {
        d_labelNames[i]->setStyleSheet("color: " + colors[i].name() + ";");
        d_labelNames[i]->setText(QString::fromStdString(v.nameValue(i)));
    }
}

void view::addStat(std::string name, double value)
{
    auto val = new QLabel{"XXXXXXXXXXXX"};
    val->setText(QString::number(value));
    d_valueBox->addWidget(val);

    d_labelValues.push_back(val);

    auto nameValue = new QLabel{"XXXXXXXXXXXX"};
    nameValue->setText(QString::fromStdString(name));
    d_nameBox->addWidget(nameValue);

    d_labelNames.push_back(nameValue);
}

void view::deleteStat(int line)
{
    QLabel* valueLabel = d_labelValues[line];
    QLabel* nameLabel = d_labelNames[line];

    d_valueBox->removeWidget(valueLabel);
    d_nameBox->removeWidget(nameLabel);

    delete valueLabel;
    delete nameLabel;

    d_labelValues.erase(d_labelValues.begin() + line);
    d_labelNames.erase(d_labelNames.begin() + line);
}


void view::menu()
{
    auto New = d_window->menuBar()->addMenu("Manage statistics");
    auto Add = new QAction{"Add value"};
    auto Max = new QAction{"Modify max"};
    auto del = new QAction{"Delete value"};
    New->addAction(Add);
    New->addAction(Max);
    New->addAction(del);

    connect(Add, &QAction::triggered, this, &view::add);
    connect(Max, &QAction::triggered, this, &view::Max);
    connect(del, &QAction::triggered, this, &view::del);
}
