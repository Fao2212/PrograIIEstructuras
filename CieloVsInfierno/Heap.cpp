#include "Heap.h"
#include "Persona.h"

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
        personas[pos] = personas[index];
        personas[index] = nullptr;
        index--;
        return borrado;
    }
    else{
        return nullptr;
    }
}
