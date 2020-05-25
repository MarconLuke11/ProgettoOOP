#ifndef XML_H
#define XML_H

#include <QString>
#include "container.h"
#include "mediaitem.h"
#include "fileaudio.h"
#include "libro.h"
#include "film.h"
#include "audiolibro.h"
#include "librodigitale.h"
#include "musica.h"
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

class xml
{
private:
    std::string filename;
public:
    xml(const std::string&);
    Container<MediaItem*> read() const;
    void write(Container<MediaItem*>&) const;
};

#endif // XML_H
