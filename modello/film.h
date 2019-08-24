#ifndef FILM_H
#define FILM_H

#include "mediaitem.h"

class Film : public MediaItem
{
private:
    string regista;
    unsigned int durata;
public:
    Film(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun regista", unsigned int=0);
    string info() const override;
    unsigned int durataTOT() const override;

    string getRegista() const;
    unsigned int getDurata() const;

    void setRegista(const string&);
    void setDurata(const unsigned int&);

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // FILM_H
