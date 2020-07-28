#include "ArbolMundo.h"
#include "ListaDoble.h"
#include "Arbol.h"
#include "NodoA.h"
#include "Nodo.h"
#include "Persona.h"

void ArbolMundo::crearArbol(ListaDoble *lista){//Se llama cada vez que se agregan nuevas personas
    int numNodos = numeroDeNodos(lista->largo()*0.01);
    int distribucion = lista->largo()/numNodos;
    Nodo * inicio = lista->primerNodo;
    this->arbol = new Arbol();
    for (int i = 0;i < numNodos;i++) {
        if(i != 0)
            inicio = recorrido(inicio,distribucion);
        arbol->insertar(inicio);
    }
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
    return buscarEnArbol(id,arbol->raiz,nullptr,nullptr);
}

Persona * ArbolMundo::buscarEnArbol(int id, NodoA *nodo,NodoA * inicio, NodoA * final){
    if(nodo == nullptr){
        return  nullptr;
    }
   else{
        int tempId = nodo->dato->dato->id;
        if(id == tempId)
            return nodo->dato->dato;
        else{
            if(id < tempId){
                if(nodo->hijoizquierdo  == nullptr){
                    if(inicio == nullptr && final == nullptr){
                        return recorrerALaIzquierda(nodo,final,id);
                    }
                    return recorrido(inicio,final,id);//23,64
                }
                else{
                    final = nodo;
                    inicio = nodo->hijoizquierdo;
                    buscarEnArbol(id,inicio,inicio,final);
                }
            }
            else{
                if(nodo->hijoderecho  == nullptr){
                    if(inicio == nullptr && final == nullptr){
                        return recorrerALaDerecha(inicio,nodo,id);
                    }
                    return recorrido(inicio,final,id);//72,64 9,14
                }
                else{
                    final = nodo;
                    inicio = nodo->hijoderecho;
                    buscarEnArbol(id,inicio,inicio,final);
                }
            }
        }
    }
}

Persona * ArbolMundo:: recorrido(NodoA *inicio, NodoA *final,int id){
    if(inicio == nullptr)
        return recorrerALaIzquierda(final,inicio,id);
    else if(final == nullptr)
        return recorrerALaDerecha(inicio,final,id);
    else{
        if(inicio->dato->dato->id < final->dato->dato->id){
            return recorrerALaIzquierda(inicio,final,id);
        }
        else{
            return recorrerALaDerecha(final,inicio,id);
        }
    }
}

Persona * ArbolMundo :: recorrerALaDerecha(NodoA *inicio, NodoA *final,int id){
    Nodo * temp = inicio->dato;
    Nodo * tempFinal = nullptr;
    if(final != nullptr)
        tempFinal = final->dato;
    while (temp != nullptr) {
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->siguiente;
    }
    return  nullptr;
}

Persona * ArbolMundo :: recorrerALaIzquierda(NodoA *inicio, NodoA *final,int id){
    Nodo * temp = inicio->dato;
    Nodo * tempFinal = nullptr;
    if(final != nullptr)
        tempFinal = final->dato;
    while (temp != nullptr) {
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->anterior;
    }
    return  nullptr;
}
