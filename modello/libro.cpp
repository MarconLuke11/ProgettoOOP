#include "libro.h"

Libro::Libro(string tit, string gen, unsigned int anno, string form, unsigned int rec, string aut, string cEd):
    MediaItem (tit, gen, anno, form, rec), autore(aut), casaEditrice(cEd)  {}

string Libro::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(5);
    stream += "\nTipo: Libro\nAutore: " + autore + "\nCasa Editrice: " + casaEditrice + value.str();
    return stream;
}

string Libro::getAutore() const
{
    return autore;
}

string Libro::getCasaEditrice() const
{
    return casaEditrice;
}

void Libro::setAutore(const string& m)
{
    autore=m;
}

void Libro::setCasaEditrice(const string& m)
{
    casaEditrice=m;
}

bool Libro::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Libro*>(&a) && MediaItem::operator==(a) && autore==static_cast<const Libro&>(a).autore
            && casaEditrice==static_cast<const Libro&>(a).casaEditrice;
}

bool Libro::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Libro*>(&a) || MediaItem::operator!=(a) || autore!=static_cast<const Libro&>(a).autore
            || casaEditrice!=static_cast<const Libro&>(a).casaEditrice;
}
