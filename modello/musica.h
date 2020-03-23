#ifndef MUSICA_H
#define MUSICA_H

#include "mediaitem.h"
#include "fileaudio.h"

class Musica : public Fileaudio
{
private:
    string artista;
    unsigned int numeroTracce;
public:
    Musica(unsigned int=0, string="Nessun artista", unsigned int=0);
    string info() const override;
    unsigned int durataTOT() const override;

    string getArtista() const;
    unsigned int getNumeroTracce() const;

    void setArtista(const string&);
    void setNumeroTracce(const unsigned int&);

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // MUSICA_H
