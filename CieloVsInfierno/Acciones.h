#ifndef ACCIONES_H
#define ACCIONES_H
#include "includes.h"

struct Acciones{

    Persona * persona;
    Accion * pecados[7];
    Accion * buenasAcciones[7];
    Comportamiento enumValues[14] = {    ORGULLO,
                                         ENVIDIA,
                                         IRA,
                                         PEREZA,
                                         CODICIA,
                                         GULA,
                                         LUJURIA,
                                         HUMILDAD,
                                         SOLIDARIDAD,
                                         CALMA,
                                         DILIGENCIA,
                                         DONACION,
                                         AYUNO,
                                         CASTIDAD};
    Acciones(Persona * persona){
        this->persona = persona;
        initAcciones();
    }

    void initAcciones();
    Accion * getAccion(Comportamiento comportamiento);
    int getValue(Comportamiento comportamiento);
    void sumarAccion(Comportamiento comportamiento,int cantidad);
    int diferenciaIndividual(Comportamiento comportamiento);
    int diferenciaTotalBA();
    QString toString();
    int totalBuenasAcciones();
    int totalPecados();
    void sumarPecados();
    void sumarBuenasAcciones();
    QString static comportamientoName(Comportamiento comportamiento);
    int getIndexComportamiento(Comportamiento comportamiento);

};

#endif // ACCIONES_H
