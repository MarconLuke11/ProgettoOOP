#include "fileaudio.h"

Fileaudio::Fileaudio(string tit, string gen, unsigned int anno, string form, unsigned int rec, unsigned int dur):
    MediaItem (tit, gen, anno, form, rec), durata(dur)  {}

string Fileaudio::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value2;
    value2 << std::fixed << std::setprecision(4) << durata;
    stream += "\nDurata: " + value2.str() + "minuti";
    return stream;
}

unsigned int Fileaudio::getDurata() const
{
    return durata;
}

void Fileaudio::setDurata(const unsigned int& m)
{
    durata=m;
}

bool Fileaudio::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Fileaudio*>(&a) && MediaItem::operator==(a)
             && durata==static_cast<const Fileaudio&>(a).durata;
}

bool Fileaudio::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Fileaudio*>(&a) || MediaItem::operator!=(a) || durata!=static_cast<const Fileaudio&>(a).durata;
}
