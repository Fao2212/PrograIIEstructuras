#ifndef UTIL_H
#define UTIL_H
#include "includes.h"

struct Util{
    static void ordenarPorPecadoMayorAMenor(Persona **personas, Comportamiento comportamiento,int length);
    static void ordenarPorPecadoMernosAMayor(Persona **personas, Comportamiento comportamiento,int length);
    static void ordenarPorTotalMayorMenor(Persona ** personas);
    static void ordenarPorTotalMenorMayor(Persona ** personas);
};

#endif // UTIL_H
