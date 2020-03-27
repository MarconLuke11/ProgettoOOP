#include "libro.h"

Libro::Libro(string aut, string cEd): autore(aut), casaEditrice(cEd)  {}

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
    return dynamic_cast<const Libro*>(&a) && MediaItem::operator==(a) && autore==dynamic_cast<const Libro&>(a).autore
            && casaEditrice==dynamic_cast<const Libro&>(a).casaEditrice;
}

bool Libro::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Libro*>(&a) || MediaItem::operator!=(a) || autore!=dynamic_cast<const Libro&>(a).autore
            || casaEditrice!=dynamic_cast<const Libro&>(a).casaEditrice;
}
