#include "Infierno.h"
#include "Demonio.h"
#include "Random.h"
#include "Heap.h"
#include "Log.h"

void Infierno::initDemonios(){
    for (int i =0;i<7;i++) {
        demonios[i] = new Demonio(nombresDeDemonios[i],enumValues[i],mundo,enumValues[i+7]);
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
    qDebug()<<"Comienza Condenacion";
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-ddhh-mm-ss");
    Log::createlog("Condenacion"+time);
    for (int i = 0;i<7;i++) {
        demonios[i]->cosecharPecados();
    }
    Log::saveLog();
    qDebug()<<"Termina Condenacion";
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

QString Infierno:: imprimirInfierno(){
    QString msg = "Infierno/n";
    for (int i = 0;i<7;i++) {
        msg+= demonios[i]->imprimirInfierno()+"\n";
    }
    return msg;
}
    //TODOS LOS DEMONIOS Y SU PECADO
    //TOTAL EN INFIERNO PROMEDIO DE PECADOS EL MAXIMO Y EL MINIMO
    //RECORRIDO DE TODOS LOS INFIERNOS
    //RECORRIDO DEL HEAP


