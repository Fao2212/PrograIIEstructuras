#include "ListaDoble.h"
#include "Nodo.h"
#include "Persona.h"

void ListaDoble::insertar(Nodo *cliente){
    if (primerNodo == NULL)
    {
        primerNodo = cliente;
        ultimoNodo = primerNodo; // ambos apuntan al nuevo
    }
    else
    {
        Nodo *nuevo = cliente;
        ultimoNodo->siguiente = nuevo;
        nuevo->anterior = ultimoNodo;
        ultimoNodo = nuevo;
    }
    this->index++;
}

void ListaDoble::insertar(Persona * persona){
    insertar(new Nodo(persona));
}

void ListaDoble::imprimir(){
    Nodo *tmp = primerNodo;
    int cont = 1;
    while (tmp != NULL){
      qDebug()<<tmp->dato->id<<QString::number(cont++); // metodo de imprimir un cliente
      tmp = tmp->siguiente;
    }
}

int ListaDoble::largo(){
    return index;
}

void ListaDoble:: ordenarPorId(){//merge sort
   quickSort();
}

void ListaDoble :: quickSort(){
    int length = largo();
    Nodo * poblacion[length];
    Nodo * temp = primerNodo;
    int contador = 0;
    while (temp != nullptr) {
        poblacion[contador++] = temp;
        temp = temp->siguiente;
    }
    quickSort(poblacion,0,length-1,ID);
    int newCont = 0;
    Nodo * newTemp = primerNodo;
    while (newTemp!= nullptr) {
        newTemp->dato = poblacion[newCont++]->dato;
        newTemp = newTemp->siguiente;
    }
    imprimir();
}

void ListaDoble::ordenarPorPecado(Persona * personas[],Comportamiento comportamiento){
    int length = largo();
    Nodo * poblacion[length];
    Nodo * temp = primerNodo;
    int contador = 0;
    while (temp != nullptr) {
        poblacion[contador++] = temp;
        temp = temp->siguiente;
    }
    quickSort(poblacion,0,length-1,comportamiento);
    int newCont = 0;
    while (newCont < length-1) {
    personas[newCont] = poblacion[newCont]->dato;
    newCont++;
    }
}

int ListaDoble::partition (Nodo * arr[], int l, int h,Comportamiento comportamiento)
{
    Nodo * x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if(comportamiento == ID){
            if (arr[j]->dato->id <= x->dato->id)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        else{
            if (arr[j]->dato->getComportamiento(comportamiento) > x->dato->getComportamiento(comportamiento))
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void * ListaDoble:: quickSort(Nodo * A[], int l, int h,Comportamiento comportamiento)
{
    if (l < h)
    {
        int p = partition(A, l, h,comportamiento); /* Partitioning index */
        quickSort(A, l, p - 1,comportamiento);
        quickSort(A, p + 1, h,comportamiento);
    }
}

void ListaDoble :: swap(Nodo * a,Nodo * b){
    Persona * temp = a->dato;
    a->dato = b->dato;
    b->dato = temp;
}

Nodo * ListaDoble::get(int pos){//buscar
    Nodo * temp = primerNodo;
    int cont = 0;
    while(temp != nullptr){
        if(cont == pos){
            return temp;
        }
        temp = temp->siguiente;
        cont++;
    }
    return nullptr;
}

void ListaDoble::enviarAlFinal(){
    ultimoNodo->siguiente = primerNodo;
    primerNodo->anterior = ultimoNodo;
    ultimoNodo = ultimoNodo->siguiente;
    primerNodo = primerNodo->siguiente;
    ultimoNodo->siguiente = nullptr;
    primerNodo->anterior = nullptr;
}

void ListaDoble::moverPrimerNodo(){
        Persona * temp = primerNodo->dato;
        primerNodo->dato = primerNodo->siguiente->dato;
        primerNodo->siguiente->dato = temp;

}

void ListaDoble::enviarAlFinal(Persona * persona){
    Nodo * aCambiar = buscar(persona);
    if (aCambiar != ultimoNodo) {
        if (aCambiar == primerNodo) {
            enviarAlFinal();
        }
        else {
            Nodo * tempAnterior = aCambiar->anterior;
            Nodo * tempSiguiente = aCambiar->siguiente;
            ultimoNodo->siguiente = aCambiar;
            aCambiar->siguiente = nullptr;
            ultimoNodo = aCambiar;
            tempAnterior->siguiente = tempSiguiente;
            tempSiguiente->anterior = tempAnterior;
        }
    }

}

Nodo * ListaDoble::buscar(Persona * p){
    Nodo * temp = primerNodo;
    while (temp != nullptr) {
        if (p == temp->dato) {
            return  temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

void ListaDoble::recorridoPecaminoso(){
    Nodo * temp = primerNodo;
    while (temp != nullptr) {
        if(temp->dato->estado != MUERTO)
            temp->dato->sumarPecados();
        temp = temp->siguiente;
    }
}

void ListaDoble::caminoDelBien(){
    Nodo * temp = primerNodo;
    while (temp != nullptr) {
        if(temp->dato->estado != MUERTO)
            temp->dato->sumarBuenasAcciones();
        temp = temp->siguiente;
    }
}
