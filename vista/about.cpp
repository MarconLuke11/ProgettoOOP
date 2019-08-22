#include "about.h"

About::About(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("About"));
    QLabel* autore = new QLabel("Progetto di Programmazione ad Oggetti\n"
                                "Corso di Studi: Informatica(UniPd)\n"
                                "Anno Accademico 2018/19\n"
                                "Autore: Luca Marcon\n"
                                "Matricola: 1070602");

    QVBoxLayout* main = new QVBoxLayout (this);
    main->addWidget(autore);
    autore->setAlignment(Qt::AlignHCenter);
}
