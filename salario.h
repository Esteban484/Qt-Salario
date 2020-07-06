#ifndef SALARIO_H
#define SALARIO_H

#include <QObject>

class Salario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre )
    Q_PROPERTY(int horas READ horas )

public:
    explicit Salario(QObject *parent = nullptr);
    Salario(QString nombre, int horas);
    //Getters
    QString nombre() ;
    int horas() ;
    //Metodo para realizar calculo
    int calcularextra( );
signals:

private:
    QString m_nombre;
    int m_horas;



};

#endif // SALARIO_H
