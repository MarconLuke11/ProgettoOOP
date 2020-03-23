#ifndef LIBRO_H
#define LIBRO_H

#include "mediaitem.h"

class Libro : public MediaItem
{
private:
    string autore;
    string casaEditrice;
public:
    Libro(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun autore", string="Nessuna casa editrice");
    string info() const override;
    virtual unsigned int durataTOT() const=0;

    string getAutore() const;
    string getCasaEditrice() const;


    void setAutore(const string&);
    void setCasaEditrice(const string&);


    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // LIBRO_H
