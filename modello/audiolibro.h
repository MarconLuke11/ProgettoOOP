#ifndef AUDIOLIBRO_H
#define AUDIOLIBRO_H

#include "mediaitem.h"
#include "libro.h"
#include "fileaudio.h"

class Audiolibro : public Libro, public Fileaudio
{
private:
    string narratore;
public:
    Audiolibro(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun autore", string="Nessuna casa editrice", unsigned int=0, string="Nessun narratore");
    string info() const override;
    unsigned int durataTOT() const override;

    string getNarratore() const;

    void setNarratore(const string&);

    virtual string getTipo() const override;

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};


#endif // AUDIOLIBRO_H
