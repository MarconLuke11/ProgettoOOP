#ifndef LIBRO_H
#define LIBRO_H

#include "mediaitem.h"

class Libro : virtual public MediaItem
{
private:
    string autore;
    string casaEditrice;
public:
    Libro(string="Nessun autore", string="Nessuna casa editrice");
    string info() const override;

    string getAutore() const;
    string getCasaEditrice() const;


    void setAutore(const string&);
    void setCasaEditrice(const string&);


    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // LIBRO_H
