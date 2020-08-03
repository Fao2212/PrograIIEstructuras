#ifndef ARBOLANGELES_H
#define ARBOLANGELES_H
#include "includes.h"

struct ArbolAngeles{

    NodoAngeles * raiz;
    HashCielo * hash;
    Infierno  * infierno;

    ArbolAngeles(HashCielo * hash,Infierno * infierno){
        this->hash = hash;
        this->infierno = infierno;
        this->raiz = nullptr;
    }

    void nuevoNivel();
    void buscarHoja(NodoAngeles *);
    void llenarHijos(NodoAngeles * nodo);

};

#endif // ARBOLANGELES_H
