#include "about.h"

About::About(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("About"));
    setFixedSize(QSize(281,150));
    setMinimumSize(250,100);
    setMaximumSize(800,700);
    QLabel* autore = new QLabel("Autore: Luca Marcon\n"
                                "Matricola: 1070602\n"
                                "Autore: Eduard George Serban\n"
                                "Matricola: 1052741\n"
                                "Progetto di Programmazione ad Oggetti\n"
                                "Corso di Studi: Informatica(UniPd)\n"
                                "Anno Accademico 2019/20\n"
                                );

    QVBoxLayout* main = new QVBoxLayout (this);
    main->addWidget(autore);
    autore->setAlignment(Qt::AlignHCenter);
}
