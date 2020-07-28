#include "Familia.h"
#include "Persona.h"

void Familia::agregarHijos(Persona **hijos){
    for (int i = 0;i<5;i++) {
        this->hijos[i] = hijos[i];
    }
}

void Familia::agregarPadre(Persona *padre){
    this->padre = padre;
}

Persona * Familia::buscarCabezaDeFamilia(Persona * persona){
    if(padre == nullptr)
        return nullptr;
    else{
        buscarCabezaDeFamilia(persona->familia->padre);
    }
}

QString Familia::imprimirFamilia(){
    qDebug()<<"Lo intente!!!!";
    Persona * primero = buscarCabezaDeFamilia(persona);
    return imprimirFamilia(primero,"");
}

QString Familia::imprimirFamilia(Persona * persona,QString datos){
    qDebug()<<"Lo intente";
    if(persona == nullptr){
        return nullptr;
    }
    else{
        QString name = persona->nombre+" "+persona->apellido;
        datos+=name;
        qDebug()<<name;
        for (int i = 0;i < 5;i++) {
            Persona * hijo = persona->familia->hijos[i];
            if(hijo != nullptr){
                datos += "\n";
                imprimirFamilia(hijo,datos);
            }
        }
    }
    return datos;
}
