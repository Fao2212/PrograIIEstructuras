#ifndef NODO_H
#define NODO_H
#include "includes.h"

struct Nodo
{
       Persona * dato;
       Nodo* anterior;
       Nodo* siguiente;

       Nodo (Persona * d)
       {
            dato = d;
            anterior = siguiente = nullptr;
       }
};
#endif // NODO_H
