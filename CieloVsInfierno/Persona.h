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
    Acciones * acciones;
    Estado estado;
    Localizacion localizacion;
    Demonio * demonio;
    Angel * angel;

    Persona(int id){
        initPersona(id);
    }

    bool tienePadres();
    int tieneHijos();
    bool tieneFamilia();
    void initPersona(int id);
    void sumarAccion(Comportamiento,int);
    void heredarPecados(Comportamiento,int cantidad);
    void sumarPecados();
    void sumarBuenasAcciones();
    int getComportamiento(Comportamiento comportamiento);
    void morir(Demonio * demonio);
    void serSalvado(Angel * angel);
    bool tieneMasBuenasAcciones();//if total 1 > total 2 return true


    QString toString();
    QString allData();
};

#endif // PERSONA_H
