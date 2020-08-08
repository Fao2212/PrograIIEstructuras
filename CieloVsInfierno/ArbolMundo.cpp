#include "ArbolMundo.h"
#include "ListaDoble.h"
#include "Arbol.h"
#include "NodoA.h"
#include "Nodo.h"
#include "Persona.h"
#include"Log.h"

void ArbolMundo::crearArbol(ListaDoble *lista){//Se llama cada vez que se agregan nuevas personas
    Log::createlog("Arbol"+Log::timeStamp());
    this->currentPopulation = lista->largo();
    int numNodos = numeroDeNodos(lista->largo()*0.01)-1;
    int distribucion = lista->largo()/numNodos;
    Nodo * inicio = lista->primerNodo;
    Nodo * arrayNodos[numNodos];

    this->arbol = new Arbol();
    for (int i = 0;i < numNodos;i++) {
        if(i != 0)
            inicio = recorrido(inicio,distribucion);
        //arbol->insertar(inicio);
        arrayNodos[i] = recorrido(inicio,distribucion);

    }
    arbol->raiz = (crearArbolAux(arrayNodos,0,numNodos-1));
    toString();
    Log::saveLog();
}

NodoA * ArbolMundo::crearArbolAux(Nodo* array[],int inicio,int final){
    if(inicio>final)
        return nullptr;
    int mid = (inicio+final)/2;
    NodoA * root = new NodoA(array[mid]);
    root->hijoizquierdo=crearArbolAux(array,inicio,mid-1);
    root->hijoderecho = crearArbolAux(array,mid+1,final);
    return root;
}

Nodo * ArbolMundo::recorrido(Nodo * inicio ,int pos){
    int cont = 0;
    Nodo * temp = inicio;
    while (cont++ < pos) {
        temp = temp->siguiente;
    }
    return  temp;
}

int ArbolMundo::numeroDeNodos(int unoPorciento){
    int potencia = 1;
    while(unoPorciento > potencia){
        potencia = potencia*2;
    }
    return potencia;
}

Persona * ArbolMundo::buscarEnArbol(int id){
    return buscarEnArbol(id,arbol->raiz);
}

Persona * ArbolMundo::buscarEnArbol(int id, NodoA *nodo){
    if(nodo == nullptr){
        return  nullptr;
    }
   else{
        int tempId = nodo->dato->dato->id;
        qDebug()<<tempId<<"Temp";
        if(id == tempId)
            return nodo->dato->dato;
        else{
            if (id<tempId) {
                if(nodo->hijoizquierdo == nullptr)
                    return recorrerALaIzquierda(nodo,id);
                else
                   return buscarEnArbol(id,nodo->hijoizquierdo);
            }
            else{
                if(nodo->hijoderecho == nullptr)
                    return recorrerALaDerecha(nodo,id);
                else
                    return  buscarEnArbol(id,nodo->hijoderecho);
            }
        }
    }
}

Persona * ArbolMundo :: recorrerALaDerecha(NodoA *inicio,int id){
    qDebug()<<"Recorriendo a la derecha"<<inicio->dato->dato->id;
    Nodo * temp = inicio->dato;
    while (temp != nullptr) {
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->siguiente;
    }
    return  nullptr;
}

Persona * ArbolMundo :: recorrerALaIzquierda(NodoA *inicio,int id){
    qDebug()<<"Recorriendo a la izquerda"<<inicio->dato->dato->id;
    Nodo * temp = inicio->dato;
    while (temp != nullptr) {
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->anterior;
    }
    return  nullptr;
}

void ArbolMundo::toString(){
    Log::addToLog("Cantidad De Nodos\t"+QString::number(arbol->cantNodos2(arbol->raiz)));
    Log::addToLog("Hojas\t"+QString::number(arbol->cantHojas(arbol->raiz)));
    Log::addToLog("Cantidad De Humanos\t"+QString::number(currentPopulation));
    QList<Persona *> * personasList = new QList<Persona*>;
    arbol->toStringProgra(arbol->raiz,personasList);
    for (int i = 0 ;i<personasList->length();i++) {
        Log::addToLog(personasList->at(i)->toString());
    }
}


