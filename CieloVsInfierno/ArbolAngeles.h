#ifndef ARBOLANGELES_H
#define ARBOLANGELES_H
#include "includes.h"

struct ArbolAngeles{

    int nivel;
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
        this->nivel = 0;
        this->infierno = infierno;
        this->raiz = nullptr;
    }

    void nuevoNivel();
    void buscarHoja(NodoAngeles *);
    void llenarHijos(NodoAngeles * nodo);
    void generarNombres(QString nombres[]);
    QString randomName();

};

#endif // ARBOLANGELES_H
