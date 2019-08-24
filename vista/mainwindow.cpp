#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
QWidget(parent), vista(new QListWidget(this)), modello(new Modello()), inserimento(new Inserimento(modello,this)),
img(new QLabel ("",this)), titoloShow(new QLabel ("",this)),genereShow(new QLabel ("",this)), annoDistribuzioneShow(new QLabel ("",this)), formatoShow(new QLabel ("",this)),
recensioneShow(new QLabel ("",this)), autoreShow(new QLabel ("",this)), casaEditriceShow(new QLabel ("",this)),
numeroPagineShow(new QLabel ("",this)), registaShow(new QLabel ("",this)), durataFilmShow(new QLabel ("",this)),
artistaShow(new QLabel ("",this)), numeroTracceShow(new QLabel ("",this)), durataMusicaShow(new QLabel ("",this)),
searchBar (new QLineEdit (this))
{
    setWindowTitle(tr("Media Qllection"));
    setFixedSize(QSize(750,650));
    setMinimumSize(720,400);
    setMaximumSize(1000,700);
    setWindowIcon(QIcon("../ProgettoOOP/img/App.png"));
    vista->setFixedWidth(300);

    load();
    //aggiunta bottoni
    QPushButton* addButton = new QPushButton("Aggiungi", this);
    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    QPushButton* clearButton = new QPushButton("Rimuovi tutto", this);
    QPushButton* modifyButton = new QPushButton("Modifica", this);
    QPushButton* searchButton = new QPushButton ("Cerca",this);
    QPushButton* preferitiButton = new QPushButton ("Mostra solo preferiti",this);
    preferitiButton->setIcon(QPixmap::fromImage(QImage("../ProgettoOOP/img/Preferiti.png")));
    preferitiButton->setIconSize(QSize(32,32));
    QPushButton* durataButton = new QPushButton ("Calcola il tuo intrattenimento totale",this);
    QPushButton* ordineAlfa = new QPushButton ("Ordine alfabetico",this);
    searchButton->setObjectName("searchButton");    
    QPushButton* search2Button = new QPushButton ("Ricerca personalizzata",this);
    QPushButton* resetSearchButton = new QPushButton ("Reset filtri",this);
    searchBar->setPlaceholderText(QString::fromStdString("Inserisci il titolo da cercare, poi tasto Cerca oppure Invio"));
    searchBar->setObjectName("searchBar");

    //creo il menu
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* menu = new QMenu("File", menuBar);
    QMenu* menu2 = new QMenu("Help", menuBar);
    QAction* save = new QAction("Salva", menu);
    QAction* exit = new QAction("Esci", menu);
    QAction* about = new QAction("About",menu);
    QAction* sviluppo = new QAction("Development Info",menu);

    //assemblo gli elementi del menu
    menuBar->addMenu(menu);
    menuBar->addMenu(menu2);
    menu->addAction(save);
    menu->addAction(exit);
    menu2->addAction(about);
    menu2->addAction(sviluppo);

    //aggiunta barra di ricerca
    QHBoxLayout* search = new QHBoxLayout();
    search->addWidget(searchBar);
    search->addWidget(searchButton);

    //aggiunta bottone di ricerca
    QHBoxLayout* searchB = new QHBoxLayout();
    searchB->addWidget(search2Button);
    searchB->addWidget(resetSearchButton);

    QHBoxLayout* preferitiB = new QHBoxLayout();
    preferitiB->addWidget(preferitiButton);

    //layout principale
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    //layout pannello inserimento di destra
    QHBoxLayout* buttons1 = new QHBoxLayout();
    buttons1->addWidget(addButton);
    buttons1->addWidget(removeButton);

    QHBoxLayout* buttons2 = new QHBoxLayout();
    buttons2->addWidget(modifyButton);
    buttons2->addWidget(clearButton);

    QHBoxLayout* buttons3 = new QHBoxLayout();
    buttons3->addWidget(durataButton);

    QHBoxLayout* buttons4 = new QHBoxLayout();
    buttons4->addWidget(ordineAlfa);

    QVBoxLayout* buttons = new QVBoxLayout();

    QHBoxLayout* spazioB = new QHBoxLayout();
    spazioB->addSpacerItem(new QSpacerItem(0, 30));

    QHBoxLayout* spazio2B = new QHBoxLayout();
    spazio2B->addSpacerItem(new QSpacerItem(0, 30));

    //implementando il display() tutto ciò che segue puo essere compattato in un'unica funzione
    QVBoxLayout* infos = new QVBoxLayout();
    autoreShow->setHidden(true);
    casaEditriceShow->setHidden(true);
    numeroPagineShow->setHidden(true);
    registaShow->setHidden(true);
    durataFilmShow->setHidden(true);
    artistaShow->setHidden(true);
    numeroTracceShow->setHidden(true);
    durataMusicaShow->setHidden(true);
    infos->addWidget(img);
    infos->addSpacerItem(new QSpacerItem(0, 20));
    infos->addWidget(titoloShow);
    infos->addWidget(genereShow);
    infos->addWidget(annoDistribuzioneShow);
    infos->addWidget(formatoShow);    
    infos->addWidget(autoreShow);
    infos->addWidget(casaEditriceShow);
    infos->addWidget(numeroPagineShow);
    infos->addWidget(registaShow);
    infos->addWidget(durataFilmShow);
    infos->addWidget(artistaShow);
    infos->addWidget(numeroTracceShow);
    infos->addWidget(durataMusicaShow);
    infos->addWidget(recensioneShow);
    img->setAlignment(Qt::AlignHCenter);
    titoloShow->setAlignment(Qt::AlignHCenter);
    genereShow->setAlignment(Qt::AlignHCenter);
    annoDistribuzioneShow->setAlignment(Qt::AlignHCenter);
    formatoShow->setAlignment(Qt::AlignHCenter);
    recensioneShow->setAlignment(Qt::AlignHCenter);
    autoreShow->setAlignment(Qt::AlignHCenter);
    casaEditriceShow->setAlignment(Qt::AlignHCenter);
    numeroPagineShow->setAlignment(Qt::AlignHCenter);
    registaShow->setAlignment(Qt::AlignHCenter);
    durataFilmShow->setAlignment(Qt::AlignHCenter);
    artistaShow->setAlignment(Qt::AlignHCenter);
    numeroTracceShow->setAlignment(Qt::AlignHCenter);
    durataMusicaShow->setAlignment(Qt::AlignHCenter);

    titoloShow->setObjectName("titolo");

    QVBoxLayout* fourthLayout = new QVBoxLayout();
    QVBoxLayout* thirdLayout = new QVBoxLayout();
    QHBoxLayout* secondLayout = new QHBoxLayout();
    QHBoxLayout* firstLayout = new QHBoxLayout();

    //sistemo i layout
    mainLayout->setMenuBar(menuBar);
    mainLayout->addLayout(firstLayout);
    firstLayout->addLayout(secondLayout);
    firstLayout->addLayout(thirdLayout);
    secondLayout->addWidget(vista);
    buttons->addLayout(buttons1);
    buttons->addLayout(buttons2);
    buttons->addLayout(buttons3);
    buttons->addLayout(buttons4);
    thirdLayout->addLayout(search);
    thirdLayout->addLayout(searchB);    
    thirdLayout->addLayout(preferitiB);
    thirdLayout->addLayout(spazioB);
    thirdLayout->addLayout(infos);
    thirdLayout->addLayout(spazio2B);
    mainLayout->addLayout(fourthLayout);
    fourthLayout->addLayout(buttons);

    connect(addButton,SIGNAL(clicked()),this,SLOT(openInsert()));
    connect(removeButton,SIGNAL(clicked()),this,SLOT(removeItem()));
    connect(clearButton, SIGNAL(clicked()),this,SLOT(removeAllItem()));
    connect(modifyButton, SIGNAL(clicked()),this,SLOT(openModify()));
    connect(durataButton,SIGNAL(clicked()),this,SLOT(openDurata()));
    connect(inserimento,SIGNAL(inserisciClicked()), this, SLOT(addItem()));
    connect(vista,SIGNAL(itemSelectionChanged()),this,SLOT(showLabel()));
    connect(searchButton,SIGNAL(clicked()), this, SLOT(textFilterChanged()));
    connect(searchBar,SIGNAL(returnPressed()), this, SLOT(textFilterChanged()));
    connect(search2Button,SIGNAL(clicked()), this, SLOT(openSearch()));
    connect(resetSearchButton, SIGNAL(clicked()), this, SLOT(resetSearch()));
    connect(preferitiButton, SIGNAL(clicked()), this, SLOT(openPreferiti()));
    connect(save, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(save, SIGNAL(triggered(bool)), this, SLOT(salvato()));
    connect(about, SIGNAL(triggered(bool)), this, SLOT(about()));
    connect(sviluppo, SIGNAL(triggered(bool)), this, SLOT(sviluppo()));
    connect(ordineAlfa,SIGNAL(clicked(bool)),this,SLOT(ordineAlfa()));
    connect(exit,SIGNAL(triggered(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    if(modello) delete modello;
}

void MainWindow::load()
{
    modello->loadFromFile();

    Container<MediaItem*>::iteratore it = modello->begin();
    int cont=0;

    while(it != modello->end()){
        QIcon icona;
        if (dynamic_cast<Libro*>(*(it))){
            icona= QIcon("../ProgettoOOP/img/libro1.png");
        }
        if (dynamic_cast<Film*>(*(it))){
            icona= QIcon("../ProgettoOOP/img/film1.png");
        }
        if (dynamic_cast<Musica*>(*(it))){
            icona= QIcon("../ProgettoOOP/img/musica1.png");
        }
        QString a = QString::fromStdString((*(modello->getElement(cont)))->getTitolo());
        QListWidgetItem* listitem = new QListWidgetItem(a,vista);
        listitem->setTextAlignment(Qt::AlignCenter);
        listitem->setIcon(icona);
        if((*(modello->getElement(cont)))->getRecensione()==1)
            listitem->setBackground(QColor(255,160,122));
        if((*(modello->getElement(cont)))->getRecensione()==2)
            listitem->setBackground(QColor(255,255,255));
        if((*(modello->getElement(cont)))->getRecensione()==3)
            listitem->setBackground(QColor(255,255,255));
        if((*(modello->getElement(cont)))->getRecensione()==4)
            listitem->setBackground(QColor(152,251,152));
        if((*(modello->getElement(cont)))->getRecensione()==5)
            listitem->setBackground(QColor(152,251,152));

        vista->addItem(listitem);
        cont++;
        it++;
    }

}

void MainWindow::openInsert() const{
    inserimento->setObjectName("Inserimento");
    inserimento->exec();
}

void MainWindow::openSearch()
{
    Ricerca* cerca = new Ricerca(vista, modello, this);
    cerca->setObjectName("ricercaWindow");
    cerca->exec();
}

void MainWindow::openPreferiti()
{
    for(int i = 0; i < modello->conta(); i++)
    {
        if((*(modello->getElement(i)))->getRecensione()!=5)
        {
            vista->item(i)->setHidden(true);
        }
    }
}

void MainWindow::openDurata()
{
    DurataTotale* prezzo = new DurataTotale(modello,this);
    prezzo->setObjectName("durataWindow");
    prezzo->exec();
}

void MainWindow::addItem() {
    if (inserimento->getTitolo()=="")
    {
            QMessageBox error;
            error.critical(this,"Errore","Il campo Titolo è un campo obbligatorio");
            error.setFixedSize(300,100);
    }


    else
    {
        QIcon icona;
        if (inserimento->getScelta()=="Libro"){
                Libro* item = new Libro(inserimento->getTitolo(),inserimento->getGenere(),inserimento->getAnno(),inserimento->getFormato(),inserimento->getRecensione(),
                                      inserimento->getAutore(),inserimento->getCasaEditrice(),inserimento->getPagine() );
                modello->aggiungi(item);
                icona= QIcon("../ProgettoOOP/img/libro1.png");
        }
        if (inserimento->getScelta()=="Film"){
                Film* item = new Film(inserimento->getTitolo(),inserimento->getGenere(),inserimento->getAnno(),inserimento->getFormato(),inserimento->getRecensione(),
                                      inserimento->getRegista(),inserimento->getDurataFilm());
                modello->aggiungi(item);
                icona= QIcon("../ProgettoOOP/img/film1.png");
        }
        if (inserimento->getScelta()=="Musica"){
                Musica* item = new Musica(inserimento->getTitolo(),inserimento->getGenere(),inserimento->getAnno(),inserimento->getFormato(),inserimento->getRecensione(),
                                          inserimento->getArtista(),inserimento->getNumeroTracce(),inserimento->getDurataMusica() );
                modello->aggiungi(item);
                icona= QIcon("../ProgettoOOP/img/musica1.png");
        }
        QString a = QString::fromStdString((*(modello->getElement(modello->conta()-1)))->getTitolo());
        QListWidgetItem* listitem = new QListWidgetItem(a,vista);
        listitem->setTextAlignment(Qt::AlignCenter);
        listitem->setIcon(icona);
        if((*(modello->getElement(modello->conta()-1)))->getRecensione()==1)
            listitem->setBackground(QColor(255,160,122));
        if((*(modello->getElement(modello->conta()-1)))->getRecensione()==4)
            listitem->setBackgroundColor(QColor(152,251,152));
        if((*(modello->getElement(modello->conta()-1)))->getRecensione()==5)
            listitem->setBackgroundColor(QColor(152,251,152));
        vista->addItem(listitem);
        std::cout<<"con dimensione: "<<modello->conta()<<"\n";
        for (auto it = modello->begin();it!=modello->end();it++)
            std::cout<<" "<<((*(it))->getTitolo());
        std::cout<<"\n";
        for (auto it = modello->getElement(modello->conta()-1);it!=modello->begin();it--)
            std::cout<<" "<<((*(it))->getTitolo());
        auto t= *(modello->getElement(0));
        std::cout<<" "<<t->getTitolo();
        std::cout<<" \n";

        inserimento->hide();
    }

}

void MainWindow::showLabel()
{
    if (modello->conta()>0){
        int index=vista->currentRow();
        if (index>modello->conta()-1)
            index=modello->conta()-1;
        Container<MediaItem*>::iteratore selected = modello->getElement(index);

        titoloShow->setText(QString::fromUtf8("Titolo: ") + QString::fromStdString((*(selected))->getTitolo()));
        genereShow->setText(QString::fromUtf8("Genere: ") + QString::fromStdString((*(selected))->getGenere()));
        annoDistribuzioneShow->setText(QString::fromUtf8("Anno di distribuzione: ") + QString::number((*(selected))->getAnno()));
        formatoShow->setText(QString::fromUtf8("Formato: ") + QString::fromStdString((*(selected))->getFormato()));
        recensioneShow->setText("");
        if ((*(selected))->getRecensione()==1){
            recensioneShow->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/cuore1.png")));
        }
        if ((*(selected))->getRecensione()==2){
            recensioneShow->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/cuore2.png")));
        }
        if ((*(selected))->getRecensione()==3){
            recensioneShow->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/cuore3.png")));
        }
        if ((*(selected))->getRecensione()==4){
            recensioneShow->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/cuore4.png")));
        }
        if ((*(selected))->getRecensione()==5){
            recensioneShow->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/cuore5.png")));
        }

        if (dynamic_cast<Libro*>(*selected)){
            img->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/libro2.png")));
            auto cast=dynamic_cast<Libro*>(*selected);
            autoreShow->setText(QString::fromUtf8("Autore: ") + QString::fromStdString((cast)->getAutore()));
            casaEditriceShow->setText(QString::fromUtf8("Casa editrice: ") + QString::fromStdString((cast)->getCasaEditrice()));
            numeroPagineShow->setText(QString::fromUtf8("Numero di pagine: ") + QString::number((cast)->getPagine()));
            autoreShow->setHidden(false);
            casaEditriceShow->setHidden(false);
            numeroPagineShow->setHidden(false);
        }
        if (!dynamic_cast<Libro*>(*selected)){
            autoreShow->setHidden(true);
            casaEditriceShow->setHidden(true);
            numeroPagineShow->setHidden(true);
        }
        if (dynamic_cast<Film*>(*selected)){
            img->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/film2.png")));
            auto cast=dynamic_cast<Film*>(*selected);
            registaShow->setText("Regista: " + QString::fromStdString((cast)->getRegista()));
            durataFilmShow->setText("Durata: " + QString::number((cast)->getDurata()) + QString::fromUtf8(" minuti"));
            registaShow->setHidden(false);
            durataFilmShow->setHidden(false);
        }
        if (!dynamic_cast<Film*>(*selected)){
            registaShow->setHidden(true);
            durataFilmShow->setHidden(true);
        }
        if (dynamic_cast<Musica*>(*selected)){
            img->setPixmap(QPixmap::fromImage(QImage("../ProgettoOOP/img/musica2.png")));
            auto cast=dynamic_cast<Musica*>(*selected);
            artistaShow->setText("Artista: " + QString::fromStdString((cast)->getArtista()));
            numeroTracceShow->setText("Numero di tracce: " + QString::number((cast)->getNumeroTracce()));
            durataMusicaShow->setText("Durata: " + QString::number((cast)->getDurata()) + QString::fromUtf8(" minuti"));
            artistaShow->setHidden(false);
            numeroTracceShow->setHidden(false);
            durataMusicaShow->setHidden(false);
        }
        if (!dynamic_cast<Musica*>(*selected)){
            artistaShow->setHidden(true);
            numeroTracceShow->setHidden(true);
            durataMusicaShow->setHidden(true);
        }

    }
    else{
        img->clear();
        titoloShow->clear();
        genereShow->setText("");
        annoDistribuzioneShow->setText("");
        formatoShow->setText("");
        recensioneShow->setText("");
        autoreShow->setText("");
        casaEditriceShow->setText("");
        numeroPagineShow->setText("");
        registaShow->setText("");
        durataFilmShow->setText("");
        artistaShow->setText("");
        numeroTracceShow->setText("");
        durataMusicaShow->setText("");
    }
}

void MainWindow::removeItem()
{
    if (modello->conta()>0 && vista->currentRow()>=0){
        int index=vista->currentRow();
        modello->rimuovi(index);
        vista->clearSelection();
        vista->clearFocus();
        delete vista->takeItem(index);
        if (index<=0)
            vista->setCurrentRow(0);
        else
            vista->setCurrentRow(index-1);
    }
    else
    {
        QMessageBox error;
        error.critical(this,"Errore","La lista è vuota, non è possibile eliminare elementi.");
        error.setFixedSize(300,100);
    }
}

void MainWindow::removeAllItem()
{
    if (modello->conta()>0){
        modello->rimuoviTutto();
        vista->clear();
    }
    else
    {
        QMessageBox error;
        error.critical(this,"Errore","La lista è vuota, non è possibile eliminare elementi.");
        error.setFixedSize(300,100);
    }
}

void MainWindow::openModify()
{
    if (vista->selectedItems().size()>0){
        int i=vista->currentRow();
        Modifica* modifica = new Modifica(modello,i,vista,this);
        modifica->setObjectName("modifyWindow");
        modifica->exec();
    }
    else
    {
        QMessageBox error;
        error.critical(this,"Errore","Non è stato selezionato alcun elemento.");
        error.setFixedSize(300,100);
    }
}

void MainWindow::textFilterChanged(){
    if (searchBar->text()!=""){
        std::string c = searchBar->text().toStdString();
        std::regex rx("[a-zA-Z]*" + c + "[a-zA-Z]*", std::regex_constants::icase);
        for(int i = 0; i < modello->conta(); i++){
            std::string x = modello->getElement(i).operator*()->getTitolo();
            QString exp = QString::fromStdString(x);
            if(!std::regex_match(x,rx)){
                vista->item(i)->setHidden(true);
            }
        }
    }
    else {
        QMessageBox error;
        error.critical(this,"Errore","Non è stata inserita alcuna chiave di ricerca");
        error.setFixedSize(300,100);
    }

}

void MainWindow::resetSearch()
{
    searchBar->setText("");
    for(int i = 0; i < modello->conta(); i++){
        vista->item(i)->setHidden(false);
    }
}

void MainWindow::save()
{
    try {
        if (modello->conta()>0)
            modello->saveToFile();
        else{
            QMessageBox error;
            error.critical(this,"Errore","Salvare un file contenente almeno un elemento");
            error.setFixedSize(300,100);
        }
    }
    catch (std::exception) {
        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Impossibile scrivere sul file", QMessageBox::Ok);
        box.exec();
    }
}

void MainWindow::about()
{
    About* about = new About(this);
    about->setObjectName("aboutWindow");
    about->exec();
}

void MainWindow::sviluppo()
{
    Sviluppo* sviluppo = new Sviluppo(this);
    sviluppo->setObjectName("developmentInfoWindow");
    sviluppo->exec();
}

void MainWindow::ordineAlfa()
{
        vista->sortItems();
        modello->ordAlfa();
}

void MainWindow::salvato(){
    QMessageBox *salvato = new QMessageBox(this);
    salvato->setText("Archivio salvato correttamente!");
    salvato->exec();
}
