#include "Cielo.h"
#include "HashCielo.h"
#include "ArbolAngeles.h"
#include "Log.h"

void Cielo::initCielo(Infierno * infierno){
    this->hash = new HashCielo();
    this->infierno = infierno;
    this->angeles = new ArbolAngeles(hash,infierno);

}

void Cielo::salvacion(){
    qDebug()<<"Comienza Salvacion";
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-ddhh-mm-ss");
    Log::createlog("Salvacion"+time);
    this->angeles->nuevoNivel();
    Log::saveLog();
    qDebug()<<"Termina salvacion";
}
