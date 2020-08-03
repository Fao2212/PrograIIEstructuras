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
    QString imprimirFamilia();
    Persona ** getFamilia();
    Persona ** getFamilia(Persona * persona,Persona ** datos,int * index);
    void imprimirHijos(Persona * p);
    void heredarPecados(Comportamiento,int);
    void heredarPecados(Comportamiento,int,Persona*,int index);

};

#endif // FAMILIA_H
