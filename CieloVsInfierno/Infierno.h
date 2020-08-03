#ifndef INFIERNO_H
#define INFIERNO_H
#include "includes.h"

struct Infierno{

    Demonio * demonios[7];
    Mundo * mundo;
    QString nombresDeDemonios[7]{
        "Lucifer",
        "Belcebu",
        "Satan",
        "Abadon",
        "Mammon",
        "Belfegor",
        "Asmodeo"
    };
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
    Infierno(Mundo * mundo){
        this->mundo = mundo;
        initDemonios();
    }

    void initDemonios();
    int totalDePecados();
    Demonio * getDemonio(QString demonio);
    QString mostrarPecados();
    QString mostrarInfierno();
    QString estadisticaPecadosDeTodosLoshumanos();
    Persona * buscarBuenasAcciones();
    void enviarPorAlmas(QString demonio);
    void condenacion();

};

#endif // INFIERNO_H
