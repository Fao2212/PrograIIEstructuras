#include "Acciones.h"
#include "Accion.h"
#include "Random.h"
#include "Persona.h"

void Acciones::initAcciones(){

    for (int i = 0;i < 7;i++) {
        pecados[i] = new Accion(enumValues[i],i);
        buenasAcciones[i] = new Accion(enumValues[i+7],i+7);
    }
}

Accion * Acciones::getAccion(Comportamiento comportamiento){
    for (int i = 0;i<7;i++) {
        if(comportamiento == pecados[i]->comportamiento){
            return pecados[i];
        }
        if(comportamiento == buenasAcciones[i]->comportamiento)
            return buenasAcciones[i];
    }
    return  nullptr;
}

int Acciones::getValue(Comportamiento comportamiento){
    Accion * accion = getAccion(comportamiento);
    if (accion == nullptr) {
        return -1;
    }
    else{
        return accion->valor;
    }
}

int Acciones::diferenciaIndividual(Comportamiento comportamiento){
    Accion * accion = getAccion(comportamiento);
    if (accion == nullptr) {
        return INT_MIN;
    }
    else{
        if(accion->index < 7){
            return accion->valor-buenasAcciones[accion->index]->valor;
        }
        else{
            return accion->valor-pecados[accion->index-7]->valor;
        }
    }
}

int Acciones::diferenciaTotalBA(){
    int resultado = 0;
    for (int i = 0; i<7;i++) {
        resultado += diferenciaIndividual(enumValues[i]);
    }
    return  resultado;
}

int Acciones::totalPecados(){
    int resultado = 0;
    for (int i = 0;i<7;i++) {
        resultado += pecados[i]->valor;
    }
    return  resultado;
}

int Acciones::totalBuenasAcciones(){
    int resultado = 0;
    for (int i = 0;i<7;i++) {

        resultado += buenasAcciones[i]->valor;
    }
    return  resultado;
}

void Acciones::sumarAccion(Comportamiento comportamiento,int cantidad){
    getAccion(comportamiento)->aumentarValor(cantidad);
}

void Acciones::sumarPecados(){
    for (int i = 0;i<7;i++) {
        int randomValue = Random::RandomRange(0,100);
        persona->heredarPecados(pecados[i]->comportamiento,randomValue);
    }
}

void Acciones::sumarBuenasAcciones(){
    for (int i = 0;i<7;i++) {
        buenasAcciones[i]->aumentarValor(Random::RandomRange(0,100));
    }
}

QString Acciones::comportamientoName(Comportamiento comportamiento){
    switch (comportamiento) {
            case IRA:
            return "Ira";
            case GULA:
            return "Gula";
            case AYUNO:
            return "Ayuno";
            case CALMA:
            return "Calma";
            case PEREZA:
            return "Pereza";
            case CODICIA:
            return "Codicia";
            case ENVIDIA:
            return "Envidia";
            case LUJURIA:
            return "Lujuria";
            case ORGULLO:
            return "Orgullo";
            case CASTIDAD:
            return "Castidad";
            case DONACION:
            return "Donacion";
            case HUMILDAD:
            return "Humildad";
            case DILIGENCIA:
            return "Diligencia";
            case SOLIDARIDAD:
            return "Solidaridad";
            case ID:
            return "Id";
            default:
            return "";
    }
}

QString Acciones::toString(){
    QString msg = "[Pecados: ";
    for (int i = 0;i<7;i++) {
        msg += pecados[i]->toString()+",";
    }
    msg += "Buenas Acciones:";
    for (int i = 0;i<7;i++) {
        msg += buenasAcciones[i]->toString()+",";
    }
    msg+="]";
    return msg;
}

int Acciones::getIndexComportamiento(Comportamiento comportamiento){
    for (int i = 0;i<14;i++) {
        if(comportamiento == enumValues[i])
            return i;
    }
    return -1;
}
