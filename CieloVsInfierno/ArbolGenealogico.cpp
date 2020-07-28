#include "ArbolGenealogico.h"
#include "ListaDoble.h"
#include "Nodo.h"
#include "Persona.h"
//Cuando se inicia el proceso de asignacion de fmilias los heaps de la lista se les hace
//un shuffle y luego con cada asignacion se marca como no dsponible y se envia a el final de la lista.
void ArbolGenealogico::initArbolGenealogico(QString nombre, Pais *pais){
    this->heap = new ListaDoble();
    this->pais = pais;
    this->familia = nombre;
}

Persona * ArbolGenealogico::buscarDisponible(Persona * persona){
    Nodo * temp = heap->primerNodo;
    Persona * p = temp->dato;
    if(p != persona)
        if(!p->familiaAsignada ){
            heap->enviarAlFinal();
            p->familiaAsignada = true;
            return p;
        }
        return nullptr;
    }


