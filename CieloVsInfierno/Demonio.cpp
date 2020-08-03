#include "Demonio.h"
#include "Mundo.h"
#include "ListaDoble.h"
#include "Persona.h"
#include "Heap.h"
#include "Pais.h"

void Demonio::initHash(){
    this->familias = new QHash<QString,Heap *>();
}

void Demonio::cosecharPecados(){
    qDebug()<<"Inicia busqueda del demonio "+nombre;
    int largo = mundo->poblacion->largo();
    Persona * personas[largo];
    mundo->poblacion->ordenarPorPecado(personas,pecado);
    int condenados = 0;
    int totalCondenados = mundo->vivos*PORCENTAJEDECONDENADOS;
    qDebug()<<"Condenados"<<totalCondenados;
    int i = 0;
    while (condenados < totalCondenados && i<largo) {
        Persona * persona = personas[i];
        if(persona->estado == VIVO){
            Heap * infierno = buscarEnInfierno(persona);
            persona->morir(this);
            infierno->add(persona);
            mundo->vivos = mundo->vivos-1;
            condenados++;
        }
        i++;
    }
    qDebug()<<"Termina busqueda del demonio";
}

Heap * Demonio::buscarEnInfierno(Persona * persona){
    QString key = getKey(persona);
    Heap * heap = familias->value(key);
    if(heap == nullptr){//Se inicializa con constructor por defecto probar con pais = null
        heap = crearEspacioEnInfierno(persona);
    }
    return  heap;
}

Heap * Demonio::crearEspacioEnInfierno(Persona * persona){
    Heap * heap = new Heap(persona->apellido,persona->pais,this);
    familias->insert(getKey(persona),heap);
    return heap;
}

QString Demonio::getKey(Persona *persona){
    QString apellido = persona->apellido;
    QString nombrepais = persona->pais->nombre;
    return apellido+nombrepais;
}

