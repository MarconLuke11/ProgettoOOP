#include "xml.h"

xml::xml(QString filepath) : filename(filepath) {}

Container<MediaItem *> xml::read() const
{
    Container<MediaItem*> list;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Errore nell'apertura del file" << file.errorString();
        return  list;
    }

    // Lettura da file XML
    QXmlStreamReader reader(&file);

    if(reader.readNextStartElement()) {
        if(reader.name() == "root") {
            while(reader.readNextStartElement()) {
                if(reader.name() == "MediaItem") {
                    const QXmlStreamAttributes attributes = reader.attributes();
                    const QString type = attributes.hasAttribute("type") ? attributes.value("type").toString() : "";

                    if(type == "libro"){
                        Libro* x = new Libro();
                        list.push_back(x);
                        while(reader.readNextStartElement()){
                            if(reader.name() == "titolo"){
                                const QString textValue = reader.readElementText();
                                x->setTitolo(textValue.toStdString());

                                qDebug() << "Letto " + type + ": " + textValue;
                            }
                            if(reader.name() == "genere"){
                                const QString textValue = reader.readElementText();
                                x->setGenere(textValue.toStdString());
                            }
                            if(reader.name() == "annoDistribuzione"){
                                const QString textValue = reader.readElementText();
                                x->setAnno(textValue.toUInt());
                            }
                            if(reader.name() == "formato"){
                                const QString textValue = reader.readElementText();
                                x->setFormato(textValue.toStdString());
                            }
                            if(reader.name() == "recensione"){
                                const QString textValue = reader.readElementText();
                                x->setRecensione(textValue.toUInt());
                            }
                            if(reader.name() == "autore"){
                                const QString textValue = reader.readElementText();
                                x->setAutore(textValue.toStdString());
                            }
                            if(reader.name() == "casaEditrice"){
                                const QString textValue = reader.readElementText();
                                x->setCasaEditrice(textValue.toStdString());
                            }
                            if(reader.name() == "numeroPagine"){
                                const QString textValue = reader.readElementText();
                                x->setPagine(textValue.toUInt());
                            }
                        }
                    }

                    if(type == "film"){
                        Film* x = new Film();
                        list.push_back(x);
                        while(reader.readNextStartElement()){
                            if(reader.name() == "titolo"){
                                const QString textValue = reader.readElementText();
                                x->setTitolo(textValue.toStdString());

                                qDebug() << "Letto " + type + ": " + textValue;
                            }
                            if(reader.name() == "genere"){
                                const QString textValue = reader.readElementText();
                                x->setGenere(textValue.toStdString());
                            }
                            if(reader.name() == "annoDistribuzione"){
                                const QString textValue = reader.readElementText();
                                x->setAnno(textValue.toUInt());
                            }
                            if(reader.name() == "formato"){
                                const QString textValue = reader.readElementText();
                                x->setFormato(textValue.toStdString());
                            }
                            if(reader.name() == "recensione"){
                                const QString textValue = reader.readElementText();
                                x->setRecensione(textValue.toUInt());
                            }
                            if(reader.name() == "regista"){
                                const QString textValue = reader.readElementText();
                                x->setRegista(textValue.toStdString());
                            }
                            if(reader.name() == "durata"){
                                const QString textValue = reader.readElementText();
                                x->setDurata(textValue.toUInt());
                            }
                        }
                    }

                    if(type == "musica"){
                        Musica* x = new Musica();
                        list.push_back(x);
                        while(reader.readNextStartElement()){
                            if(reader.name() == "titolo"){
                                const QString textValue = reader.readElementText();
                                x->setTitolo(textValue.toStdString());

                                qDebug() << "Letto " + type + ": " + textValue;
                            }
                            if(reader.name() == "genere"){
                                const QString textValue = reader.readElementText();
                                x->setGenere(textValue.toStdString());
                            }
                            if(reader.name() == "annoDistribuzione"){
                                const QString textValue = reader.readElementText();
                                x->setAnno(textValue.toUInt());
                            }
                            if(reader.name() == "formato"){
                                const QString textValue = reader.readElementText();
                                x->setFormato(textValue.toStdString());
                            }
                            if(reader.name() == "recensione"){
                                const QString textValue = reader.readElementText();
                                x->setRecensione(textValue.toUInt());
                            }
                            if(reader.name() == "artista"){
                                const QString textValue = reader.readElementText();
                                x->setArtista(textValue.toStdString());
                            }
                            if(reader.name() == "numeroTracce"){
                                const QString textValue = reader.readElementText();
                                x->setNumeroTracce(textValue.toUInt());
                            }
                            if(reader.name() == "durata"){
                                const QString textValue = reader.readElementText();
                                x->setDurata(textValue.toUInt());
                            }

                        }
                    }



                }
            }
        }
        else
            reader.skipCurrentElement();
    }
    file.close();
    return list;
}

void xml::write(Container<MediaItem *> & lista) const
{
    QSaveFile file(filename);
    if(!file.open(QIODevice::WriteOnly)) {
        throw std::exception();
    }

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");

    writer.writeStartElement("root");

    Container<MediaItem*>::iteratore it = lista.begin();

    while(it != lista.end()) {
        writer.writeStartElement("MediaItem");

        MediaItem* media = *it;
        std::string type;
        if(dynamic_cast<Libro*>(media))
            type = "libro";
        if(dynamic_cast<Film*>(media))
            type = "film";
        if(dynamic_cast<Musica*>(media))
            type = "musica";


        writer.writeAttribute("type", QString::fromStdString(type));

        writer.writeStartElement("titolo");
        writer.writeCharacters(QString::fromStdString(media->getTitolo()));
        writer.writeEndElement();

        writer.writeStartElement("genere");
        writer.writeCharacters(QString::fromStdString(media->getGenere()));
        writer.writeEndElement();

        writer.writeStartElement("annoDistribuzione");
        writer.writeCharacters(QString::number(media->getAnno()));
        writer.writeEndElement();

        writer.writeStartElement("formato");
        writer.writeCharacters(QString::fromStdString(media->getFormato()));
        writer.writeEndElement();

        writer.writeStartElement("recensione");
        writer.writeCharacters(QString::number(media->getRecensione()));
        writer.writeEndElement();

        if(dynamic_cast<Libro*>(media)){
            Libro* libro = static_cast<Libro*>(media);

            writer.writeStartElement("autore");
            writer.writeCharacters(QString::fromStdString((libro->getAutore())));
            writer.writeEndElement();

            writer.writeStartElement("casaEditrice");
            writer.writeCharacters(QString::fromStdString(libro->getCasaEditrice()));
            writer.writeEndElement();

            writer.writeStartElement("numeroPagine");
            writer.writeCharacters(QString::number(libro->getPagine()));
            writer.writeEndElement();
        }

        if(dynamic_cast<Film*>(media)){
            Film* film = static_cast<Film*>(media);

            writer.writeStartElement("regista");
            writer.writeCharacters(QString::fromStdString(film->getRegista()));
            writer.writeEndElement();

            writer.writeStartElement("durata");
            writer.writeCharacters(QString::number(film->getDurata()));
            writer.writeEndElement();
        }

        if(dynamic_cast<Musica*>(media)){
            Musica* musica = static_cast<Musica*>(media);

            writer.writeStartElement("artista");
            writer.writeCharacters(QString::fromStdString(musica->getArtista()));
            writer.writeEndElement();

            writer.writeStartElement("numeroTracce");
            writer.writeCharacters(QString::number(musica->getNumeroTracce()));
            writer.writeEndElement();

            writer.writeStartElement("durata");
            writer.writeCharacters(QString::number(musica->getDurata()));
            writer.writeEndElement();
        }

        writer.writeEndElement();

        if (writer.hasError())
            throw std::exception();

        it++;
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    file.commit();
}
