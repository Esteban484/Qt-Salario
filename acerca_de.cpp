#include "acerca_de.h"
#include "ui_acerca_de.h"

Acerca_De::Acerca_De(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca_De)
{
    ui->setupUi(this);
}

Acerca_De::~Acerca_De()
{
    delete ui;
}
