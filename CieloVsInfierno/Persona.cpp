#include "Persona.h"
#include "Familia.h"
#include "Pais.h"
#include "Acciones.h"
#include "Demonio.h"
#include "Angel.h"

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
    return QString::number(id)+"\t"+nombre+"\t"+apellido+"\t"+pais->nombre+"\t"+
            /*creencia+profesion+correo+horaDeNacimiento+*/acciones->toString()+
            "\t"+familia->toStringHijos();
}

void Persona::sumarAccion(Comportamiento comportamiento, int cantidad){
    sumarPecadosAPais(comportamiento,cantidad);
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
}

void Persona::serSalvado(Angel *angel){
    this->angel = angel;
    this->localizacion = CIELO;
}

bool Persona::tieneMasBuenasAcciones(){
    return acciones->totalBuenasAcciones() > acciones->totalPecados();
}

void Persona::sumarPecadosAPais(Comportamiento comportamiento,int pecados){
    if(acciones->getIndexComportamiento(comportamiento)<7)
        this->pais->sumarPecados(pecados);
    else
        this->pais->sumarBuenasAcciones(pecados);
}

QString Persona::toStringInfierno(){
    return QDateTime::currentDateTime().toString()+"\tHumano#\t"+QString::number(id)+"\t"+nombre+
            "\t"+apellido+"\t"+pais->nombre+"\t"+QDateTime::currentDateTime().toString()+
            "\t"+toStringComportamiento(demonio->pecado)+"\t"+QString::number(getComportamiento(demonio->pecado))+"\t"+
            toStringComportamiento(demonio->buenaAccion)+"\t"+QString::number(getComportamiento(demonio->buenaAccion))+"\t"+
            demonio->nombre;
}

QString Persona::toStringCielo(){
    return QDateTime::currentDateTime().toString()+"\tHumano#\t"+QString::number(id)+"\t"+nombre+
            "\t"+apellido+"\t"+pais->nombre+"\t"+QDateTime::currentDateTime().toString()+
            "\t"+"Pecados"+"\t"+QString::number(acciones->totalPecados())+"\t"+"Buenas Acciones"
            +"\t"+QString::number(acciones->totalBuenasAcciones())+"\t"+
            angel->toString();
}

QString Persona::toStringComportamiento(Comportamiento comportamiento){
    return acciones->comportamientoName(comportamiento);
}

QString Persona::toStringSimple(){
    return QString::number(id)+"\t"+nombre+"\t"+apellido;
}
