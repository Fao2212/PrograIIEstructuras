#ifndef ANGEL_H
#define ANGEL_H
#include "includes.h"

struct Angel{

    HashCielo * hash;
    Infierno * infierno;
    Persona * salvado;

    Angel(HashCielo * hash,Infierno * infierno){
        this->hash = hash;
        this->infierno = infierno;
        //Aasignacion de datos
        salvarPersona();
    }

    void salvarPersona();//Usa el algoritmo del infierno y este mismo borra de su heap a la apersona
    QString toString();

};

#endif // ANGEL_H
