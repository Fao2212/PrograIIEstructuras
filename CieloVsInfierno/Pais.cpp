#include "Pais.h"

void Pais::obtenerContinente(int pais){
    if (pais<20){
        this->continente = "OCEANIA";
    }
    else if (pais<40) {
        this->continente = "EUROPA";
    }
    else if (pais<60) {
        this->continente = "ASIA";
    }
    else if (pais<80) {
        this->continente = "AMERICA";
    }
    else
        this->continente = "AFRICA";
}

void Pais::sumarPecados(int pecados){
    this->pecados += pecados;
}
