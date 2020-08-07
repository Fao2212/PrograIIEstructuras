#ifndef CONTIENENTE_H
#define CONTIENENTE_H
#include "includes.h"

struct Continente{

    QList<Pais *> * paieses;
    QString nombre;

    Continente(QString nombre){
        this->nombre = nombre;
        this->paieses = new  QList<Pais*>();
    }

    int sumarPecados();
    void addPais(Pais * pais);
    QString toString();

};

#endif // CONTIENENTE_H
