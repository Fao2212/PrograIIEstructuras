#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

struct FileManager{
    FileManager(){

    }
    static QString leer(QString path);
    static void escribir(QString path,QString string);
    static void reescribir(QString path,QString string);
    static QString moverArchivo(QString path, QString newPath);
    static QStringList directoryFileList(QString path);
    static void renameFile();//A implementar
    static void renameFileTimeStamp();//A implementar
    static QDir setDir();
};



#endif // FILEMANAGER_H
