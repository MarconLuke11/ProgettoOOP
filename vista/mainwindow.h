#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <regex>

#include "modello/modello.h"
#include "inserimento.h"
#include "modifica.h"
#include "duratatotale.h"
#include "about.h"
#include "sviluppo.h"
#include "ricerca.h"
#include "modello/container.h"
#include "modello/libro.h"
#include "modello/film.h"
#include "modello/musica.h"


class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QListWidget* vista;
    Modello* modello;
    Inserimento* inserimento;

    QLabel* img;
    QLabel* titoloShow;
    QLabel* genereShow;
    QLabel* annoDistribuzioneShow;
    QLabel* formatoShow;
    QLabel* recensioneShow;
    QLabel* autoreShow;
    QLabel* casaEditriceShow;
    QLabel* numeroPagineShow;
    QLabel* registaShow;
    QLabel* durataFilmShow;
    QLabel* artistaShow;
    QLabel* numeroTracceShow;
    QLabel* durataMusicaShow;


    QLineEdit* searchBar;
    QVBoxLayout* secondLayout;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load();

public slots:
    void openInsert() const;
    void openSearch();
    void openPreferiti();
    void openDurata();
    void addItem();
    void showLabel();
    void removeItem();
    void removeAllItem();
    void openModify();
    void textFilterChanged();
    void resetSearch();
    void save();
    void about();
    void sviluppo();
    void ordineAlfa();
    void salvato();
    //void display();
};

#endif // MAINWINDOW_H
