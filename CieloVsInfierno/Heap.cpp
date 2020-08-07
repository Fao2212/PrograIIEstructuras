#include "Heap.h"
#include "Persona.h"
#include "Acciones.h"

void Heap::initArray(){
    for (int i = 0;i<200;i++) {
        personas[i] = nullptr;
    }
}

void Heap::add(Persona *persona){
    personas[index++] = persona;
}

Persona * Heap::buscarMenosPecador(){
    for (int i = 0;i<index;i++) {
        if(personas[i]->tieneMasBuenasAcciones()){
            return eliminar(personas[i]);
        }
    }
    return nullptr;
}

Persona * Heap::eliminar(Persona * borrado){
    int pos = -1;
    for (int i = 0;i<index;i++) {
        if(personas[i] == borrado){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        personas[pos] = personas[index-1];
        personas[index-1] = nullptr;
        index--;
        return borrado;
    }
    else{
        return nullptr;
    }
}

QString Heap::toString(){
    QString msg = "";
    for (int i = 0;i<index;i++) {
        msg+=personas[i]->toString()+"\n";
    }
    return msg;
}

int Heap::sumarPecados(){
    int res = 0;
    for (int i = 0;i<index;i++) {
        res+=personas[i]->acciones->totalPecados();
    }
    return res;
}
//Hacer un bubble sort para reordenar el array al eliminar
