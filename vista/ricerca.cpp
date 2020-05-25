#include "ricerca.h"

Ricerca::Ricerca(QListWidget* v, Modello* m, QWidget *parent):QDialog(parent), view(v),
    cerca(new QPushButton("Ricerca personalizzata", this)), scelta(new QComboBox(this)), lista(m)
{
    setWindowTitle(tr("Ricerca personalizzata"));
    setFixedSize(QSize(300,100));

    scelta->addItem("Libro Digitale");
    scelta->addItem("Audiolibro");
    scelta->addItem("Film");
    scelta->addItem("Musica");
    scelta->addItem("Mostra tutto");
    scelta->setMinimumWidth(250);
    cerca->setMinimumWidth(150);
    QVBoxLayout* Layout = new QVBoxLayout(this);
    Layout->addWidget(scelta);
    Layout->addWidget(cerca);
    Layout->setAlignment(Qt::AlignCenter);

    connect(cerca,SIGNAL(clicked()),this,SLOT(ricercaPersonalizzata()));
}

void Ricerca::ricercaPersonalizzata()
{

    for(int i = 0; i < lista->conta(); i++){
         view->item(i)->setHidden(false);
    }

    if (scelta->currentIndex()==0){
        for(int i = 0; i < lista->conta(); i++){
            if(!dynamic_cast<Librodigitale*>((*(lista->getElement(i))))){
                view->item(i)->setHidden(true);
            }
        }
    }
    if (scelta->currentIndex()==1){
        for(int i = 0; i < lista->conta(); i++){
            if(!dynamic_cast<Audiolibro*>((*(lista->getElement(i))))){
                view->item(i)->setHidden(true);
            }
        }
    }
    if (scelta->currentIndex()==2){
        for(int i = 0; i < lista->conta(); i++){
            if(!dynamic_cast<Film*>((*(lista->getElement(i))))){
                view->item(i)->setHidden(true);
            }
        }
    }
    if (scelta->currentIndex()==3){
        for(int i = 0; i < lista->conta(); i++){
            if(!dynamic_cast<Musica*>((*(lista->getElement(i))))){
                view->item(i)->setHidden(true);
            }
        }
    }

    if (scelta->currentIndex()==4){
          //non deve fare nulla
    }
    close();
}

