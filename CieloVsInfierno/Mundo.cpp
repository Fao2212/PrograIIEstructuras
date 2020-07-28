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
void Mundo:: nombrarPersona(Persona * persona){
    darNombre(persona);
    darApellido(persona);
}

void Mundo::initApellidos(){

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
    QDir a = FileManager::setDir();
    QString path = a.path()+"/CieloVsInfierno/Datos Humanos/Nombres.txt";
    QString data = FileManager::leer(path);
    QStringList ql = data.split(";");
    for (int i = 0;i<ql.length();i++) {
        nombres[i] = ql.at(i);
    }
}

void Mundo::initPaises(){
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
    this->poblacion = new ListaDoble();
    this->familias = new ListaSimple();
    this->consecutivo = 0;
    initIdentidades();
    initNombres();
    initApellidos();
    initPaises();
}

void Mundo::initIdentidades(){
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
    arbolMundo->arbol->inOrden(arbolMundo->arbol->raiz);
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
    return persona;
}

Persona * Mundo::buscarPersona(int id){
    return arbolMundo->buscarEnArbol(id);
}


void Mundo::darNombre(Persona * persona){
    persona->nombre = nombres[Random::RandomRange(0,1000)];
}

void Mundo::darApellido(Persona * persona){
    persona->apellido = apellidos[Random::RandomRange(0,200)];
}

void Mundo::darPais(Persona * persona){
    persona->pais = paises[Random::RandomRange(0,25)];
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
    int numeroDeHijos = Random::RandomRange(0,5);
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
}

void Mundo::imprimirUnaFamilia(Persona * persona){
    qDebug()<<"ImprimirUnaFmailia0";
    persona->familia->imprimirFamilia();
}

void Mundo::iniciarDistribucionDeFamilias(){//Tengo que pensar en como dar familias antes del shuffle
    for (int i = 0;i<poblacion->largo();i++) {
        asignarFamilia(poblacion->get(i)->dato);
    }
}
