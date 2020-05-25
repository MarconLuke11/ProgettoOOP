#include "musica.h"

Musica::Musica(string tit, string gen, unsigned int anno, string form, unsigned int rec, unsigned int dur, string art, unsigned int nTr):
    MediaItem(tit, gen, anno, form, rec), Fileaudio(dur), artista(art), numeroTracce(nTr)  {}

string Musica::info() const
{
    string stream;
    stream = Fileaudio::info();
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

string Musica::getTipo() const
{
    return "Musica";
}

bool Musica::operator==(const MediaItem& a) const
{

    if(typeid(const Musica&) != typeid(a)) return false;
        const Musica* p = dynamic_cast<const Musica*>(&a);
        return MediaItem::operator==(a) && Fileaudio::operator==(a)
                && artista==p->artista && numeroTracce==p->numeroTracce;
}

bool Musica::operator!=(const MediaItem& a) const
{

    if(typeid(const Musica&) != typeid(a)) return true;
        const Musica* p = dynamic_cast<const Musica*>(&a);
        return MediaItem::operator!=(a) || Fileaudio::operator!=(a)
                || artista!=p->artista || numeroTracce!=p->numeroTracce;
}

