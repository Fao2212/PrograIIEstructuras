#include "Persona.h"
#include "Familia.h"

void Persona:: initPersona(int id){
    this->id = id;
    this->familia = new Familia(this);
    this->familiaAsignada = false;
}

int Persona::tieneHijos(){
    int cont = 0;
    for (int i = 0;i <5;i++) {
        if(familia->hijos[i] != nullptr){
            cont++;
        }
    }
    return cont;
}

bool Persona::tienePadres(){
    return  familia->padre != nullptr;
}

bool Persona::tieneFamilia(){
    return  (tienePadres() || tieneHijos() != 0 );
}

