 #ifndef FAMILIA_H
#define FAMILIA_H
#include "includes.h"
struct Familia{

    Persona * padre;
    Persona * hijos[5];
    Persona * persona;

    Familia(Persona * persona){
        this->persona = persona;
        this->padre = nullptr;
        for (int i = 0;i<5;i++) {hijos[i] = nullptr;}
    }

    void agregarHijos(Persona * hijos[]);
    void agregarPadre(Persona * padre);
    Persona * buscarCabezaDeFamilia(Persona * persona);//Busca recursivamente hasta encontrar el nulo
    QString imprimirFamilia();//Busca la cabeza e imprime recursivamente
    QString imprimirFamilia(Persona * persona,QString datos);

};

#endif // FAMILIA_H
