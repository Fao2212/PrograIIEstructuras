#include "Cielo.h"
#include "HashCielo.h"
#include "ArbolAngeles.h"
#include "Log.h"
#include"Acciones.h"

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

QString Cielo::imprimirCielo(){
    Log::addToLog("Cielo");
    Log::addToLog(hash->toString());
    return "";
}

QString Cielo::imprimirCantidadDeCadaBuenaAccion(){
    QString msg = "";
    Log::addToLog("BuenasAccionesTotales:\t"+QString::number(totalEnCielo()));
    for (int i = 0;i<7;i++) {
        msg+=Acciones::comportamientoName(buenasAcciones[i])+"\t"+QString::number(hash->cantidadDeUnaBuenaAccion(buenasAcciones[i]))+"\t";
    }
    Log::addToLog(msg);
    return  msg;
}

int Cielo::totalEnCielo(){
    return hash->totalBuenasAcciones();
}
