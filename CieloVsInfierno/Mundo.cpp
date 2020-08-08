#include "Mundo.h"
#include "Random.h"
#include "ListaDoble.h"
#include "ArbolMundo.h"
#include "Arbol.h"
#include "Persona.h"
#include "ListaSimple.h"
#include "FileManager.h"
#include "Pais.h"
#include "Familia.h"
#include "ArbolGenealogico.h"
#include "Nodo.h"
#include "NodoAG.h"
#include "Infierno.h"
#include "Contienente.h"
#include "Cielo.h"
#include "Log.h"

void Mundo:: nombrarPersona(Persona * persona){
    darNombre(persona);
    darApellido(persona);
}

void Mundo::initApellidos(){
    Log::addToLog("Creando apellidos");
    QDir a = FileManager::setDir();
    QString path = a.path()+"/CieloVsInfierno/Datos Humanos/Apellidos.txt";
    QString data = FileManager::leer(path);
    QStringList ql = data.split(";");
    int temp[ql.length()];
    for (int i = 0;i < ql.length();i++) {
        temp[i] = i;
    }
    Random::Shuffle(temp,ql.length());
    for (int i = 0;i<200;i++) {
        apellidos[i] = ql.at(temp[i]);
    }
}

void Mundo::initNombres(){
    Log::addToLog("Creando nombres");
    QDir a = FileManager::setDir();
    QString path = a.path()+"/CieloVsInfierno/Datos Humanos/Nombres.txt";
    QString data = FileManager::leer(path);
    QStringList ql = data.split(";");
    for (int i = 0;i<ql.length();i++) {
        nombres[i] = ql.at(i);
    }
}

void Mundo::initPaises(){
    Log::addToLog("Creando paises");
    QDir a = FileManager::setDir();
    QString path = a.path()+"/CieloVsInfierno/Datos Humanos/Paises.txt";
    QString data = FileManager::leer(path);
    QStringList ql = data.split(";");
    int temp[ql.length()];
    Pais * tempPais[100];
    for (int i = 0;i<ql.length();i++) {
        temp[i] = i;
    }
    Random::Shuffle(temp,ql.length());
    for (int i = 0;i<ql.length();i++) {
        tempPais[i] = new Pais(ql.at(i),i);
    }
    for (int i = 0;i < 25;i++) {
        paises[i] = tempPais[temp[i]];
    }
}

void Mundo::initMundo(){
    Log::createlog("CreacionDelMuntoTest");
    this->poblacion = new ListaDoble();
    this->familias = new ListaSimple();
    this->consecutivo = 0;
    this->vivos = 0;
    this->infierno = new Infierno(this);
    this->cielo = new Cielo(infierno);
    initIdentidades();
    initNombres();
    initApellidos();
    initPaises();
    initContinentes();
    Log::saveLog();
}

void Mundo::initIdentidades(){
    Log::addToLog("Creando identidades");
    for (int i = 0;i<1000000;i++) {
        identidades[i] = i;
    }
    Random::Shuffle(identidades,1000000);//revisar esto
}

void Mundo :: agregarPoblacion(int cantidad){
    for (int i = 0;i < cantidad;i++) {
        poblacion->insertar(crearPersona());
    }
    iniciarDistribucionDeFamilias();
    ordenarMundo();
    NodoAG * mier = familias->primerNodo;
    while (mier->siguiente != nullptr) {
        mier->dato->heap->imprimir();
        mier = mier->siguiente;
    }
    imprimirMundo();
}

void Mundo::ordenarMundo(){
    this->poblacion->ordenarPorId();
    this->arbolMundo = new ArbolMundo(poblacion);
}

Persona * Mundo::crearPersona(){
    Persona * persona = new Persona(identidades[consecutivo++]);
    nombrarPersona(persona);
    darPais(persona);
    guardarFamilia(persona);
    vivos++;
    return persona;
}

Persona * Mundo::buscarPersona(int id){
    return arbolMundo->buscarEnArbol(id);
}


void Mundo::darNombre(Persona * persona){
    persona->nombre = nombres[Random::RandomRange(0,1000)];
}

void Mundo::darApellido(Persona * persona){
    persona->apellido = apellidos[Random::RandomRange(0,199)];
}

void Mundo::darPais(Persona * persona){
    int randon = Random::RandomRange(0,24);
    qDebug()<<randon;
    persona->pais = paises[randon];
}

void Mundo::guardarFamilia(Persona * persona){
    ArbolGenealogico * ag = buscarArbolFamiliar(persona);
    if (ag == nullptr) {
        ag = crearArbolFamiliar(persona);
    }
    ag->heap->insertar(persona);
    persona->arbolGenealogico = ag;
}

ArbolGenealogico * Mundo::buscarArbolFamiliar(Persona * persona){
   return this->familias->buscar(persona);
}

ArbolGenealogico * Mundo:: crearArbolFamiliar(Persona * persona){
    ArbolGenealogico * ag = new ArbolGenealogico(persona->apellido,persona->pais);
    this->familias->insertar(ag);
    return ag;
}

void Mundo::asignarFamilia(Persona *persona){
    int numeroDeHijos = Random::RandomRange(0,4);
    Persona * hijos[5];
    for (int i = 0;i<5;i++) {
        if(i<numeroDeHijos){
            hijos[i] = persona->arbolGenealogico->buscarDisponible(persona);
        }
        else{
            hijos[i] = nullptr;
        }
    }
    for (int i = 0;i<5;i++) {
        if (hijos[i] != nullptr) {
            hijos[i]->familia->agregarPadre(persona);
        }
    }
    persona->familia->agregarHijos(hijos);
    persona->familiaAsignada = true;
    persona->arbolGenealogico->heap->enviarAlFinal(persona);
}

QString Mundo::imprimirUnaFamilia(Persona * persona){
    return  persona->familia->imprimirFamilia();
}

void Mundo::iniciarDistribucionDeFamilias(){//Tengo que pensar en como dar familias antes del shuffle
    for (int i = 0;i<poblacion->largo();i++) {
        if(!poblacion->get(i)->dato->familiaAsignada)
            asignarFamilia(poblacion->get(i)->dato);
    }
}

void Mundo::pecar(){
    qDebug()<<"Inicia pecado";
    poblacion->recorridoPecaminoso();
    qDebug()<<"Termina pecado";
}

void Mundo::buenasAcciones(){
    qDebug()<<"Inicia buenas acciones";
    poblacion->caminoDelBien();
    qDebug()<<"Termina buenas acciones";
}

void Mundo::initContinentes(){
    Log::addToLog("Creando continentes");
    for (int i = 0;i<5;i++) {
        contienentes[i] = new Continente(continentesName[i]);
        for (int j = 0;j<25;j++) {
            if(paises[j]->continente == contienentes[i]->nombre)
                contienentes[i]->addPais(paises[j]);
        }
        qDebug()<<contienentes[i]->nombre<<contienentes[i]->toString();
    }

}

QString Mundo::imprimirInfierno(){
    Log::createlog("ImpresionDelInfierno"+Log::timeStamp());
    QString msg = infierno->imprimirInfierno();
    Log::addToLog(msg);
    Log::saveLog();
    return msg;
}

QString Mundo::imprimirCielo(){
    Log::createlog("ImpresiomDelCielo"+Log::timeStamp());
    cielo->imprimirCielo();
    Log::saveLog();
    return "";
}

QString Mundo::imprimirGuerra(){
    Log::createlog("EstadoDeGuerra"+Log::timeStamp());
    int totalCielo = cielo->totalEnCielo();
    int totalInfierno = infierno->pecadosTotales();
    infierno->imprimirCantidadDeCadaPecado();
    cielo->imprimirCantidadDeCadaBuenaAccion();
    Log::addToLog("Neto Infierno\t"+QString::number(totalInfierno-totalCielo));
    Log::addToLog("Neto Cielo\t"+QString::number(totalCielo-totalInfierno));
    if(totalInfierno-totalCielo>totalCielo-totalInfierno)
        Log::addToLog("Ganando:\tInfierno");
    else
        Log::addToLog("Ganando:\tCielo");
    Log::saveLog();
    return "";
}

QString Mundo::rankingPaisesMasPecadores(){
    QString msg = "Mas Pecadores\n";
    ordenarPaisesTotalPecados();
    for (int i = 0;i<10;i++) {
        msg+=QString::number(i+1)+"."+paises[i]->nombre+" "+paises[i]->pecados+"\n";
    }
    return msg;
}

QString Mundo::rankingPaisesMenosPecadores(){
    QString msg = "Menos Pecadores\n";
    ordenarPaisesTotalPecados();
    for (int i = 0;i<5;i++) {
        msg+=QString::number(i+1)+"."+paises[i]->nombre+" "+paises[i]->pecados+"\n";
    }
    return msg;
}

QString Mundo::rankingPaisesMasBondadosos(){
    QString msg = "Mas Bondadosos\n";
    ordenarPaisesTotalBuenasAcciones();
    for (int i = 0;i<10;i++) {
        msg+=QString::number(i+1)+"."+paises[i]->nombre+" "+paises[i]->buenasAcciones+"\n";
    }
    return msg;
}

QString Mundo::rankingPaisesMenosBondadosos(){
    QString msg = "Menos Bondadosos\n";
    ordenarPaisesTotalBuenasAcciones();
    for (int i = 0;i<5;i++) {
        msg+=QString::number(i+1)+"."+paises[i]->nombre+" "+paises[i]->buenasAcciones+"\n";
    }
    return msg;
}

void Mundo::ordenarPaisesTotalPecados(){
    for (int i = 0;i<24;i++) {
        for (int j = i+1;j<25;j++) {
            if (paises[j]->pecados > paises[i]->pecados){
                Pais * temp = paises[i];
                paises[i] = paises[j];
                paises[j] = temp;
            }
        }
    }
}

void Mundo::ordenarPaisesTotalBuenasAcciones(){
    for (int i = 0;i<24;i++) {
        for (int j = i+1;j<25;j++) {
            if (paises[j]->buenasAcciones > paises[i]->buenasAcciones){
                Pais * temp = paises[i];
                paises[i] = paises[j];
                paises[j] = temp;
            }
        }
    }
}

QString Mundo::imprimirMundo(){
    Log::createlog("Mundo"+Log::timeStamp());
    Log::addToLog("Poblacion\t"+QString::number(poblacion->largo()));
    for (int i = 0;i<poblacion->largo();i++) {
        Log::addToLog(poblacion->get(i)->dato->toString());
    }
    Log::saveLog();
    return "";
}
