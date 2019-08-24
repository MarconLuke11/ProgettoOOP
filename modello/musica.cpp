#include "musica.h"

Musica::Musica(string tit, string gen, unsigned int anno, string form, unsigned int rec, string art, unsigned int nTr, unsigned int dur):
    MediaItem (tit, gen, anno, form, rec), artista(art), numeroTracce(nTr), durata(dur)  {}

string Musica::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(3) << numeroTracce;
    std::stringstream value2;
    value2 << std::fixed << std::setprecision(4) << durata;
    stream += "\nTipo: Musica\nArtista: " + artista + "\nNumero di tracce: " + value.str(); + "\nDurata: " + value2.str() + "minuti";
    return stream;
}

unsigned int Musica::durataTOT() const
{
    unsigned int durataTotale = getDurata();
    return durataTotale > 0 ? durataTotale : 0;
}

string Musica::getArtista() const
{
    return artista;
}

unsigned int Musica::getNumeroTracce() const
{
    return numeroTracce;
}

unsigned int Musica::getDurata() const
{
    return durata;
}

void Musica::setArtista(const string& m)
{
    artista=m;
}

void Musica::setNumeroTracce(const unsigned int& m)
{
    numeroTracce=m;
}

void Musica::setDurata(const unsigned int& m)
{
    durata=m;
}

bool Musica::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Musica*>(&a) && MediaItem::operator==(a) && artista==static_cast<const Musica&>(a).artista
            && numeroTracce==static_cast<const Musica&>(a).numeroTracce && durata==static_cast<const Musica&>(a).durata;
}

bool Musica::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Musica*>(&a) || MediaItem::operator!=(a) || artista!=static_cast<const Musica&>(a).artista
            || numeroTracce!=static_cast<const Musica&>(a).numeroTracce || durata!=static_cast<const Musica&>(a).durata;
}

