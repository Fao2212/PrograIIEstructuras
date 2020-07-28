#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "includes.h"
struct ListaSimple{

    NodoAG * primerNodo;

    ArbolGenealogico * buscar(Persona *);
    void insertar(ArbolGenealogico * ag);
    void insertar(NodoAG * );

};

#endif // LISTASIMPLE_H
