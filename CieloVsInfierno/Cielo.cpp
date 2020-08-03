#include "Cielo.h"
#include "HashCielo.h"
#include "ArbolAngeles.h"

void Cielo::initCielo(Infierno * infierno){
    this->hash = new HashCielo();
    this->infierno = infierno;
    this->angeles = new ArbolAngeles(hash,infierno);

}

void Cielo::salvacion(){
    this->angeles->nuevoNivel();
}
