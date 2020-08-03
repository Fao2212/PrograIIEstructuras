#ifndef MUNDO_H
#define MUNDO_H
#include "includes.h"

struct Mundo{

    ArbolMundo * arbolMundo;
    ListaDoble * poblacion;
    ListaSimple * familias;
    int identidades[1000000];
    QString apellidos[200];
    QString nombres[1001];
    Pais * paises[25];
    int vivos;//El total esta en poblacion index
    Infierno * infierno;
    Cielo * cielo;

    int consecutivo;

    Mundo(){
        initMundo();
    }

    void initMundo();
    void agregarPoblacion(int cantidad);
    void ordenarMundo();//quicksort
    void initIdentidades();
    void initApellidos();
    void initNombres();
    void initPaises();
    void iniciarDistribucionDeFamilias();

    Persona * crearPersona();
    void nombrarPersona(Persona *);
    void darNombre(Persona *);
    void darApellido(Persona *);
    void darPais(Persona *);
    void asignarFamilia(Persona *);

    ArbolGenealogico * buscarArbolFamiliar(Persona *);
    ArbolGenealogico * crearArbolFamiliar(Persona *);
    void guardarFamilia(Persona * persona);
    QString imprimirUnaFamilia(Persona * persona);
    int totalPersonasMuertas();

    Persona * buscarPersona(int id);//Usa el arbol para encontrar el mas proximo y se mueve anterior o siguietne a partir del nodo
    void pecar();
    void buenasAcciones();




};

#endif // MUNDO_H
