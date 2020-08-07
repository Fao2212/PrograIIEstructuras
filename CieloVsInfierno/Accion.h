#ifndef ACCION_H
#define ACCION_H
#include "includes.h"

struct Accion{
    int valor;
    Comportamiento comportamiento;
    int index;

    Accion(Comportamiento comportamiento,int index){
        this->comportamiento = comportamiento;
        this->valor = 0;
        this->index = index;
    }

    void aumentarValor(int cantidad);
    QString toString();
};

#endif // ACCION_H
