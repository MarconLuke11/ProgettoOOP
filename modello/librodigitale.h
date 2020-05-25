#ifndef DIGITALBOOK_H
#define DIGITALBOOK_H

#include "mediaitem.h"
#include "libro.h"

class Librodigitale : public Libro
{
private:
    unsigned int numeroPagine;
public:
    Librodigitale(string="Nessun titolo", string="Nessun genere", unsigned int=0, string="Nessun formato", unsigned int=1, string="Nessun autore", string="Nessuna casa editrice", unsigned int=0);
    string info() const override;
    unsigned int durataTOT() const override;

    unsigned int getPagine() const;

    void setPagine(const unsigned int&);

    virtual string getTipo() const override;

    virtual bool operator==(const MediaItem&) const override;
    virtual bool operator!=(const MediaItem&) const override;
};

#endif // DIGITALBOOK_H
