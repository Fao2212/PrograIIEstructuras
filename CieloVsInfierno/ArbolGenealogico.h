#ifndef ARBOLGENEALOGICO_H
#define ARBOLGENEALOGICO_H
#include "includes.h"

struct ArbolGenealogico{

    ListaDoble * heap;
    QString familia;
    Pais * pais;

    ArbolGenealogico(QString nombre,Pais * pais){
        initArbolGenealogico(nombre,pais);
    }

    void initArbolGenealogico(QString nombre,Pais * pais);
    Persona * buscarDisponible();

};

#endif // ARBOLGENEALOGICO_H
