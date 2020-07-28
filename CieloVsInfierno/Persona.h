#ifndef PERSONA_H
#define PERSONA_H
#include "includes.h"
struct Persona{

    int id;
    Pais * pais;
    QString apellido;
    QString nombre;
    Familia * familia;
    ArbolGenealogico * arbolGenealogico;
    bool familiaAsignada;

    Persona(int id){
        initPersona(id);
    }

    bool tienePadres();
    int tieneHijos();
    bool tieneFamilia();
    void initPersona(int id);
};

#endif // PERSONA_H
