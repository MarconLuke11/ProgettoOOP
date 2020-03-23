#include "librodigitale.h"

Librodigitale::Librodigitale(string aut, string cEd, unsigned int pag):
    Libro(aut,cEd), numeroPagine(pag)  {}

string Librodigitale::info() const
{
    string stream;
    stream = MediaItem::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(5) << numeroPagine;
    stream += "\nTipo: Libro\nAutore: " + this->getAutore() + "\nCasa Editrice: " + this->getCasaEditrice() + "\nNumero di pagine: " + value.str();
    return stream;
}

unsigned int Librodigitale::durataTOT() const
{
    unsigned int durataTotale = numeroPagine *3; //calcolando 3 minuti per leggere una pagina
    return durataTotale > 0 ? durataTotale : 0;
}


unsigned int Librodigitale::getPagine() const
{
    return numeroPagine;
}


void Librodigitale::setPagine(const unsigned int& m)
{
    numeroPagine=m;
}

bool Librodigitale::operator==(const MediaItem& a) const
{
    return dynamic_cast<const Librodigitale*>(&a) && MediaItem::operator==(a) && Libro::operator==(a)
             && numeroPagine==static_cast<const Librodigitale&>(a).numeroPagine;
}

bool Librodigitale::operator!=(const MediaItem& a) const
{
    return !dynamic_cast<const Librodigitale*>(&a) || MediaItem::operator!=(a) || Libro::operator!=(a)
             || numeroPagine!=static_cast<const Librodigitale&>(a).numeroPagine;
}
