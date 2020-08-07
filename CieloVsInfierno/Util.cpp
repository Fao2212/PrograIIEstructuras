#include "Util.h"
#include "Persona.h"

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
