#include "film.h"

Film::Film(string tit, string gen, unsigned int anno, string form, unsigned int rec, string reg, unsigned int dur):
    MediaItem (tit, gen, anno, form, rec), regista(reg), durata(dur) {}

string Film::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(3) << durata;
    stream += "\nTipo: Film\nRegista: " + regista + "\nDurata: " + value.str() + "minuti";
    return stream;
}

unsigned int Film::durataTOT() const
{
    unsigned int durataTotale = getDurata();
    return durataTotale > 0 ? durataTotale : 0;
}

string Film::getRegista() const
{
    return regista;
}

unsigned int Film::getDurata() const
{
    return durata;
}

void Film::setRegista(const string &r)
{
    regista=r;
}

void Film::setDurata(const unsigned int &d)
{
    durata=d;
}

bool Film::operator==(const MediaItem &a) const
{
    return dynamic_cast<const Film*>(&a) && MediaItem::operator==(a) && regista==static_cast<const Film&>(a).regista
            && durata==static_cast<const Film&>(a).durata;
}

bool Film::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Film*>(&a) || MediaItem::operator!=(a) || regista!=static_cast<const Film&>(a).regista
            || durata!=static_cast<const Film&>(a).durata;
}
