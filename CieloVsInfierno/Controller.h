#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "includes.h"
#include "Mundo.h"
#include "mainwindow.h"

struct Controller{
    Mundo * mundo;
    MainWindow mw;
    Controller(int cantidadDePersonas){
        mundo = new Mundo();
        mundo->agregarPoblacion(cantidadDePersonas);
    }
};

#endif // CONTROLLER_H
