#include "audiolibro.h"

Audiolibro::Audiolibro(string tit, string gen, unsigned int anno, string form, unsigned int rec, string aut, string cEd, unsigned int dur, string nar):
    MediaItem(tit, gen, anno, form, rec), Libro(aut, cEd), Fileaudio(dur), narratore(nar) {}


string Audiolibro::info() const
{
    string stream;
    stream = Libro::info() + Fileaudio::info();
    std::stringstream value;
    value << std::fixed << narratore;
    stream += "\nTipo: Audiolibro\nNarratore: " +  value.str();
    return stream;
}

unsigned int Audiolibro::durataTOT() const
{
    unsigned int durataTotale = getDurata();
    return durataTotale > 0 ? durataTotale : 0;
}

string Audiolibro::getNarratore() const
{
    return narratore;
}

void Audiolibro::setNarratore(const string& m)
{
    narratore=m;
}

string Audiolibro::getTipo() const
{
    return "Audiolibro";
}

bool Audiolibro::operator==(const MediaItem& a) const
{

    if(typeid(const Audiolibro&) != typeid(a)) return false;
        const Audiolibro* p = dynamic_cast<const Audiolibro*>(&a);
        return MediaItem::operator==(a) && Libro::operator==(a)
                && Fileaudio::operator==(a) && narratore==p->narratore;
}

bool Audiolibro::operator!=(const MediaItem& a) const
{
    if(typeid(const Audiolibro&) != typeid(a)) return true;
        const Audiolibro* p = dynamic_cast<const Audiolibro*>(&a);
        return MediaItem::operator!=(a) || Libro::operator!=(a)
                || Fileaudio::operator!=(a) || narratore!=p->narratore;
}
