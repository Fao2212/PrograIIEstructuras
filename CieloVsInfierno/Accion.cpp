#include "Accion.h"
#include "Acciones.h"

void Accion::aumentarValor(int cantidad){
    valor += cantidad;
}

QString Accion::toString(){
    return Acciones::comportamientoName(this->comportamiento)+"\t"+QString::number(valor);
}
