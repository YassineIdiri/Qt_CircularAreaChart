#ifndef VIEW_H
#define VIEW_H

#include <QPainter>
#include <vector>
#include <QString>
#include <string>
#include <QObject>
#include <QtWidgets>
#include <iostream>
class mainWindow;
class widgetCircularArea;
class statisticalValue;

class view : public QObject {
    Q_OBJECT
public:
    explicit view (mainWindow* w, QObject *parent = nullptr);
    void buildInterface(const statisticalValue& Value);
    void displayValues(const statisticalValue& v);
    void menu();
    void addStat(std::string name, double value);
    void deleteStat(int line);
signals:
    void edit();
    void cancel();
    void add();
    void Max();
    void del();
private:
    mainWindow* d_window;
    widgetCircularArea* d_chart;
    QVBoxLayout* d_nameBox;
    QVBoxLayout* d_valueBox;
    std::vector<QLabel*> d_labelValues;
    std::vector<QLabel*> d_labelNames;
};


#endif // VIEW_H
