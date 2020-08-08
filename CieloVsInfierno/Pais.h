#ifndef PAIS_H
#define PAIS_H
#include "includes.h"
struct Pais{

    Pais(){

    }

    Pais(QString nombre,int pos){
        this->nombre = nombre;
        obtenerContinente(pos);
        this->pecados = 0;
    }

    QString continente;
    QString nombre;
    int pecados;//...
    int buenasAcciones;

    void obtenerContinente(int pos);
    void sumarPecados(int pecados);
    void sumarBuenasAcciones(int buenasAcciones);

};

#endif // PAIS_H
