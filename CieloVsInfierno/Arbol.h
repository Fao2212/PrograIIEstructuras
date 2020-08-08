#ifndef ARBOL_H
#define ARBOL_H
#include "includes.h"

struct Arbol
{
       NodoA * raiz;

       Arbol ()
       {
        raiz = nullptr;
       }

       void insertar (Nodo*);
       NodoA* insertar(Nodo*, NodoA*);
       void inOrden(NodoA*);//Meter a un switch
       void preOrden(NodoA*);
       void posOrden(NodoA*);
       NodoA* buscar (Nodo*, NodoA*);
       int obtenerNumeroElementos(NodoA*);
       int peso (NodoA*);
       int obtenerAltura(NodoA*);
       NodoA* mayor (NodoA* arbol);
       NodoA* borrarElemento(Nodo*);
       NodoA* borrarElemento(Nodo*, NodoA*);
       void anchura(NodoA*);
       int altura(NodoA*);
       int cantHojas(NodoA*);
       int cantNodos2(NodoA*);
       void nodos_nivel (NodoA*, int, int);
       int contadorNodos(NodoA*);
       void toStringProgra(NodoA*,QList<Persona *> * personas);
       void toStringHojas(NodoA*);


};

#endif // ARBOL_H
