/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: jsonparser.h
    Description: This file is meant to encapsulate the json functionality within our application

Reviewed by:
*/

#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include <sprite.h>

class JsonParser : public QObject
{
    Q_OBJECT
public:

    explicit JsonParser(QObject *parent = nullptr);

    /// \brief JsonParser::parseJson-> parses json from a given .ssh or .json from
    /// \param fileName-> file that the json will be parsed from
    /// \return Sprite object-> a sprite of
    Sprite static parseJson(QString fileName);

    /// \brief JsonParser::saveFileFromQImages-> static method that saves a file given a vector of QImage pointers
    /// \param frames-> list of the QImage pointers
    /// \param fileName-> what the name of the saved file should be
    /// \return bool-> this returns a true or false value if the file was successfully saved to the file system
    bool static saveFileFromQImages(const vector<QImage*> frames, QString fileName);
private:

    /// \brief JsonParser::jsonObjectFromQImage-> private method that converts a single QImage pointer to a QJsonObject
    /// \param framePtr-> image that will be parsed
    /// \param frameNumber-> index
    /// \return QJsonObject -> this will be added to the saved file as an object
    QJsonObject static jsonObjectFromQImage(const QImage* framePtr, int imageIndex);

    ///
    /// \brief saveJsonFile -> saves a json file to the file system
    /// \param doc -> all of the json code added to a document.
    /// \param fileName -> fileName of the doc that will be saved to the computer
    /// \return bool -> returns a true/false based if file was successfully saved to the file system
    ///
    bool static saveJsonFile(QJsonDocument doc, QString fileName);

signals:
    /// \brief jsonParsingError this error will be emitted if there were any issues parsing the file
    /// \param details about the error saving the file to the server
    void jsonParsingError(QString error);
};

#endif // JSONPARSER_H
