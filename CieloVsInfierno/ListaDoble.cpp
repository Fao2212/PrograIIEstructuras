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
    quickSort(poblacion,0,length-1);
    int newCont = 0;
    Nodo * newTemp = primerNodo;
    while (newTemp!= nullptr) {
        newTemp->dato = poblacion[newCont++]->dato;
        newTemp = newTemp->siguiente;
    }
    imprimir();
}

int ListaDoble::partition (Nodo * arr[], int l, int h)
{
    Nodo * x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j]->dato->id <= x->dato->id)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void * ListaDoble:: quickSort(Nodo * A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
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
    primerNodo = primerNodo->siguiente;
    ultimoNodo = ultimoNodo->siguiente;
    ultimoNodo->siguiente = nullptr;
    primerNodo->anterior = nullptr;
}
