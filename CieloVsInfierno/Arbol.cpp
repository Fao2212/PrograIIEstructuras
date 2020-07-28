#include "NodoA.h"
#include "Arbol.h"
#include "QDebug"
#include "Nodo.h"
#include "Persona.h"

void Arbol::insertar(Nodo * dato)
{
     raiz = insertar(dato, raiz);
}

//  INSERTA RECURSIVAMENTE
NodoA* Arbol::insertar(Nodo * valor, NodoA* nodo)
{

      if (nodo == NULL)
      {
        return new NodoA(valor);
      }
      else if (nodo->dato->dato->id < valor->dato->id)
      {
        nodo->hijoderecho = insertar(valor, nodo->hijoderecho);
      }
      else if (nodo->dato->dato->id >= valor->dato->id)
      {
         nodo->hijoizquierdo = insertar(valor, nodo->hijoizquierdo);
      }

      return nodo;
}

void Arbol::inOrden(NodoA* nodo)
{
   if (nodo != nullptr)
   {
     inOrden(nodo->hijoizquierdo);
     qDebug()<< nodo->dato->dato->id << "  id Persona";
     inOrden(nodo->hijoderecho);
   }
}

void Arbol::preOrden(NodoA* nodo)
{
   if (nodo != nullptr)
   {
     qDebug() << nodo->dato->dato->id << "  ";
     preOrden(nodo->hijoizquierdo);
     preOrden(nodo->hijoderecho);
   }
}

void Arbol::posOrden(NodoA* nodo)
{
   if (nodo != nullptr)
   {
     posOrden(nodo->hijoizquierdo);
     posOrden(nodo->hijoderecho);
     qDebug() << nodo->dato->dato->id << "  ";

   }
}


int Arbol::contadorNodos(NodoA* nodo)
{
     if (nodo == nullptr)
        return 0;
     else
         return 1+ contadorNodos(nodo->hijoderecho)+contadorNodos(nodo->hijoizquierdo);
}

NodoA* Arbol::buscar (Nodo * valor, NodoA* nodo)
 {
     if (nodo == nullptr)
     {
         return nullptr;
     }
     else if (nodo->dato->dato->id == valor->dato->id)
     {
        return nodo;
     }
     else if (nodo->dato->dato->id < valor->dato->id)
     {
        return buscar(valor, nodo->hijoderecho);
     }
     else
     {
        return buscar(valor, nodo->hijoizquierdo);
     }
 }

 // cantidad de elementos de un arbol binario
 int Arbol::obtenerNumeroElementos(NodoA* nodo)
 {
     int num_elems = 0;

     if(nodo != nullptr)
     {
        num_elems += obtenerNumeroElementos(nodo->hijoizquierdo);
        num_elems++;
        num_elems += obtenerNumeroElementos(nodo->hijoderecho);
    }
    return num_elems;
 }


  int Arbol::obtenerAltura(NodoA* nodo) {

      // resultado
    int altura    = 0;

    // referencias hi e hd
    NodoA* ref_h_izq;
    NodoA* ref_h_der;

    // resultado de alturas de hi e hd
    int altura_r_izq = 0;
    int altura_r_der = 0;

    //
    if(nodo != nullptr) {
        // incia en 1 para contar la raiz
        altura = 1;

        // inicialiaza las referencias
        ref_h_izq = nodo->hijoizquierdo;
        ref_h_der = nodo->hijoderecho;

        // si ninguno de los hijos es nulo
        if( (ref_h_izq != nullptr) && (ref_h_der != nullptr) ) {
            // obtiene las alturas de cada arbol izq y der
            altura_r_izq = obtenerAltura(ref_h_izq);
            altura_r_der = obtenerAltura(ref_h_der);

            // suma la altura mayor, para determinar el mayor nivel
            if(altura_r_izq >= altura_r_der)
            {
                altura += altura_r_izq;
            }
            else
            {
                altura += altura_r_der;
            }
        // hizq no es nulo, suma altura de hijo izquierdo
        }
        else if( (ref_h_izq != nullptr) && (ref_h_der == nullptr) )
        {
            altura += obtenerAltura(ref_h_izq);
        }
        // hder no es nulo, suma altura de hijo derecho
        else if( (ref_h_izq == nullptr) && (ref_h_der != nullptr) )
        {
            altura += obtenerAltura(ref_h_der);
        }
        // cuando ambos son nulos, resta el uno con el que empezó
        else if( (ref_h_izq == nullptr) && (ref_h_der == nullptr) )
        {
            altura -= 1;
        }
    }
    // retorna el resultado
    return altura;

}

int maximo (int a, int b)
{
    if (a>b)
       return a;
       else return b;
}

int Arbol::altura (NodoA* nodo)
{
    if (nodo == nullptr)
        return -1;
    else
         return 1 + maximo(altura(nodo->hijoizquierdo),altura(nodo->hijoderecho));
}

int Arbol::cantNodos2 (NodoA* nodo)
{
    if (nodo == nullptr)
        return 0;
    else
         return 1 + cantNodos2(nodo->hijoizquierdo)+cantNodos2(nodo->hijoderecho);
}



int Arbol::cantHojas(NodoA* raiz)
{
    if (raiz == nullptr)
       return 0;
    else if (raiz->hijoderecho == nullptr && raiz->hijoizquierdo==nullptr)
         return 1;
    else
        return cantHojas(raiz->hijoderecho)+cantHojas(raiz->hijoizquierdo);

}


 NodoA* Arbol::mayor (NodoA* arbol)
  {
    if (arbol == nullptr)
        return nullptr;
    else if (arbol->hijoderecho == nullptr)
        return arbol;
    else
        return mayor (arbol->hijoderecho);
  }


NodoA* Arbol::borrarElemento(Nodo * ele)
{
      raiz = borrarElemento(ele, raiz);
      return raiz;
}

NodoA* Arbol::borrarElemento(Nodo * ele, NodoA* arbol)
    {
        if (arbol == nullptr)
        {
            return nullptr;
        }
        else if (ele->dato->id < arbol->dato->dato->id)
            arbol->hijoizquierdo = borrarElemento(ele, arbol->hijoizquierdo);
        else if (ele->dato->id > arbol->dato->dato->id)
            arbol->hijoderecho = borrarElemento(ele, arbol->hijoderecho);
        else if (arbol->hijoizquierdo == nullptr && arbol->hijoderecho == nullptr)
            arbol = nullptr;
        else if (arbol->hijoizquierdo == nullptr)
            arbol = arbol->hijoderecho;
        else if (arbol->hijoderecho == nullptr)
            arbol = arbol->hijoizquierdo;
        else{
            NodoA* max = mayor(arbol->hijoizquierdo); // mayor de los menores
            arbol->hijoizquierdo = borrarElemento(max->dato, arbol->hijoizquierdo);
            arbol->dato = max->dato;
        }
        return arbol;
    }
