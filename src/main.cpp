#include "../headers/mainwindow.h"
#include <vector>
#include <string>
#include <iostream>
#include <iostream>
#include "../headers/statisticalvalue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<std::string> names;
    std::vector<double> values;

    names.push_back("Computer Science");
    names.push_back("Mathematics");
    names.push_back("English");
    names.push_back("Science");
    names.push_back("History");
    names.push_back("Geography");
    names.push_back("Physics");

    values.push_back(20);
    values.push_back(14);
    values.push_back(15);
    values.push_back(12);
    values.push_back(7);
    values.push_back(8);
    values.push_back(5);


    statisticalValue v{names,values,20};
    mainWindow w{v};
    w.resize(500, 300);
    w.show();
    return a.exec();
}
