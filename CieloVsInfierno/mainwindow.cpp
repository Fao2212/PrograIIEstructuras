#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mundo.h"
#include "Persona.h"
#include "Pais.h"
#include "Familia.h"
#include "Infierno.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mundo = new Mundo();
    this->mundo->agregarPoblacion(10000);
    this->mundo->initApellidos();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id = ui->txtBusqueda->text();
    if(id != ""){
        qDebug()<<id<<"ID INPUT";
        qDebug()<<id.toInt();
        Persona * persona = mundo->buscarPersona(id.toInt());
        if (persona != nullptr) {
            qDebug()<<persona->nombre;
            qDebug()<<persona->apellido;
            qDebug()<<persona->pais->nombre;
            qDebug()<<persona->pais->continente;
        }
        else {
            qDebug()<<"No esiste";
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString id = ui->txtAddPeople->text();
    if(id != ""){
        qDebug()<<id<<"cantidad de monas";
        qDebug()<<id.toInt();
        mundo->agregarPoblacion(id.toInt());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString id = ui->txtImprimirFamily->text();
    if(id != ""){
        qDebug()<<id<<"ID INPUT";
        qDebug()<<id.toInt();
        Persona * persona = mundo->buscarPersona(id.toInt());
        if (persona != nullptr) {
           qDebug()<<"qUIERO IMPRIMIR0";
           this->ui->txtTemporal->addItem("Familia de: "+persona->toString());
           this->ui->txtTemporal->addItem(mundo->imprimirUnaFamilia(persona));
        }
        else {
            qDebug()<<"No esiste";
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    mundo->pecar();
}

void MainWindow::on_btnCondenacion_clicked()
{
    mundo->infierno->condenacion();
}
