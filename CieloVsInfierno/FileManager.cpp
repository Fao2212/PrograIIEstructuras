#include "FileManager.h"//Reescribir reemlplaza todo el contenido del archivo por el nuevo
//Escribir agrega una linea de texto

#include <QDebug>

QString FileManager :: leer(QString path){
    QFile file(path);
    QString str = "";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Archivo nuevo creado";

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        str += line;
    }
    return str;
}

void FileManager :: escribir(QString path, QString string){//Se puede cambiar a que retorne el nuevo nombre
    QString output = leer(path);
    QFile file(path);
    output += "\n"+string;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << output;
}

void FileManager :: reescribir(QString path, QString string){
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"error";

    QTextStream out(&file);
    out << string;
}

QStringList FileManager :: directoryFileList(QString path){
    QDir directory(path);//Validar que exista el directorio
    return directory.entryList(QStringList() << "*.txt" << "*.TXT",QDir::Files);
}

QString FileManager :: moverArchivo(QString path, QString newPath){//Poner el archivo y la direccion de la carpeta
    QFile file(path);
    QFileInfo fileInfo(file.fileName());
    QString filename(fileInfo.fileName());
    file.rename(newPath+"/"+filename);
    return (newPath+"/"+filename);
}

QDir FileManager :: setDir(){
    QDir direccion = QDir::currentPath();
    qDebug()<<direccion;
    direccion.cdUp();
    qDebug()<<direccion;
    return direccion;
}
