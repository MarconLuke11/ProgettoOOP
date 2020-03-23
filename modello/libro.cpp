#include "libro.h"

Libro::Libro(string tit, string gen, unsigned int anno, string form, unsigned int rec, string aut, string cEd, unsigned int pag):
    MediaItem (tit, gen, anno, form, rec), autore(aut), casaEditrice(cEd), numeroPagine(pag)  {}

string Libro::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(5) << numeroPagine;
    stream += "\nTipo: Libro\nAutore: " + autore + "\nCasa Editrice: " + casaEditrice + "\nNumero di pagine: " + value.str();
    return stream;
}

unsigned int Libro::durataTOT() const
{
    unsigned int durataTotale = getPagine() *3; //calcolando 3 minuti per leggere una pagina
    return durataTotale > 0 ? durataTotale : 0;
}

string Libro::getAutore() const
{
    return autore;
}

string Libro::getCasaEditrice() const
{
    return casaEditrice;
}

unsigned int Libro::getPagine() const
{
    return numeroPagine;
}

void Libro::setAutore(const string& m)
{
    autore=m;
}

void Libro::setCasaEditrice(const string& m)
{
    casaEditrice=m;
}

void Libro::setPagine(const unsigned int& m)
{
    numeroPagine=m;
}

bool Libro::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Libro*>(&a) && MediaItem::operator==(a) && autore==static_cast<const Libro&>(a).autore
            && casaEditrice==static_cast<const Libro&>(a).casaEditrice && numeroPagine==static_cast<const Libro&>(a).numeroPagine;
}

bool Libro::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Libro*>(&a) || MediaItem::operator!=(a) || autore!=static_cast<const Libro&>(a).autore
            || casaEditrice!=static_cast<const Libro&>(a).casaEditrice || numeroPagine!=static_cast<const Libro&>(a).numeroPagine;
}
