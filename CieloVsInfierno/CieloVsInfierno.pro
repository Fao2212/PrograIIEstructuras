QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Accion.cpp \
    Acciones.cpp \
    Angel.cpp \
    Arbol.cpp \
    ArbolAngeles.cpp \
    ArbolGenealogico.cpp \
    ArbolMundo.cpp \
    Cielo.cpp \
    Controller.cpp \
    Demonio.cpp \
    Familia.cpp \
    FileManager.cpp \
    HashCielo.cpp \
    Heap.cpp \
    Infierno.cpp \
    ListaDoble.cpp \
    ListaSimple.cpp \
    Mundo.cpp \
    Pais.cpp \
    Persona.cpp \
    Random.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Accion.h \
    Acciones.h \
    Angel.h \
    Arbol.h \
    ArbolAngeles.h \
    ArbolGenealogico.h \
    ArbolMundo.h \
    Cielo.h \
    Controller.h \
    Demonio.h \
    Familia.h \
    FileManager.h \
    HashCielo.h \
    Heap.h \
    Infierno.h \
    ListaDoble.h \
    ListaSimple.h \
    Mundo.h \
    Nodo.h \
    NodoA.h \
    NodoAG.h \
    NodoAngeles.h \
    Pais.h \
    Persona.h \
    Random.h \
    includes.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
