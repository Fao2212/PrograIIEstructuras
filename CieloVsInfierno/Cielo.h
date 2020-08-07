#ifndef CIELO_H
#define CIELO_H
#include "includes.h"

struct Cielo{

    HashCielo * hash;
    ArbolAngeles * angeles;
    Infierno * infierno;
    Comportamiento buenasAcciones[7]{
        HUMILDAD,
        SOLIDARIDAD,
        CALMA,
        DILIGENCIA,
        DONACION,
        AYUNO,
        CASTIDAD};

    Cielo(Infierno * infierno){
        initCielo(infierno);
    }

    void initCielo(Infierno * infierno);
    void salvacion();
    QString imprimirCielo();
    QString imprimirCantidadDeCadaBuenaAccion();
    int totalEnCielo();

};

#endif // CIELO_H
