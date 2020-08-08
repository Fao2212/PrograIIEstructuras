#include "ArbolAngeles.h"
#include "NodoAngeles.h"
#include "Angel.h"
#include "Random.h"

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
    if(raiz == nullptr){
        qDebug()<<"Raiz creada";
        this->raiz = new NodoAngeles(new Angel(hash,infierno,randomName(),nivel));
    }
    else
        buscarHoja(raiz);
    nivel++;
}

void ArbolAngeles::llenarHijos(NodoAngeles * nodo){

    nodo->hijoIzquierdo = new NodoAngeles(new Angel(hash,infierno,randomName(),nivel));
    nodo->hijoMedio = new NodoAngeles(new Angel(hash,infierno,randomName(),nivel));
    nodo->hijoDerecho = new NodoAngeles(new Angel(hash,infierno,randomName(),nivel));

}

void ArbolAngeles::generarNombres(QString nombres[]){
    for (int i = 0;i<nombres->length();i++) {
        nombres[i] = nombresAngeles[Random::RandomRange(0,9)];
    }
}

QString ArbolAngeles::randomName(){
    return nombresAngeles[Random::RandomRange(0,9)];
}
