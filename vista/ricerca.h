#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>
#include <QComboBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>

#include "modello/modello.h"
#include "modello/libro.h"
#include "modello/film.h"
#include "modello/musica.h"

class Ricerca: public QDialog
{
    Q_OBJECT

private:
    QListWidget* view;

    QPushButton* cerca;
    QComboBox* scelta;
    Modello* lista;
public:
    Ricerca(QListWidget*, Modello*, QWidget *parent = nullptr);

public slots:
    void ricercaPersonalizzata();
};

#endif // RICERCA_H
