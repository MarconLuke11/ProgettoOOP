#ifndef LIBRO_H
#define LIBRO_H

#include "mediaitem.h"

class Libro : public MediaItem
{
private:
    string autore;
    string casaEditrice;
    unsigned int numeroPagine;
public:
    Libro(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun autore", string="Nessuna casa editrice", unsigned int=0);
    virtual Libro* clone() const override;
    string info() const override;
    unsigned int durataTOT() const override;

    string getAutore() const;
    string getCasaEditrice() const;
    unsigned int getPagine() const;

    void setAutore(const string&);
    void setCasaEditrice(const string&);
    void setPagine(const unsigned int&);

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // LIBRO_H
