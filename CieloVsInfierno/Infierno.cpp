#include "Infierno.h"
#include "Demonio.h"
#include "Random.h"
#include "Heap.h"

void Infierno::initDemonios(){
    for (int i =0;i<7;i++) {
        demonios[i] = new Demonio(nombresDeDemonios[i],enumValues[i],mundo);
    }
}

void Infierno::enviarPorAlmas(QString demonio){
    Demonio * demon = getDemonio(demonio);
    if(demon != nullptr)
        demon->cosecharPecados();
}

Demonio * Infierno::getDemonio(QString demonio){
    for (int i = 0;i < 7;i++) {
        Demonio * demon = demonios[i];
        if(demon->nombre == demonio)
            return demon;
    }
    return  nullptr;
}

void Infierno::condenacion(){
    for (int i = 0;i<7;i++) {
        demonios[i]->cosecharPecados();
    }
}

Persona * Infierno::buscarBuenasAcciones(){
    int aVisitar[7];
    for (int i = 0;i < 7;i++) {
        aVisitar[i] = i;
    }
    Random::Shuffle(aVisitar,7);
    for (int i = 0;i<7;i++) {
        QHash<QString,Heap *> * infiernoDemonio = demonios[aVisitar[i]]->familias;
        QList<Heap *> famEnInfierno = infiernoDemonio->values();
        for (int i = 0;i<famEnInfierno.length();i++) {
            Heap * tempHeap = famEnInfierno.at(i);
            Persona * aSalvar = tempHeap->buscarMenosPecador();
            if(aSalvar != nullptr)
                return aSalvar;
        }
    }
    return nullptr;
}
