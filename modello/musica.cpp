#include "musica.h"

Musica::Musica(unsigned int dur, string art, unsigned int nTr):
    Fileaudio(dur), artista(art), numeroTracce(nTr)  {}

string Musica::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(3) << numeroTracce;
    stream += "\nTipo: Musica\nArtista: " + artista + "\nNumero di tracce: " + value.str();
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

void Musica::setArtista(const string& m)
{
    artista=m;
}

void Musica::setNumeroTracce(const unsigned int& m)
{
    numeroTracce=m;
}

bool Musica::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Musica*>(&a) && MediaItem::operator==(a) && Fileaudio::operator==(a) && artista==static_cast<const Musica&>(a).artista
            && numeroTracce==static_cast<const Musica&>(a).numeroTracce;
}

bool Musica::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Musica*>(&a) || MediaItem::operator!=(a) || Fileaudio::operator!=(a) ||  artista!=static_cast<const Musica&>(a).artista
            || numeroTracce!=static_cast<const Musica&>(a).numeroTracce;
}

