#ifndef ANGEL_H
#define ANGEL_H
#include "includes.h"

struct Angel{

    HashCielo * hash;
    Infierno * infierno;
    Persona * salvado;
    QString nombre;
    int version;
    int generacion;

    Angel(HashCielo * hash,Infierno * infierno,QString nombre,int generacion){
        this->hash = hash;
        this->infierno = infierno;
        //Aasignacion de datos
        salvarPersona();
        this->nombre = nombre;
        this->generacion = generacion;
    }

    void salvarPersona();//Usa el algoritmo del infierno y este mismo borra de su heap a la apersona
    QString toString();

};

#endif // ANGEL_H
