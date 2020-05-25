#include "librodigitale.h"

Librodigitale::Librodigitale(string tit, string gen, unsigned int anno, string form, unsigned int rec, string aut, string cEd, unsigned int pag):
    MediaItem(tit, gen, anno, form, rec), Libro(aut,cEd), numeroPagine(pag)  {}


string Librodigitale::info() const
{
    string stream;
    stream = Libro::info();
    std::stringstream value;
    value << std::fixed << std::setprecision(5) << numeroPagine;
    stream += "\nNumero di pagine: " + value.str();
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

string Librodigitale::getTipo() const
{
    return "Libro digitale";
}

bool Librodigitale::operator==(const MediaItem& a) const
{
    if(typeid(const Librodigitale&) != typeid(a)) return false;
        const Librodigitale* p = dynamic_cast<const Librodigitale*>(&a);
        return MediaItem::operator==(a) && Libro::operator==(a)
             && numeroPagine==p->numeroPagine;
}

bool Librodigitale::operator!=(const MediaItem& a) const
{
    if(typeid(const Librodigitale&) != typeid(a)) return true;
        const Librodigitale* p = dynamic_cast<const Librodigitale*>(&a);
        return MediaItem::operator!=(a) || Libro::operator!=(a) || numeroPagine!=p->numeroPagine;
}
