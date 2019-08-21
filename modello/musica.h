#ifndef MUSICA_H
#define MUSICA_H

#include "mediaitem.h"

class Musica : public MediaItem
{
private:
    string artista;
    unsigned int numeroTracce;
    unsigned int durata;
public:
    Musica(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun artista", unsigned int=0, unsigned int=0);
    virtual Musica* clone() const override;
    string info() const override;
    unsigned int durataTOT() const override;

    string getArtista() const;
    unsigned int getNumeroTracce() const;
    unsigned int getDurata() const;

    void setArtista(const string&);
    void setNumeroTracce(const unsigned int&);
    void setDurata(const unsigned int&);

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // MUSICA_H
