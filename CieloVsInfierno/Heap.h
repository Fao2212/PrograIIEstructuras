#ifndef HEAP_H
#define HEAP_H
#include "includes.h"
struct Heap{

    ListaDoble * asdasd;

    Heap(){

    }

    void insertarEnHeap(Persona * dato);//Asegurarse que el mayor siempre esta en el tope usando el arbol
    void eliminarEnHeap();//Solo elimina la raiz. Esto puede que no se utilize
    Nodo * buscarEnHeap(Persona * dato);

};

#endif // HEAP_H
