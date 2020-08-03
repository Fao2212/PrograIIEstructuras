#include "Persona.h"
#include "Familia.h"
#include "Acciones.h"

void Persona:: initPersona(int id){
    this->id = id;
    this->familia = new Familia(this);
    this->familiaAsignada = false;
    this->acciones = new Acciones(this);
    this->estado = VIVO;
    this->localizacion = MUNDO;
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

QString Persona::toString(){
    return QString::number(this->id)+" "+this->nombre+" "+this->apellido;
}

void Persona::sumarAccion(Comportamiento comportamiento, int cantidad){
    acciones->sumarAccion(comportamiento,cantidad);
}

void Persona::heredarPecados(Comportamiento comportamiento, int cantidad){
    familia->heredarPecados( comportamiento,  cantidad);
}

void Persona::sumarPecados(){
    acciones->sumarPecados();
}

void Persona::sumarBuenasAcciones(){
    acciones->sumarBuenasAcciones();
}

int Persona::getComportamiento(Comportamiento comportamiento){
    return acciones->getValue(comportamiento);
}

void Persona::morir(Demonio *demonio){
    this->demonio = demonio;
    this->estado = MUERTO;
    this->localizacion = INFIERNO;
    //Funcion de bitacora para infierno
}

void Persona::serSalvado(Angel *angel){
    this->angel = angel;
    this->localizacion = CIELO;
}

bool Persona::tieneMasBuenasAcciones(){
    return acciones->totalBuenasAcciones() > acciones->totalPecados();
}
