#include "modifica.h"
#include "mainwindow.h"
#include "modello/modello.h"
#include "modello/mediaitem.h"
#include "modello/libro.h"
#include "modello/film.h"
#include "modello/musica.h"


#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QString>
#include <QMessageBox>

Modifica::Modifica(Modello *m, int i, QListWidget* v, QWidget *parent) : QDialog(parent), modello(m),index(i),vista(v),
    titoloL (new QLabel ("Titolo*: ",this)), genereL (new QLabel ("Genere: ",this)),
    annoDistribuzioneL (new QLabel (QString::fromUtf8("Anno di distribuzione: "),this)), formatoL (new QLabel ("Formato: ",this)),
    recensioneL (new QLabel ("Recensione: ",this)), autoreLDL (new QLabel ("Autore: ",this)),
    casaEditriceLDL (new QLabel ("Casa editrice: ",this)), numeroPagineL(new QLabel("Numero di pagine: ", this)), autoreALL (new QLabel ("Autore: ",this)),
    casaEditriceALL (new QLabel ("Casa editrice: ",this)), durataALL(new QLabel("Durata audiolibro (minuti): ", this)),
    narratoreL(new QLabel("Narratore: ", this)), registaL(new QLabel("Regista: ", this)), durataFilmL(new QLabel("Durata del film (minuti): ", this)),
    artistaL(new QLabel("Artista: ", this)), numeroTracceL(new QLabel("Numero di tracce: ", this)),
    durataMusicaL(new QLabel("Durata musica (minuti): ", this)),
    titolo (new QLineEdit (this)),genere (new QLineEdit (this)),
    annoDistribuzione (new QSpinBox (this)), formato (new QLineEdit (this)),
    recensione (new QComboBox (this)), autoreLD (new QLineEdit (this)),
    casaEditriceLD (new QLineEdit (this)), numeroPagine (new QSpinBox (this)), autoreAL (new QLineEdit (this)),
    casaEditriceAL (new QLineEdit (this)), durataAL (new QSpinBox (this)),
    narratore (new QLineEdit (this)), regista (new QLineEdit (this)), durataFilm (new QSpinBox (this)), artista (new QLineEdit (this)),
    numeroTracce (new QSpinBox (this)), durataMusica (new QSpinBox (this))
{
    setWindowTitle(tr("Modifica"));
    setFixedSize(QSize(400,450));
    titolo->setMaximumWidth(150);
    titolo->setPlaceholderText("Campo obbligatorio");
    genere->setMaximumWidth(150);
    annoDistribuzione->setMaximumWidth(150);
    annoDistribuzione->setMaximum(2500);
    annoDistribuzione->setValue(2000);
    formato->setMaximumWidth(150);
    recensione->setMaximumWidth(150);
    autoreLD->setMaximumWidth(150);
    casaEditriceLD->setMaximumWidth(150);
    numeroPagine->setMaximumWidth(150);
    numeroPagine->setMaximum(10000);
    autoreAL->setMaximumWidth(150);
    casaEditriceAL->setMaximumWidth(150);
    durataAL->setMaximumWidth(150);
    durataAL->setMaximum(3000);
    narratore->setMaximumWidth(150);
    regista->setMaximumWidth(150);
    durataFilm->setMaximumWidth(150);
    durataFilm->setMaximum(300);
    artista->setMaximumWidth(150);
    numeroTracce->setMaximumWidth(150);
    numeroTracce->setMaximum(50);
    durataMusica->setMaximumWidth(150);
    durataMusica->setMaximum(300);
    QPushButton* modifica= new QPushButton("Modifica");
    QPushButton* reset= new QPushButton("Reset");
    modifica->setMaximumWidth(120);
    reset->setMaximumWidth(120);
    modifica->setMinimumHeight(40);
    reset->setMinimumHeight(40);

    recensione->addItem("1");
    recensione->addItem("2");
    recensione->addItem("3");
    recensione->addItem("4");
    recensione->addItem("5");
    recensione->setMaximumWidth(150);

    QVBoxLayout* Layout = new QVBoxLayout(this);

    QHBoxLayout* titoloLayout = new QHBoxLayout();
    titoloLayout->addWidget(titoloL);
    titoloLayout->addWidget(titolo);

    QHBoxLayout* genereLayout = new QHBoxLayout();
    genereLayout->addWidget(genereL);
    genereLayout->addWidget(genere);

    QHBoxLayout* annoDistribuzioneLayout = new QHBoxLayout();
    annoDistribuzioneLayout->addWidget(annoDistribuzioneL);
    annoDistribuzioneLayout->addWidget(annoDistribuzione);

    QHBoxLayout* formatoLayout = new QHBoxLayout();
    formatoLayout->addWidget(formatoL);
    formatoLayout->addWidget(formato);

    QHBoxLayout* recensioneLayout = new QHBoxLayout();
    recensioneLayout->addWidget(recensioneL);
    recensioneLayout->addWidget(recensione);

    QHBoxLayout* autoreLDLayout = new QHBoxLayout();
    autoreLDLayout->addWidget(autoreLDL);
    autoreLDLayout->addWidget(autoreLD);

    QHBoxLayout* casaEditriceLDLayout = new QHBoxLayout();
    casaEditriceLDLayout->addWidget(casaEditriceLDL);
    casaEditriceLDLayout->addWidget(casaEditriceLD);

    QHBoxLayout* numeroPagineLayout = new QHBoxLayout();
    numeroPagineLayout->addWidget(numeroPagineL);
    numeroPagineLayout->addWidget(numeroPagine);

    QHBoxLayout* autoreALLayout = new QHBoxLayout();
    autoreALLayout->addWidget(autoreALL);
    autoreALLayout->addWidget(autoreAL);

    QHBoxLayout* casaEditriceALLayout = new QHBoxLayout();
    casaEditriceALLayout->addWidget(casaEditriceALL);
    casaEditriceALLayout->addWidget(casaEditriceAL);

    QHBoxLayout* durataALLayout = new QHBoxLayout();
    durataALLayout->addWidget(durataALL);
    durataALLayout->addWidget(durataAL);

    QHBoxLayout* narratoreLayout = new QHBoxLayout();
    narratoreLayout->addWidget(narratoreL);
    narratoreLayout->addWidget(narratore);

    QHBoxLayout* registaLayout = new QHBoxLayout();
    registaLayout->addWidget(registaL);
    registaLayout->addWidget(regista);

    QHBoxLayout* durataFilmLayout = new QHBoxLayout();
    durataFilmLayout->addWidget(durataFilmL);
    durataFilmLayout->addWidget(durataFilm);

    QHBoxLayout* artistaLayout = new QHBoxLayout();
    artistaLayout->addWidget(artistaL);
    artistaLayout->addWidget(artista);

    QHBoxLayout* numeroTracceLayout = new QHBoxLayout();
    numeroTracceLayout->addWidget(numeroTracceL);
    numeroTracceLayout->addWidget(numeroTracce);

    QHBoxLayout* durataMusicaLayout = new QHBoxLayout();
    durataMusicaLayout->addWidget(durataMusicaL);
    durataMusicaLayout->addWidget(durataMusica);

    QHBoxLayout* bottoni = new QHBoxLayout();
    bottoni->addSpacerItem(new QSpacerItem(0,80));
    bottoni->addWidget(modifica);
    bottoni->addWidget(reset);

    Layout->addLayout(titoloLayout);
    Layout->addLayout(genereLayout);
    Layout->addLayout(annoDistribuzioneLayout);
    Layout->addLayout(formatoLayout);
    Layout->addLayout(recensioneLayout);
    Layout->addLayout(autoreLDLayout);
    Layout->addLayout(casaEditriceLDLayout);
    Layout->addLayout(numeroPagineLayout);
    Layout->addLayout(autoreALLayout);
    Layout->addLayout(casaEditriceALLayout);
    Layout->addLayout(durataALLayout);
    Layout->addLayout(narratoreLayout);
    Layout->addLayout(registaLayout);
    Layout->addLayout(durataFilmLayout);
    Layout->addLayout(artistaLayout);
    Layout->addLayout(numeroTracceLayout);
    Layout->addLayout(durataMusicaLayout);
    Layout->addLayout(bottoni);

    connect(modifica, SIGNAL(clicked()), this, SLOT(modifica()));
    connect(modifica, SIGNAL(clicked()), this, SLOT(reset()));
    connect(reset, SIGNAL(clicked()), this, SLOT(reset()));


    MediaItem* item = *(modello->getElement(index));


    titolo->setText(QString::fromStdString((item)->getTitolo()));
    genere->setText(QString::fromStdString((item)->getGenere()));
    annoDistribuzione->setValue(item->getAnno());
    formato->setText(QString::fromStdString((item)->getFormato()));
    recensione->setCurrentIndex(((item)->getRecensione()-1));

    if (dynamic_cast<Librodigitale*>(item)){
        Librodigitale* i=dynamic_cast<Librodigitale*>(item);
        autoreLD->setText(QString::fromStdString((i)->getAutore()));
        casaEditriceLD->setText(QString::fromStdString((i)->getCasaEditrice()));
        numeroPagine->setValue(i->getPagine());
    }

    if (dynamic_cast<Audiolibro*>(item)){
        Audiolibro* i=dynamic_cast<Audiolibro*>(item);
        autoreAL->setText(QString::fromStdString((i)->getAutore()));
        casaEditriceAL->setText(QString::fromStdString((i)->getCasaEditrice()));
        narratore->setText(QString::fromStdString((i)->getNarratore()));
        durataAL->setValue(i->getDurata());
    }

    if (dynamic_cast<Film*>(item)){
        Film* i=dynamic_cast<Film*>(item);
        regista->setText(QString::fromStdString((i)->getRegista()));
        durataFilm->setValue(i->getDurata());
    }
    if (dynamic_cast<Musica*>(item)){
        Musica* i=dynamic_cast<Musica*>(item);
        artista->setText(QString::fromStdString((i)->getArtista()));
        numeroTracce->setValue(i->getNumeroTracce());
        durataMusica->setValue(i->getDurata());
    }

    autoreLDL->setVisible(false);
    autoreLD->setVisible(false);
    casaEditriceLDL->setVisible(false);
    casaEditriceLD->setVisible(false);
    numeroPagineL->setVisible(false);
    numeroPagine->setVisible(false);
    autoreALL->setVisible(false);
    autoreAL->setVisible(false);
    casaEditriceALL->setVisible(false);
    casaEditriceAL->setVisible(false);
    durataALL->setVisible(false);
    durataAL->setVisible(false);
    narratoreL->setVisible(false);
    narratore->setVisible(false);
    registaL->setVisible(false);
    regista->setVisible(false);
    durataFilmL->setVisible(false);
    durataFilm->setVisible(false);
    artistaL->setVisible(false);
    artista->setVisible(false);
    numeroTracceL->setVisible(false);
    numeroTracce->setVisible(false);
    durataMusicaL->setVisible(false);
    durataMusica->setVisible(false);


    if (dynamic_cast<Librodigitale*>(item)){
        autoreLDL->setVisible(true);
        autoreLD->setVisible(true);
        casaEditriceLDL->setVisible(true);
        casaEditriceLD->setVisible(true);
        numeroPagineL->setVisible(true);
        numeroPagine->setVisible(true);
    }
    else{
        autoreLDL->setVisible(false);
        autoreLD->setVisible(false);
        casaEditriceLDL->setVisible(false);
        casaEditriceLD->setVisible(false);
        numeroPagineL->setVisible(false);
        numeroPagine->setVisible(false);
    }

    if (dynamic_cast<Audiolibro*>(item)){
        autoreALL->setVisible(true);
        autoreAL->setVisible(true);
        casaEditriceALL->setVisible(true);
        casaEditriceAL->setVisible(true);
        durataALL->setVisible(true);
        durataAL->setVisible(true);
        narratoreL->setVisible(true);
        narratore->setVisible(true);
    }
    else{
        autoreALL->setVisible(false);
        autoreAL->setVisible(false);
        casaEditriceALL->setVisible(false);
        casaEditriceAL->setVisible(false);
        durataALL->setVisible(false);
        durataAL->setVisible(false);
        narratoreL->setVisible(false);
        narratore->setVisible(false);
    }

    if (dynamic_cast<Film*>(item)){
        registaL->setVisible(true);
        regista->setVisible(true);
        durataFilmL->setVisible(true);
        durataFilm->setVisible(true);
    }
    else{
        registaL->setVisible(false);
        regista->setVisible(false);
        durataFilmL->setVisible(false);
        durataFilm->setVisible(false);
    }
    if (dynamic_cast<Musica*>(item)){
        artistaL->setVisible(true);
        artista->setVisible(true);
        numeroTracceL->setVisible(true);
        numeroTracce->setVisible(true);
        durataMusicaL->setVisible(true);
        durataMusica->setVisible(true);
    }
    else{
        artistaL->setVisible(false);
        artista->setVisible(false);
        numeroTracceL->setVisible(false);
        numeroTracce->setVisible(false);
        durataMusicaL->setVisible(false);
        durataMusica->setVisible(false);
    }

}

void Modifica::modifica()
{
    if(getTitolo() == ""){
        QMessageBox error;
        error.critical(this,"Errore","Campi obbligatori mancanti o non validi\nIl titolo è un campo obbligatorio");
        error.setFixedSize(300,100);
        hide();
    }
    else
    {
    MediaItem* item = *(modello->getElement(index));
    item->setRecensione(getRecensione());
    QListWidgetItem* listitem = vista->currentItem();
    if((*(modello->getElement(index)))->getRecensione()==1)
        listitem->setBackground(QColor(255,160,122));
    if((*(modello->getElement(index)))->getRecensione()==2)
        listitem->setBackground(QColor(255,255,255));
    if((*(modello->getElement(index)))->getRecensione()==3)
        listitem->setBackground(QColor(255,255,255));
    if((*(modello->getElement(index)))->getRecensione()==4)
        listitem->setBackground(QColor(152,251,152));
    if((*(modello->getElement(index)))->getRecensione()==5)
        listitem->setBackground(QColor(152,251,152));
    item->setTitolo(getTitolo());
    item->setGenere(getGenere());
    item->setAnno(getAnno());
    item->setFormato(getFormato());

    if (dynamic_cast<Librodigitale*>(item)){
        Librodigitale* i=dynamic_cast<Librodigitale*>(item);
        i->setAutore(getAutoreLD());
        i->setCasaEditrice(getCasaEditriceLD());
        i->setPagine(getPagine());
    }

    if (dynamic_cast<Audiolibro*>(item)){
        Audiolibro* i=dynamic_cast<Audiolibro*>(item);
        i->setAutore(getAutoreAL());
        i->setCasaEditrice(getCasaEditriceAL());
        i->setDurata(getDurataAL());
        i->setNarratore(getNarratore());
    }

    if (dynamic_cast<Film*>(item)){
        Film* i=dynamic_cast<Film*>(item);
        i->setRegista(getRegista());
        i->setDurata(getDurataFilm());
    }

    if (dynamic_cast<Musica*>(item)){
        Musica* i=dynamic_cast<Musica*>(item);
        i->setArtista(getArtista());
        i->setNumeroTracce(getNumeroTracce());
        i->setDurata(getDurataMusica());
    }


    titolo->setText("");
    genere->setText("");
    formato->setText("");

    QListWidgetItem* itemView = vista->item(index);
    QString a = QString::fromStdString((*(modello->getElement(index)))->getTitolo());
    itemView->setText(a);
    vista->clearSelection();
    hide();
    }
}

void Modifica::reset() const
{
    titolo->setText("");
    genere->setText("");
    annoDistribuzione->setValue(2000);
    formato->setText("");
    recensione->setCurrentIndex(0);
    autoreLD->setText("");
    casaEditriceLD->setText("");
    numeroPagine->setValue(0);
    autoreAL->setText("");
    casaEditriceAL->setText("");
    durataAL->setValue(0);
    narratore->setText("");
    regista->setText("");
    durataFilm->setValue(0);
    artista->setText("");
    numeroTracce->setValue(0);
    durataMusica->setValue(0);
}

std::string Modifica::getTitolo() const
{
    return titolo->text().toStdString();
}

std::string Modifica::getGenere() const
{
    return genere->text().toStdString();
}

unsigned int Modifica::getAnno() const
{
    return annoDistribuzione->text().toUInt();
}

std::string Modifica::getFormato() const
{
    return formato->text().toStdString();
}

unsigned int Modifica::getRecensione() const
{
    if (recensione->currentText()=="1")
        return 1;
    if (recensione->currentText()=="2")
        return 2;
    if (recensione->currentText()=="3")
        return 3;
    if (recensione->currentText()=="4")
        return 4;
    return 5;
}

std::string Modifica::getAutoreLD() const
{
    return autoreLD->text().toStdString();
}

std::string Modifica::getCasaEditriceLD() const
{
    return casaEditriceLD->text().toStdString();
}

unsigned int Modifica::getPagine() const
{
    return numeroPagine->text().toUInt();
}

std::string Modifica::getAutoreAL() const
{
    return autoreAL->text().toStdString();
}

std::string Modifica::getCasaEditriceAL() const
{
    return casaEditriceAL->text().toStdString();
}

unsigned int Modifica::getDurataAL() const
{
    return durataAL->text().toUInt();
}

std::string Modifica::getNarratore() const
{
    return narratore->text().toStdString();
}

std::string Modifica::getRegista() const
{
    return regista->text().toStdString();
}

unsigned int Modifica::getDurataFilm() const
{
    return durataFilm->text().toUInt();
}

std::string Modifica::getArtista() const
{
    return artista->text().toStdString();
}

unsigned int Modifica::getNumeroTracce() const
{
    return numeroTracce->text().toUInt();
}

unsigned int Modifica::getDurataMusica() const
{
    return durataMusica->text().toUInt();
}
