#ifndef STATISTICALVALUE_H
#define STATISTICALVALUE_H
#include <vector>
#include <string>

class statisticalValue
{
public:
    statisticalValue(const std::vector<std::string>& names ,const std::vector<double>& values, double max);
    double nbValues() const;
    double greateValue()const;
    double value(double i) const;
    std::string nameValue(double i) const;
    void changeValue(double i, double value);
    double maxValue()const;
    void modifyMax(double m);
    void addValue(std::string name, double value);
    void deleteValue(double i);

    std::vector<std::string> listNames;
    std::vector<double> listValues;
    double d_maxValue;
};

#endif // STATISTICALVALUE_H


