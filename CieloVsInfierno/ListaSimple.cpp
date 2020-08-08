#include "ListaSimple.h"
#include "NodoAG.h"
#include "Persona.h"
#include "ArbolGenealogico.h"
#include "Pais.h"

ArbolGenealogico * ListaSimple::buscar(Persona * persona){
    NodoAG * temp = primerNodo;
    while (temp != nullptr) {
        if(persona->apellido == temp->dato->familia && persona->pais == temp->dato->pais)
            return  temp->dato;
        temp = temp->siguiente;
    }
    return  nullptr;
}

void ListaSimple::insertar(ArbolGenealogico * ag){
    insertar(new NodoAG(ag));
}

void ListaSimple::insertar(NodoAG * cliente){
    if (primerNodo == NULL)
    {
        primerNodo = cliente;
    }
    else
    {
        NodoAG * nuevo = cliente;
        NodoAG * temp = primerNodo;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

ArbolGenealogico * ListaSimple::buscar(QString apellido,QString pais){
    NodoAG * temp = primerNodo;
    while (temp != nullptr) {
        qDebug()<<temp->dato->familia<<temp->dato->pais->nombre;
        if(apellido == temp->dato->familia && pais == temp->dato->pais->nombre)
            return  temp->dato;
        temp = temp->siguiente;
    }
    return  nullptr;
}
