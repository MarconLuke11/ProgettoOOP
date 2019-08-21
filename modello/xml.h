#ifndef XML_H
#define XML_H

#include <QString>
#include "container.h"
#include "mediaitem.h"
#include "libro.h"
#include "film.h"
#include "musica.h"
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

class xml
{
private:
    QString filename;
public:
    xml(QString);
    Container<MediaItem*> read() const;
    void write(Container<MediaItem*>&) const;
};

#endif // XML_H
