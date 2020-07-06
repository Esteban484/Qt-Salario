#include "principal.h"
#include "ui_principal.h"
#include "acerca_de.h"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->cmdCalcular, SIGNAL(released()),
            this, SLOT(calcular()));
    connect(ui->mnuCalcular, SIGNAL(triggered(bool)),
            this, SLOT(calcular()));
    connect(ui->mnuSalir, SIGNAL(triggered(bool)),
            this, SLOT(close()));
    connect(ui->mnuGuardar, SIGNAL(triggered(bool)),
            this, SLOT(guardar()));
    connect(ui->mnuAbrir, SIGNAL(triggered(bool)),
            this, SLOT(abrir()));
    connect(ui->actionAcerca_de, SIGNAL(triggered(bool)),
            this, SLOT(ayuda()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::calcular()
{
    // obtener datos
    Salario p;
    int horas=p.horas();
    QString nombre=p.nombre();
    nombre = ui->inNombre->text();
    horas = ui->inHoras->value();


    if (nombre == "" || horas == 0){
        ui->statusbar->showMessage("No se han ingresado datos para calcular.",5000);
        return;
    }else{
        ui->statusbar->clearMessage();
    }

    float const HORA_EXTRA = 20.10;

    // Calcular horas extra
    int extra = p.calcularextra();


    // Calcular el salario
    float salario = 0;
    if (ui->inMatutina->isChecked()){
        salario = horas * 5.15 + extra * HORA_EXTRA;
    }else if (ui->inVespertina->isChecked()){
        salario = horas * 8.50 + extra * HORA_EXTRA;
    }else{
        salario = horas * 12.65 + extra * HORA_EXTRA;
    }

    // Calcular el descuento
    float descuento = salario * 9.5 / 100;
    float salario_neto = salario - descuento;


    // Imprimir resultados
    QString resultado = "\nObrero: " + nombre + "\n";
    resultado += "Salario: $" + QString::number(salario) + "\n";
    resultado += "Descuento (9.5%): $" + QString::number(descuento) + "\n";
    resultado += "Salario neto: $" + QString::number(salario_neto) + "\n";
    resultado += "--\n";

    ui->outResultado->appendPlainText(resultado);
    limpiar();
}

void Principal::guardar()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar datos", QDir::home().absolutePath(), "Archivo de texto (*.txt)");
    QFile data(fileName);

    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&data);
        salida << ui->outResultado->toPlainText();
        ui->statusbar->showMessage("Datos almacenados en " + fileName,5000);
    }

    data.close();
}

void Principal::abrir()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Guardar datos", QDir::home().absolutePath(), "Archivo de texto (*.txt)");
    QFile data(fileName);

    if (!data.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&data);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        qDebug() << linea;
    }

    data.close();
}

void Principal::ayuda()
{
    Acerca_De ventana;
    ventana.setModal(true);
    ventana.exec();
}



void Principal::limpiar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();

}
