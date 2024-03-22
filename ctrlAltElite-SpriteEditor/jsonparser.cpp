/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor


File: jsonparser.cpp
    Description: This file is meant to encapsulate the json functionality within our application

Reviewed by: Ashlyn Hansen
*/

#include "jsonparser.h"
#include <QFileDialog>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include "spriteframe.h"


// this class parses json from a file and creates a Sprite Object.
JsonParser::JsonParser(QObject *parent)
    : QObject{parent}
{
}

Sprite JsonParser::parseJson(QString fileName) {
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open the Json File";
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if(parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << parseError.errorString();
    }

    if(jsonDoc.isNull() || jsonDoc.isEmpty() || !jsonDoc.isObject()) {
        qWarning() << "JSON document is not valid.";
    }


    QJsonObject jsonObject = jsonDoc.object();

    QString jsonFileName = jsonObject["file_name"].toString();
    int spriteWidth = jsonObject["sprite_width"].toInt();
    int spriteHeight = jsonObject["sprite_height"].toInt();

    QJsonArray jsonFrameArray = jsonObject["file_frames"].toArray();

    std::vector<SpriteFrame> spriteFrames;

    for(const QJsonValue &frame: jsonFrameArray) {
        if(frame.isObject()) {
            QJsonObject frameObj = frame.toObject();
            QString frameName = frameObj.keys().at(0);
            QJsonArray imgArray = frameObj.value(frameName).toArray();

            SpriteFrame sf(spriteWidth, spriteHeight);

            for(const QJsonValue &imgValue: imgArray ) {
                QJsonObject imgObj = imgValue.toObject();
                int red = imgObj["red"].toInt();
                int green = imgObj["green"].toInt();
                int blue = imgObj["blue"].toInt();
                int alpha = imgObj["alpha"].toInt();

                sf.addPixel(red, green, blue, alpha);
            }
            spriteFrames.push_back(sf);
        }
    }

    return Sprite(jsonFileName, spriteWidth, spriteHeight, spriteFrames);
}


bool JsonParser::saveFileFromQImages(const vector<QImage*> frames, QString fileName) {

    QJsonObject jsonObject;

    jsonObject["file_name"] = fileName;
    jsonObject["sprite_width"] = frames[0]->width();
    jsonObject["sprite_height"] = frames[0]->height();
    jsonObject["frame_count"] = static_cast<int>(frames.size());

    QJsonArray fileFrames;

    int index = 0;
    for(auto framePtr: frames) {
        QJsonObject frameJson = jsonObjectFromQImage( framePtr, index);
        fileFrames.append(frameJson);
        index++;
    }

    jsonObject["file_frames"] = fileFrames;

    QJsonDocument spriteJson(jsonObject);

    return saveJsonFile(spriteJson, fileName);
}


QJsonObject JsonParser::jsonObjectFromQImage(const QImage* framePtr, int frameNumber) {
    QImage frame = *framePtr;
    QJsonObject img;

    QJsonArray imgPixels;
    for(int i = 0; i < frame.height(); i++) {
        for(int j = 0; j < frame.width(); j++) {

            QColor pixelColor = frame.pixelColor(i, j);

            QJsonObject pixelData;

            pixelData["red"] = pixelColor.red();
            pixelData["blue"]= pixelColor.blue();
            pixelData["green"]= pixelColor.green();
            pixelData["alpha"] = pixelColor.alpha();

            imgPixels.append(pixelData);
        }
    }

    string fileName = "img" + std::to_string(frameNumber);

    img[QString::fromStdString(fileName)] = imgPixels;
    return img;
}

bool JsonParser::saveJsonFile(QJsonDocument doc, QString fileName){
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        file.write(doc.toJson());
        file.close();
        return true;
    }
    else{
        return false;
    }
}
