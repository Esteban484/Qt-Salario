#include "salario.h"

Salario::Salario(QObject *parent) : QObject(parent)
{

    m_horas=0;
    m_nombre="";

}

Salario::Salario(QString nombre, int horas)
{
    m_nombre=nombre;
    m_horas=horas;

}

QString Salario::nombre()
{
    return m_nombre;
}

int Salario::horas()
{
    return m_horas;
}

int Salario::calcularextra()
{

    // Calcular horas extra
    int extra = 0;

    if (m_horas > 40){
        extra = m_horas - 40;
        m_horas= 40;
    }
    return extra;
}



