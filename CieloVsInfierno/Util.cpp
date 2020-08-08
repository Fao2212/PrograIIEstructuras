#include "Util.h"
#include "Persona.h"
#include "Acciones.h"

void Util::ordenarPorPecadoMayorAMenor(Persona **personas, Comportamiento comportamiento,int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->getComportamiento(comportamiento) > personas[i]->getComportamiento(comportamiento)){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void Util::ordenarPorPecadoMernosAMayor(Persona **personas, Comportamiento comportamiento,int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->getComportamiento(comportamiento) < personas[i]->getComportamiento(comportamiento)){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void Util::ordenarPorTotalMayorMenor(Persona **personas,int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->acciones->totalPecados() > personas[i]->acciones->totalPecados()){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void Util::ordenarPorTotalMenorMayor(Persona **personas, int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->acciones->totalPecados() < personas[i]->acciones->totalPecados()){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void Util::ordenarBondadPorTotalMayorMenor(Persona **personas, int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->acciones->totalBuenasAcciones() > personas[i]->acciones->totalBuenasAcciones()){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void Util::ordenarBondadPorTotalMenorMayor(Persona **personas,int length){
    for (int i = 0;i<length-1;i++) {
        for (int j = i+1;j<length;j++) {
            if (personas[j]->acciones->totalBuenasAcciones() < personas[i]->acciones->totalBuenasAcciones()){
                Persona * temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
