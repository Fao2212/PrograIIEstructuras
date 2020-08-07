#include "Contienente.h"
#include "Pais.h"

int Continente::sumarPecados(){
    int resultado = 0;
    for (int i = 0;paieses->length();i++) {
        resultado += paieses->at(i)->pecados;
    }
    return resultado;
}

void Continente::addPais(Pais * pais){
    paieses->append(pais);
}

QString Continente::toString(){
    QString mesnaje = "";
    for (int i =0;i<paieses->length();i++) {
        mesnaje += paieses->at(i)->nombre;
    }
    return mesnaje;
}
