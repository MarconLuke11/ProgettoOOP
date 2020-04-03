#ifndef INSERIMENTO_H
#define INSERIMENTO_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>

#include "modello/modello.h"

class Inserimento: public QDialog
{
    Q_OBJECT

private:
    Modello* modello;

    QComboBox* scelta;
    QLabel* titoloL;
    QLabel* genereL;
    QLabel* annoDistribuzioneL;
    QLabel* formatoL;
    QLabel* recensioneL;
    QLabel* autoreL;
    QLabel* casaEditriceL;
    QLabel* numeroPagineL;
    QLabel* narratoreL;
    QLabel* registaL;
    QLabel* durataFilmL;
    QLabel* artistaL;
    QLabel* numeroTracceL;
    QLabel* durataMusicaL;

    QLineEdit* titolo;
    QLineEdit* genere;
    QSpinBox* annoDistribuzione;
    QLineEdit* formato;
    QComboBox* recensione;
    QLineEdit* autore;
    QLineEdit* casaEditrice;
    QSpinBox* numeroPagine;
    QLineEdit* narratore;
    QLineEdit* regista;
    QSpinBox* durataFilm;
    QLineEdit* artista;
    QSpinBox* numeroTracce;
    QSpinBox* durataMusica;
public:
    explicit Inserimento(Modello*, QWidget *parent = nullptr);

    std::string getScelta() const;
    std::string getTitolo() const;
    std::string getGenere() const;
    unsigned int getAnno() const;
    std::string getFormato() const;
    unsigned int getRecensione() const;
    std::string getAutore() const;
    std::string getCasaEditrice() const;
    unsigned int getPagine() const;
    std::string getNarratore() const;
    std::string getRegista() const;
    unsigned int getDurataFilm() const;
    std::string getArtista() const;
    unsigned int getNumeroTracce() const;
    unsigned int getDurataMusica() const;

signals:
    void inserisciClicked();

public slots:
    void reset() const;
    void visualizza(const QString &) const;

};

#endif // INSERIMENTO_H
