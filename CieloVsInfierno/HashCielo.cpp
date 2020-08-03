#include "HashCielo.h"
#include "Random.h"
#include "Persona.h"

QString HashCielo::toString(){
    QString data = "";
    for (int i = 0;i<1000;i++) {
        QList<Persona *> * bucket = buckets[i];
        qDebug()<<"Bucket "<<i<<" "<<bucket->length();
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
