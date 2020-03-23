#ifndef FILEAUDIO_H
#define FILEAUDIO_H

#include "mediaitem.h"

class Fileaudio : public MediaItem
{
private:
    unsigned int durata;
public:
    Fileaudio(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, unsigned int=0);
    string info() const override;
       unsigned int getDurata() const;

    void setDurata(const unsigned int&);

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // FILEAUDIO_H
