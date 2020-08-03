#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "includes.h"
struct ListaDoble{

           Nodo *primerNodo, *ultimoNodo;
           int index;

           ListaDoble()
           {
               primerNodo = ultimoNodo = nullptr;
               this->index = 0;
           }

        void insertar (Nodo * cliente);
        void insertar (Persona * persona);
        void imprimir();
        int largo();
        Nodo * mergeSort(Nodo * nodo,QString id);
        Nodo * split(Nodo * nodo);
        Nodo * merge(Nodo * primero,Nodo * segundo,QString id);
        Nodo * get(int pos);
        void bubbleSort(QString modo);
        void quickSort();
        int partition (Nodo * arr[], int l, int h,Comportamiento comportamiento);
        void * quickSort(Nodo * A[], int l, int h,Comportamiento comportamiento);
        void swap(Nodo * a,Nodo * b);
        void enviarAlFinal();
        void moverPrimerNodo();
        void enviarAlFinal(Persona * p);
        Nodo * buscar(Persona * );

        void recorridoPecaminoso();
        void caminoDelBien();
        void ordenarPorId();
        void ordenarPorPecado(Persona * personas[],Comportamiento comportamiento);

    };

#endif // LISTADOBLE_H
