#include "Familia.h"
#include "Persona.h"


void Familia::agregarHijos(Persona **hijos){
    for (int i = 0;i<5;i++) {
        this->hijos[i] = hijos[i];
    }
}

void Familia::agregarPadre(Persona *padre){
    this->padre = padre;
}


Persona * Familia::buscarCabezaDeFamilia(Persona * p){
    if(p->familia->padre != nullptr){
        return buscarCabezaDeFamilia(p->familia->padre);
    }
    return p;
}


QString Familia::imprimirFamilia(){
    Persona ** xd = getFamilia();
    QString msg = "";
    for (int i=0;i<50;i++) {
        if(xd[i]!= nullptr){
            msg+=xd[i]->toString();
        }
    }
    return msg;
}

Persona ** Familia::getFamilia(){
    static Persona * familia[50];
    Persona * primero = buscarCabezaDeFamilia(persona);
    int x = 0;
    int * index = &x;
    for (int i = 0;i < 50;i++) {
        familia[i] = nullptr;
    }
    getFamilia(primero,familia,index);
    return familia;
}

Persona ** Familia::getFamilia(Persona *p,Persona ** datos,int * index){
    if(p != nullptr){
        datos[(*index)++] = p;
    }
    if(p == nullptr){
        return datos;
    }
        for (int i = 0;i < 5;i++) {
            Persona * hijo = p->familia->hijos[i];
            getFamilia(hijo,datos,index);
        }
}

void Familia::heredarPecados(Comportamiento comportamiento, int cantidad){
    int index = 0;
    heredarPecados(comportamiento,cantidad,persona,index);
}

void Familia::heredarPecados(Comportamiento comportamiento, int cantidad, Persona * p, int index){
    if(p == nullptr || index == 3)
        return ;
    if(index == 0)
        p->sumarAccion(comportamiento,cantidad);
    else if(index == 1)
        p->sumarAccion(comportamiento,cantidad/2);
    else if(index == 2)
        p->sumarAccion(comportamiento,cantidad/4);
    index++;
    for (int i = 0;i<5;i++) {
        Persona * hijo = p->familia->hijos[i];
        heredarPecados(comportamiento,cantidad,hijo,index);
    }
}
