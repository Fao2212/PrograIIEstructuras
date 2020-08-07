#ifndef HASHCIELO_H
#define HASHCIELO_H
#include "includes.h"

struct HashCielo{

    QList<Persona *> * buckets[1000];

    HashCielo(){
        for (int i = 0;i<1000;i++) {
            buckets[i] = new QList<Persona*>();
        }
    }

    int hashFunction(QString);//Modulo 1000 para conseguir un spot
    void insert(Persona *);
    Persona * get(QString);//Innecesario
    QString toString();
    int cantidadDeUnaBuenaAccion(Comportamiento comportamiento);
    QString toStringBucket(QList<Persona *>* bucket);
    int totalBuenasAcciones();
;
};

#endif // HASHCIELO_H
