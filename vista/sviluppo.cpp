#include "sviluppo.h"

Sviluppo::Sviluppo(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Development info"));
    QLabel* sviluppo = new QLabel("Sviluppato con:\n"
                                "Sistema operativo: Windows 10\n"
                                "Versione Libreria Qt: 5.9.5\n"
                                "Versione compilatore: MinGW 5.3.0 32bit\n"
                                "Versione Qt Creator: 4.10.2 (Community)");

    QVBoxLayout* main = new QVBoxLayout (this);
    QLabel* foto = new QLabel("");
    foto->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/Qt.png")));
    main->addWidget(foto);
    main->addWidget(sviluppo);
    foto->setAlignment(Qt::AlignHCenter);
    sviluppo->setAlignment(Qt::AlignHCenter);
}
