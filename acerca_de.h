#ifndef ACERCA_DE_H
#define ACERCA_DE_H

#include <QDialog>

namespace Ui {
class Acerca_De;
}

class Acerca_De : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca_De(QWidget *parent = nullptr);
    ~Acerca_De();

private:
    Ui::Acerca_De *ui;
};

#endif // ACERCA_DE_H
