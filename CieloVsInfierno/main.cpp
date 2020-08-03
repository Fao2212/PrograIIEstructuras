#include <QApplication>
#include "mainwindow.h"
#include "Mundo.h"
#include "ListaDoble.h"
#include "HashCielo.h"

int main(int argc, char *argv[])
{
    //Prueba mundo
    //Prubea Lista
    /*ListaDoble * l = new ListaDoble();
    for (int i = 0;i<10;i++) {
        l->insertar(new Nodo(new Persona(40-i)));
    }
    l->imprimir();
    l->ordenarPorId();
    l->imprimir();*/
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();
    //Probando hash
    /*HashCielo * a = new HashCielo();
    a->hashFunction(nullptr);*/
    return 0;
}
