#ifndef DURATATOTALE_H
#define DURATATOTALE_H

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QString>
#include "modello/modello.h"

class DurataTotale: public QDialog
{
    Q_OBJECT

private:
    Modello* modello;
public:
    explicit DurataTotale(Modello* , QWidget *parent = nullptr);
};

#endif // DURATATOTALE_H
