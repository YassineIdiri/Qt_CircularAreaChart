#include "../headers/valuedialog.h"

valueDialog::valueDialog(const statisticalValue& Value) :
    QDialog{}
{
    interfaceView(Value);

}


valueDialog::~valueDialog()
{
    for (QDoubleSpinBox* spinBox : d_values) {
        delete spinBox;
    }
}

void valueDialog::editValue(const statisticalValue& Value)
{
    for (int i{0}; i<Value.nbValues(); ++i)
    {
        d_values[i]->setValue(Value.value(i));
    }
}

void valueDialog::editNameValue(const statisticalValue& Value)
{
    for (int i{0}; i<Value.nbValues(); ++i)
    {

        d_names[i]->setText(QString::fromStdString(Value.nameValue(i)));
    }
}
void valueDialog::onErase()
{
    for (unsigned int i=0; i<d_values.size(); ++i)
    {
        d_values[i]->setValue(0);
    }
}

void valueDialog::interfaceView(const statisticalValue& Value)
{
    auto mainBox = new QVBoxLayout{};

    auto box = new QHBoxLayout{};

    auto valueBox = new QVBoxLayout{};
    for (int i{0}; i<Value.nbValues(); ++i)
    {
        auto valeurNote = new QDoubleSpinBox{};
        valeurNote->setRange(0.0, Value.maxValue());
        d_values.push_back(valeurNote);
        valueBox->addWidget(valeurNote);
    }

    auto nameBox = new QVBoxLayout{};
    for (int i{0}; i<Value.nbValues(); ++i)
    {
        auto nameValue = new QLineEdit{"XXXXXXXXXXXX"};
        d_names.push_back(nameValue);
        nameBox->addWidget(nameValue);
    }

    box->addLayout(nameBox);
    box->addLayout(valueBox);

    auto boutonOK = new QPushButton{"OK"};
    boutonOK->setDefault(true);
    connect(boutonOK, &QPushButton::clicked, this, &QDialog::accept);
    auto boutonEffacer = new QPushButton{"Erase"};
    connect(boutonEffacer, &QPushButton::clicked, this, &valueDialog::onErase);
    auto boutonAnnuler = new QPushButton{"Cancel"};
    connect(boutonAnnuler, &QPushButton::clicked, this, &QDialog::reject);

    auto buttonBox = new QHBoxLayout{};
    buttonBox->addWidget(boutonOK);
    buttonBox->addWidget(boutonEffacer);
    buttonBox->addWidget(boutonAnnuler);

    mainBox->addLayout(box);
    mainBox->addLayout(buttonBox);

    setLayout(mainBox);
}

statisticalValue valueDialog::values(const statisticalValue& s) const
{
        std::vector<std::string> names;
        std::vector<double> values;

        for (const QLineEdit* lineEdit : d_names)
        {
          names.push_back(lineEdit->text().toStdString());
        }

        for (const QDoubleSpinBox* spinBox : d_values)
        {
            values.push_back(spinBox->value());
        }

        double Max = s.maxValue();
        statisticalValue v{names,values,Max};
        return v;
}

