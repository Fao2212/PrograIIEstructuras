#ifndef HEAP_H
#define HEAP_H
#include "includes.h"
struct Heap{

    Demonio * demonio;
    QString apellido;
    Pais * pais;
    int index;
    Persona * personas[200];

    Heap(QString apellido,Pais * pais,Demonio * demonio){
        this->pais = pais;
        this->apellido = apellido;
        this->demonio = demonio;
        this->index = 0;
        initArray();
    }

    void initArray();
    void add(Persona * persona);
    void ordenar();
    QString toString();
    Persona * eliminar(Persona * persona);
    Persona * buscarMenosPecador();
    int sumarPecados();
};

#endif // HEAP_H
