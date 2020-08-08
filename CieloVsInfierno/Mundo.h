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
    QString profesiones[50];
    QString creencias[10];
    Pais * paises[25];
    int vivos;//El total esta en poblacion index  muertos = total - vivos
    Infierno * infierno;
    Cielo * cielo;
    Continente * contienentes[5];
    QString continentesName[5] = {
        "OCEANIA","EUROPA","ASIA","AMERICA","AFRICA"
    };

    int consecutivo;

    Mundo(){
        initMundo();
    }

    void initMundo();
    void initContinentes();
    void agregarPoblacion(int cantidad);
    void ordenarMundo();//quicksort
    void initIdentidades();
    void initApellidos();
    void initNombres();
    void initPaises();
    void iniciarDistribucionDeFamilias();
    void initProfesiones();
    void initCreencias();

    Persona * crearPersona();
    void nombrarPersona(Persona *);
    void darNombre(Persona *);
    void darApellido(Persona *);
    void darPais(Persona *);
    void asignarFamilia(Persona *);
    void darCreencia(Persona *);
    void darProfesion(Persona *);

    ArbolGenealogico * buscarArbolFamiliar(Persona *);
    ArbolGenealogico * crearArbolFamiliar(Persona *);
    void guardarFamilia(Persona * persona);
    QString imprimirUnaFamilia(Persona * persona);
    int totalPersonasMuertas();

    //Consultas
    QString imprimirInfierno();
    QString rankingPaisesMasPecadores();
    QString imprimirCielo();
    QString rankingPaisesMenosPecadores();
    QString rankingPaisesMasBondadosos();
    QString rankingPaisesMenosBondadosos();
    QString imprimirMundo();
    QString imprimirFamiliaNombrePais(QString apellido,QString pais);
    QString imprimirMundoPecadosProfesion(QString profesion);
    QString imprimirMundoPecadosApellido(QString apellido);
    QString imprimirMundoPecadosContinente(QString contienente);
    QString imprimirMundoPecadosPaises(QString paises);
    QString imprimirMundoPecadosCreencia(QString creencia);
    QString imprimirMundoBondadProfesion(QString profesion);
    QString imprimirMundoBondadApellido(QString apellido);
    QString imprimirMundoBondadContinente(QString contienente);
    QString imprimirMundoBondadPaises(QString paises);
    QString imprimirMundoBondadCreencia(QString creencia);


    static QString localizacionToString(Localizacion localizacion);
    static QString estadoToString(Estado estado);
    Persona * buscarPersona(int id);//Usa el arbol para encontrar el mas proximo y se mueve anterior o siguietne a partir del nodo
    void pecar();
    QString imprimirGuerra();
    void buenasAcciones();
    void ordenarPaisesTotalPecados();
    void ordenarPaisesTotalBuenasAcciones();




};

#endif // MUNDO_H
