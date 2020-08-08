#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "includes.h"
struct ListaSimple{

    NodoAG * primerNodo;

    ArbolGenealogico * buscar(Persona *);
    void insertar(ArbolGenealogico * ag);
    void insertar(NodoAG * );
    ArbolGenealogico * buscar(QString apellido,QString pais);

};

#endif // LISTASIMPLE_H
