#include "mediaitem.h"
#include <strings.h>

MediaItem::MediaItem(string tit, string gen, unsigned int anno, string form, unsigned int rec):
    titolo(tit), genere(gen), annoDistribuzione(anno), formato(form), recensione(rec) {}

std::ostream& operator<<(std::ostream& output, const MediaItem& m){
    output << m.info() << std::endl;
    return output;
}

string MediaItem::info() const{
    string stream;
    std::stringstream value;
    value << std::fixed << std::setprecision(4) << annoDistribuzione;
    std::stringstream value2;
    value2 << std::fixed << std::setprecision(1) << recensione;
    stream = "Titolo: " + titolo + "\nGenere: " + genere + "\nAnno di distribuzione: " + value.str() + "\nFormato: " + formato + "\nRecensione: " + value2.str();
    return stream;
}

string MediaItem::getTitolo() const
{
    return titolo;
}

string MediaItem::getGenere() const
{
    return genere;
}

unsigned int MediaItem::getAnno() const
{
    return annoDistribuzione;
}

string MediaItem::getFormato() const
{
    return formato;
}

unsigned int MediaItem::getRecensione()
{
    return recensione;
}

void MediaItem::setTitolo(const string& tit)
{
    titolo=tit;
}

void MediaItem::setGenere(const string& gen)
{
    genere=gen;
}

void MediaItem::setAnno(const unsigned int& anno)
{
    annoDistribuzione=anno;
}

void MediaItem::setFormato(const string& form)
{
    formato=form;
}

void MediaItem::setRecensione(const unsigned int& rec)
{
    recensione=rec;
}

bool MediaItem::operator==(const MediaItem& m) const
{
    return titolo==m.titolo && genere==m.genere && annoDistribuzione==m.annoDistribuzione && formato==m.formato && recensione==m.recensione;
}

bool MediaItem::operator!=(const MediaItem& m) const
{
    return titolo!=m.titolo || genere!=m.genere || annoDistribuzione!=m.annoDistribuzione || formato!=m.formato || recensione!=m.recensione;
}

bool MediaItem::operator<(const MediaItem& m)
{
    const char *strtit1 = titolo.c_str();
    const char *strtit2 = m.titolo.c_str();
    if(strcasecmp(strtit1,strtit2) < 0)
        return true;
    else
        return false;
}

