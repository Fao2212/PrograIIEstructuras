#include "Infierno.h"
#include "Demonio.h"
#include "Random.h"
#include "Heap.h"
#include "Log.h"
#include "Util.h"
#include "Persona.h"
#include "Acciones.h"

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


int Infierno::pecadosTotales(){
    QList<Heap *> * enInfierno = new QList<Heap *>();
    int totalDePecados = 0;
    for (int i = 0;i<7;i++) {
        enInfierno->append(demonios[i]->familias->values());
    }
    for (int i = 0;i<enInfierno->length();i++) {
        Heap * tempHeap = enInfierno->at(i);
        totalDePecados += tempHeap->sumarPecados();
    }
    return totalDePecados;
}


QString Infierno::imprimirCantidadDeCadaPecado(){
    QString msg = "";
    Log::addToLog("PecadosTotales:\t"+QString::number(pecadosTotales()));
    for (int i = 0;i<7;i++) {
        msg+=demonios[i]->toStringPecado()+"\t";
    }
    Log::addToLog(msg);
    return msg;
}

QString Infierno:: imprimirInfierno(){
    Log::addToLog("Infierno");
    QString msg = "";
    int totalPecados=0;
    int humanosEnInfierno =0;
    int promedioPecados;
    Persona * masPecador;
    Persona * menosPecador;
    QList<Heap *> * enInfierno = new QList<Heap *>();
    QList<Persona *> * personasEnInfierno = new QList<Persona *>();
    for (int i = 0;i<7;i++) {
        enInfierno->append(demonios[i]->familias->values());
        msg+= demonios[i]->imprimirInfierno()+"\n";
    }
    for (int i = 0;i<enInfierno->length();i++) {
        Heap * tempHeap = enInfierno->at(i);
        totalPecados += tempHeap->sumarPecados();
        for (int i = 0;i<tempHeap->index;i++) {
            personasEnInfierno->append(tempHeap->personas[i]);
        }
    }
    Persona * arrayPersonas[personasEnInfierno->length()];
    for (int i = 0;i<personasEnInfierno->length();i++) {
        arrayPersonas[i] = personasEnInfierno->at(i);
    }
    Util::ordenarPorTotalMayorMenor(arrayPersonas,personasEnInfierno->length());
    masPecador = arrayPersonas[0];
    menosPecador = arrayPersonas[personasEnInfierno->length()-1];
    humanosEnInfierno = personasEnInfierno->length();
    promedioPecados = totalPecados/humanosEnInfierno;
    Log::addToLog("Total De Humanos:\t"+QString::number(humanosEnInfierno));
    Log::addToLog("Total De Pecados:\t"+QString::number(totalPecados));
    Log::addToLog("Promedio de pecados por humano:\t"+QString::number(promedioPecados));
    Log::addToLog("Mas Pecador:\t"+masPecador->toString());
    Log::addToLog("Menos Pecador:\t"+menosPecador->toString());
    return msg;
}



