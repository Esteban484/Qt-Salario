#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "salario.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:
    void calcular();
    void guardar();
    void abrir();
    void ayuda();


private:
    Ui::Principal *ui;
    void limpiar();
};
#endif // PRINCIPAL_H
