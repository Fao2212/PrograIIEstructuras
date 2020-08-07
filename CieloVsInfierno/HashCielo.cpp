#include "HashCielo.h"
#include "Random.h"
#include "Persona.h"
#include "Acciones.h"

QString HashCielo::toString(){
    QString data = "";
    for (int i = 0;i<1000;i++) {
        QList<Persona *> * bucket = buckets[i];
        data += "Bucket "+QString::number(i)+"\n"+toStringBucket(bucket);
    }
    return data;
}

int HashCielo::hashFunction(QString id){
    return (((id.toInt()*Random::RandomRange(0,100))/Random::RandomRange(1,100))+Random::RandomRange(0,1000))%1000;
}

void HashCielo::insert(Persona * persona){
    buckets[hashFunction(QString::number(persona->id))]->append(persona);
}

Persona * HashCielo::get(QString id){
    int index = hashFunction(id);
    QList<Persona *> * list = buckets[index];
    for (int i = 0;i < list->length();i++) {
        Persona * persona = list->at(i);
        if (persona->id == id) {
            return  persona;
        }
    }
    return nullptr;
}

QString HashCielo::toStringBucket(QList<Persona *>* bucket){
    QString msg = "";
    for (int i = 0;i<bucket->length();i++) {
        msg+=bucket->at(i)->toString()+"\n";
    }
    return msg;
}

int HashCielo::cantidadDeUnaBuenaAccion(Comportamiento comportamiento){
    int cantidad = 0;
    for (int i = 0;i<1000;i++) {
        QList<Persona *> * bucket = buckets[i];
        for (int i = 0;i<bucket->length();i++) {
            cantidad += bucket->at(i)->getComportamiento(comportamiento);
        }
    }
    return cantidad;
}

int HashCielo::totalBuenasAcciones(){
    int cantidad = 0;
    for (int i = 0;i<1000;i++) {
        QList<Persona *> * bucket = buckets[i];
        for (int i = 0;i<bucket->length();i++) {
            cantidad += bucket->at(i)->acciones->totalBuenasAcciones();
        }
    }
    return cantidad;
}
