#ifndef MODELLO_H
#define MODELLO_H

#include "container.h"
#include "mediaitem.h"
#include "xml.h"

class Modello
{
private:
    Container<MediaItem*> media;
public:
    Modello();
    ~Modello();
    int conta() const;
    void aggiungi(MediaItem*);
    void rimuovi(int);
    void rimuoviTutto();
    unsigned int durataTotale();
    Container<MediaItem*>::iteratore end() const;
    Container<MediaItem*>::iteratore begin() const;
    Container<MediaItem*>::iteratore getElement(int) const;
    void ordAlfa();
    int sizeModello() const;
    void saveToFile(const std::string&);
    void loadFromFile(const std::string&);
    MediaItem* getItem(int);

};

#endif // MODELLO_H
