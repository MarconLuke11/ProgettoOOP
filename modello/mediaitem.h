#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using std::string;

class MediaItem
{
    friend std::ostream& operator<<(std::ostream &, const MediaItem&);
private:
    string titolo;
    string genere;
    unsigned int annoDistribuzione;
    string formato;
    unsigned int recensione;
public:
    MediaItem(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1);
    virtual ~MediaItem() = default; //distruttore
    virtual string info() const; //per ottenere le informazioni dell'oggetto
    virtual unsigned int durataTOT() const=0; //per calcolare la durata

    string getTitolo() const;
    string getGenere() const;
    unsigned int getAnno() const;
    string getFormato() const;
    unsigned int getRecensione();

    void setTitolo(const string& ="Nessun titolo");
    void setGenere(const string& ="Nessun genere");
    void setAnno(const unsigned int& =0);
    void setFormato(const string& ="Nessun formato");
    void setRecensione(const unsigned int& =1);

    virtual bool operator==(const MediaItem&) const;
    virtual bool operator!=(const MediaItem&) const;
    bool operator<(const MediaItem&);
};

#endif // MEDIAITEM_H
