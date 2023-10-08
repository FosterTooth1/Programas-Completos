#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Cola nula
        error           -3          Cola vacia
        error           0           Sin errores
*/

struct Nodo{
    int valor;  //--> Puede ser otro TDA
    struct Nodo* NodoInferior;
};

//Nivel 3
typedef struct{
    struct Nodo* Cabecera;
    struct Nodo* Ultimo;
    int cursor;
}Cola;

Cola* crearCola(int* error);
void consultarCabecera(Cola p, int* error);
void encolar(Cola *p, int* error, struct Nodo dato);//push
void Desencolar(Cola *p, int* error,struct Nodo *datoExtraido);
bool isEmpty(Cola p, int* error);
void vaciarCola(Cola *p, int* error);
void destruirCola(Cola* p, int* error);
void MostrarCola(Cola *p, int* error, struct Nodo dato);
void consultarUltimo(Cola p, int* error);
