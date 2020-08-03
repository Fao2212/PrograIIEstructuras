#include "ArbolAngeles.h"
#include "NodoAngeles.h"
#include "Angel.h"

void ArbolAngeles::buscarHoja(NodoAngeles * nodo){
    if(nodo->hijoIzquierdo == nullptr)
        llenarHijos(nodo);
    else{
        buscarHoja(nodo->hijoIzquierdo);
        buscarHoja(nodo->hijoMedio);
        buscarHoja(nodo->hijoDerecho);
    }
}

void ArbolAngeles::nuevoNivel(){
    if(raiz == nullptr)
        this->raiz = new NodoAngeles(new Angel(hash,infierno));
    else
        buscarHoja(raiz);
}

void ArbolAngeles::llenarHijos(NodoAngeles * nodo){

    nodo->hijoIzquierdo = new NodoAngeles(new Angel(hash,infierno));
    nodo->hijoMedio = new NodoAngeles(new Angel(hash,infierno));
    nodo->hijoDerecho = new NodoAngeles(new Angel(hash,infierno));

}
