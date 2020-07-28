#ifndef ARBOLMUNDO_H
#define ARBOLMUNDO_H
#include "includes.h"

struct ArbolMundo{

    Arbol * arbol;

    ArbolMundo(ListaDoble * lista){
        crearArbol(lista);
    }

    void crearArbol(ListaDoble * lista);
    int numeroDeNodos(int unoPorciento);//Usa el 1% y ajusta a la base dos mas proxima
    Persona * buscarEnArbol(int id);//Revisa los nodos
    Persona * buscarEnArbol(int id,NodoA * nodo,NodoA* inicio,NodoA * final);
    Persona * recorrido(NodoA* inicio,NodoA * final,int id);
    Persona * recorrerALaDerecha(NodoA* inicio,NodoA * final,int id);
    Persona * recorrerALaIzquierda(NodoA* inicio,NodoA * final,int id);//encunetra el nodo o es el final
    Nodo * recorrido(Nodo * inicio,int pos);
};

#endif // ARBOLMUNDO_H
