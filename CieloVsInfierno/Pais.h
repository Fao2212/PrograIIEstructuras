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

    void obtenerContinente(int pos);
    void sumarPecados(int pecados);

};

#endif // PAIS_H
