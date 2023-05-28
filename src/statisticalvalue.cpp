#include "../headers/statisticalvalue.h"

statisticalValue::statisticalValue(const std::vector<std::string>& names,const std::vector<double>& values, double max) : listNames{names} ,listValues{values}, d_maxValue{max}
{

}


double statisticalValue::nbValues() const
{
    return listValues.size();
}
double statisticalValue::value(double i) const
{
    return listValues[i];
}

std::string statisticalValue::nameValue(double i) const
{
    return listNames[i];
}

void statisticalValue::changeValue(double i, double value)
{
    listValues[i] = value;
}

double statisticalValue::maxValue()const
{
    return d_maxValue;
}

void statisticalValue::addValue(std::string name, double value)
{
    listNames.push_back(name);
    listValues.push_back(value);
}

void statisticalValue::modifyMax(double m)
{
    d_maxValue = m;
}

void statisticalValue::deleteValue(double i)
{
    listNames.erase(listNames.begin()+i);
    listValues.erase(listValues.begin()+i);

}

double statisticalValue::greateValue()const
{
    double max =0;
    for(int i=0; i<listValues.size(); i++)
    {
        if(max<listValues[i])
        {
            max= listValues[i];
        }
    }
    return max;
}
