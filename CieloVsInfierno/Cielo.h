#ifndef CIELO_H
#define CIELO_H
#include "includes.h"

struct Cielo{

    HashCielo * hash;
    ArbolAngeles * angeles;
    Infierno * infierno;

    Cielo(Infierno * infierno){
        initCielo(infierno);
    }

    void initCielo(Infierno * infierno);
    void salvacion();


};

#endif // CIELO_H
