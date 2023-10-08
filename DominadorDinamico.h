#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Pila nula
        error           -3          Pila vacia
        error           0           Sin errores
*/

struct Nodo{
    int valor;  //--> Puede ser otro TDA
    struct Nodo* NodoInferior;
};

//Nivel 3
typedef struct{
    struct Nodo* cima;
    int cursor;
}Pila;

Pila* crearPila(int* error);
void consultarCima(Pila p, int* error);
void apilar(Pila *p, int* error, struct Nodo dato);//push
void Desapilar(Pila *p, int* error,struct Nodo *datoExtraido);
bool isEmpty(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
void destruirPila(Pila* p, int* error);
void MostrarPila(Pila *p, int* error, struct Nodo dato);
void VerificarDominador(Pila *p, int* error);