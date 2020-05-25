#include "duratatotale.h"
#include "modello/modello.h"


DurataTotale::DurataTotale(Modello*m,QWidget *parent) : QDialog(parent), modello(m)
{
    setWindowTitle(tr("Quantifica i tuoi media"));
    setFixedSize(QSize(500,150));
    QLabel* txt1 = new QLabel("Il tuo intrattenimento totale, calcolato in minuti, equivale a:\n");
    QLabel* txt2 = new QLabel(QString::number(modello->durataTotale()).append(" minuti\n"));
    QLabel* txt3 = new QLabel("ottenuto sommando la durata di tutti i film, di tutti i file audio\ne considerando 3 minuti per la lettura della pagina di un libro digitale\n");
    QVBoxLayout* main = new QVBoxLayout (this);
    main->addWidget(txt1);
    main->addWidget(txt2);
    main->addWidget(txt3);
    txt1->setAlignment(Qt::AlignHCenter);
    txt2->setAlignment(Qt::AlignHCenter);
    txt3->setAlignment(Qt::AlignHCenter);
}
