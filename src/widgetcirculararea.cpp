#include "../headers/widgetcirculararea.h"

widgetCircularArea::widgetCircularArea(const statisticalValue& value,QWidget *parent) : QWidget{parent}, d_statisticalValues{value}
{

}

std::vector<QPoint> widgetCircularArea::maxPointsValue(const QPoint& center, int rayon)
{
    std::vector<QPoint> points;
    double angle = 2 * M_PI / d_statisticalValues.nbValues();

    for (int i = 0; i < d_statisticalValues.nbValues(); ++i) {
        int x = center.x() + rayon * std::cos(angle * i);
        int y = center.y() + rayon * std::sin(angle * i);
        points.push_back(QPoint(x, y));
    }

    return points;
}

std::vector<QPoint> widgetCircularArea::pointsValue(const QPoint& center, int rayon)
{
    std::vector<QPoint> points;
    double angle = 2 * M_PI / d_statisticalValues.nbValues();

    for (int i = 0; i < d_statisticalValues.nbValues(); ++i) {
        double proportion = static_cast<double>(d_statisticalValues.value(i)) / d_statisticalValues.maxValue();
        int distance = static_cast<int>(rayon * proportion);

        int x = center.x() + distance * std::cos(angle * i);
        int y = center.y() + distance * std::sin(angle * i);
        points.push_back(QPoint(x, y));
    }

    return points;
}

void widgetCircularArea::draw(QPainter& paint, const QPoint& center,const std::vector<QPoint>& pointValue)
{
    QPen pen{Qt::SolidLine};
    for (const auto& p : pointValue)
    {
        pen.setColor(Qt::gray);
        paint.setPen(pen);
        paint.drawLine(center, p);
    }
    for (unsigned int i {0}; i<pointValue.size()-1; ++i)
    {
        pen.setColor(Qt::gray);
        paint.setPen(pen);
        paint.drawLine(pointValue[i], pointValue[i+1]);
    }
    pen.setColor(Qt::gray);
    paint.setPen(pen);
    paint.drawLine(pointValue[0], pointValue.back());
}

void widgetCircularArea::drawStat(QPainter& paint, const QPoint& center, const std::vector<QPoint>& pointValue, const std::vector<QColor>& colors)
{
    QPen pen{Qt::SolidLine};

    for (unsigned int i = 0; i < pointValue.size(); ++i)
    {
        pen.setColor(colors[i % colors.size()]);
        paint.setPen(pen);
        paint.drawLine(center, pointValue[i]);
    }

    for (unsigned int i = 0; i < pointValue.size() - 1; ++i)
    {
        pen.setColor(Qt::gray);
        paint.setPen(pen);
        paint.drawLine(pointValue[i], pointValue[i + 1]);
    }

    pen.setColor(Qt::gray);
    paint.setPen(pen);
    paint.drawLine(pointValue[0], pointValue.back());
}

void widgetCircularArea::paintEvent(QPaintEvent *)
{
    int width = 200;
    int height = 200;
    QPainter paint{this};
    QPoint center{width / 2, height / 2};
    int rayon = (width > height) ? height : width;
    rayon = rayon / 2;
    paint.eraseRect(0, 0, width, height);

    QPen pen{Qt::SolidLine};
    pen.setWidth(1);
    paint.setPen(pen);

    draw(paint, center, maxPointsValue(center, rayon));

    std::vector<QColor> colors = { QColor(Qt::red),QColor(Qt::blue),QColor(Qt::green),QColor(Qt::cyan),
                                  QColor(Qt::magenta),QColor(Qt::darkCyan),QColor(Qt::darkRed),QColor(Qt::darkMagenta),
                                  QColor(Qt::darkBlue),QColor(Qt::darkGreen),QColor(Qt::black),QColor(Qt::darkYellow)};

    const std::vector<QPoint>& pointValue = pointsValue(center, rayon);

    drawStat(paint, center, pointValue, colors);
}
void widgetCircularArea::editValue(const statisticalValue& value)
{
    d_statisticalValues = value;
    update();
}
