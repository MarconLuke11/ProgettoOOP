#include "modello.h"

Modello::Modello() {}

Modello::~Modello()
{
    for (auto it = media.begin(); it!=media.end(); it++)
    {
        delete *it;
    }
}

int Modello::conta() const
{
    return media.count();
}

void Modello::aggiungi(MediaItem *m)
{
    media.push_back(m);
}

void Modello::rimuovi(int i)
{
    media.remove(i);
}

void Modello::rimuoviTutto()
{
    media.removeAlt();
}

unsigned int Modello::durataTotale()
{
    unsigned int durata=0;
    for (auto cit = media.cbegin(); cit!=media.cend(); cit++){
        durata += (**(cit)).durataTOT();
    }
    return durata;
}

Container<MediaItem*>::iteratore Modello::end() const{
    return media.end();
}

Container<MediaItem*>::iteratore Modello::begin() const{
    return media.begin();
}

Container<MediaItem*>::iteratore Modello::getElement(int i) const
{
    return media.getItem(i);
}

void Modello::ordAlfa()
{
    Container<MediaItem*>::iteratore begin = media.begin(), end = media.end();
    for( ; begin != end; begin++)
    {
        Container<MediaItem*>::iteratore minIt = media.min_element(begin, end);
        media.swap( *minIt, *begin);
    }
}

int Modello::sizeModello() const
{
    return media.size();
}

void Modello::saveToFile(const std::string& filename) {
    xml xml(filename);
    xml.write(media);
}

void Modello::loadFromFile(const std::string& filename) {
    xml xml(filename);
    media = xml.read();
}




