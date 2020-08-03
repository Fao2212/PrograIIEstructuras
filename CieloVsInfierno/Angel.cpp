#include "Angel.h"
#include "Infierno.h"
#include "HashCielo.h"
#include "Persona.h"

void Angel::salvarPersona(){
    this->salvado = infierno->buscarBuenasAcciones();
    if(salvado != nullptr){
        this->hash->insert(salvado);
        this->salvado->serSalvado(this);
    }
}
