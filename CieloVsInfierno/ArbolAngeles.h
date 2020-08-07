#ifndef ARBOLANGELES_H
#define ARBOLANGELES_H
#include "includes.h"

struct ArbolAngeles{

    NodoAngeles * raiz;
    HashCielo * hash;
    Infierno  * infierno;
    int generacion;
    QString nombresAngeles[10]{
                "Miguel",
                "Nuriel",
                "Aniel",
                "Rafael",
                "Gabriel",
                "Shamsiel",
                "Raguel",
                "Uriel",
                "Azrael",
                "Sariel"};

    ArbolAngeles(HashCielo * hash,Infierno * infierno){
        this->hash = hash;
        this->infierno = infierno;
        this->raiz = nullptr;
    }

    void nuevoNivel();
    void buscarHoja(NodoAngeles *);
    void llenarHijos(NodoAngeles * nodo);
    void generarNombres(QString nombres[]);

};

#endif // ARBOLANGELES_H
