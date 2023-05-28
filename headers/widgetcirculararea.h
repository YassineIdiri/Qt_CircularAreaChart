#ifndef WIDGETCIRCULARAREA_H
#define WIDGETCIRCULARAREA_H
#include <QWidget>
#include <QPoint>
#include <cmath>
#include <vector>
#include <QPainter>
#include <vector>

#include <iostream>
#include "../headers/statisticalvalue.h"



class widgetCircularArea : public QWidget
{
    Q_OBJECT
    public:

    widgetCircularArea(const statisticalValue& value, QWidget *parent = nullptr);
    void editValue(const statisticalValue& value);

    private:

    statisticalValue d_statisticalValues;

    void paintEvent(QPaintEvent* ) override;
    std::vector<QPoint> pointsValue(const QPoint& center, int rayon);
    std::vector<QPoint> maxPointsValue(const QPoint& center, int rayon);
    void draw(QPainter& paint, const QPoint& center,const std::vector<QPoint>& pointValue);
    void drawStat(QPainter& paint, const QPoint& center, const std::vector<QPoint>& pointValue, const std::vector<QColor>& colors);
};

#endif // WIDGETCIRCULARAREA_H
