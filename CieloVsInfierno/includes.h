#ifndef INCLUDES_H
#define INCLUDES_H
#include "QDebug"
#include "QString"
#include "QFile"
#include "QHash"
#include "qlist.h"
#include "QDir"
#include "QDateTime"

struct Arbol;
struct ArbolGenealogico;
struct ArbolMundo;
struct Familia;
struct Heap;
struct ListaDoble;
struct ListaSimple;
struct Mundo;

struct Infierno;
struct Demonio;

struct Cielo;
struct Angel;
struct HashCielo;
struct NodoAngeles;
struct ArbolAngeles;

struct Nodo;
struct NodoAG;
struct NodoA;

struct Pais;
struct Continente;

struct Persona;
struct Acciones;
struct Accion;
struct Random;

enum Comportamiento{
    ORGULLO,
    ENVIDIA,
    IRA,
    PEREZA,
    CODICIA,
    GULA,
    LUJURIA,
    HUMILDAD,
    SOLIDARIDAD,
    CALMA,
    DILIGENCIA,
    DONACION,
    AYUNO,
    CASTIDAD,
    ID
};

enum Estado{
    VIVO,
    MUERTO
};

enum Localizacion{
    INFIERNO,
    MUNDO,
    CIELO
};

enum Demonios{
    LUCIFER,
    BELCEBU,
    SATAN,
    ABADON,
    MAMMON,
    BELFEGOR,
    ASMODEO
};



#endif // INCLUDES_H
