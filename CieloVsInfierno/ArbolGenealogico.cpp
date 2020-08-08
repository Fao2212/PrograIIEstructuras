#include "ArbolGenealogico.h"
#include "ListaDoble.h"
#include "Nodo.h"
#include "Persona.h"
//Cuando se inicia el proceso de asignacion de fmilias los heaps de la lista se les hace
//un shuffle y luego con cada asignacion se marca como no dsponible y se envia a el final de la lista.
void ArbolGenealogico::initArbolGenealogico(QString nombre, Pais *pais){
    this->heap = new ListaDoble();
    this->pais = pais;
    this->familia = nombre;
}

Persona * ArbolGenealogico::buscarDisponible(Persona * persona){
    Nodo * temp = heap->primerNodo;
    Persona * p = temp->dato;

    if(p != persona){
        if(!p->familiaAsignada ){
            heap->enviarAlFinal();
            p->familiaAsignada = true;
            return p;
        }
        else{
            heap->enviarAlFinal();
            return nullptr;
        }
    }
        else{
            if (heap->primerNodo->siguiente != nullptr) {
                heap->moverPrimerNodo();
                return buscarDisponible(persona);
            }
            else {
                return  nullptr;
            }
        }
    }

QString ArbolGenealogico::toStringPorcentajes(){
    QString msg = "";
    msg+= "Porcentaje Vivos\t"+QString::number(porcentajeVivos())+"\n";
    msg+= "Porcentaje Infierno\t"+QString::number(porcentajeInfierno())+"\n";
    msg+= "Porcentaje Cielo\t"+QString::number(porcentajeCielo())+"\n";
    return  msg;
}


int ArbolGenealogico::porcentajeCielo(){
   int vivos = 0;
   for (int i = 0;i<heap->largo();i++) {
       if(heap->get(i)->dato->localizacion == CIELO)
           vivos+=1;
   }
   return  (100/heap->largo())*vivos;
}

int ArbolGenealogico::porcentajeVivos(){
    int vivos = 0;
    for (int i = 0;i<heap->largo();i++) {
        if(heap->get(i)->dato->estado == VIVO)
            vivos+=1;
    }
    return  (100/heap->largo())*vivos;
}

int ArbolGenealogico::porcentajeInfierno(){
    int vivos = 0;
    for (int i = 0;i<heap->largo();i++) {
        if(heap->get(i)->dato->localizacion == INFIERNO)
            vivos+=1;
    }
    return  (100/heap->largo())*vivos;
}
