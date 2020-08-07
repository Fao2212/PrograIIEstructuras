#ifndef DEMONIO_H
#define DEMONIO_H
#include "includes.h"

struct Demonio{

    QString nombre;
    Comportamiento pecado;
    Comportamiento buenaAccion;
    QHash<QString,Heap *> * familias;
    Mundo * mundo;
    double PORCENTAJEDECONDENADOS = 0.05;

    Demonio(QString nombre,Comportamiento pecado,Mundo * mundo,Comportamiento buenaAccion){
        this->nombre = nombre;
        this->pecado = pecado;
        this->mundo = mundo;
        this->buenaAccion = buenaAccion;
        initHash();
    }

    void initHash();
    void cosecharPecados();
    Heap * crearEspacioEnInfierno(Persona *);
    Heap * buscarEnInfierno(Persona *);
    QString getKey(Persona *);
    QString toString();
    int sumarPecados();
    QString imprimirInfierno();
    QString toStringPecado();


};

#endif // DEMONIO_H
