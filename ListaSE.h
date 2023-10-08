#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Lista nula
        error           -3          Lista vacia
        error           0           Sin errores
*/

struct Nodo{
    int valor;  //--> Puede ser otro TDA
    //char Valores[50];
    struct Nodo* NodoInferior;
};

//Nivel 3
typedef struct{
    struct Nodo* Cabecera;
    struct Nodo* Ultimo;
    int cursor;
}Lista;

Lista* crearLista(int* error);
void consultarCabecera(Lista p, int* error);
void consultarUltimo(Lista p, int* error);
void consultarPosicion(Lista p, int* error, int n);
void enListarUltimo(Lista *p, int* error, struct Nodo dato);//push
void enListarCabecera(Lista *p, int* error, struct Nodo dato);
void enListarPosicion(Lista *p, int* error, struct Nodo dato, int n);
void DesenListarCabecera(Lista *p, int* error,struct Nodo *datoExtraido);
void DesenListarUltimo(Lista *p, int* error,struct Nodo *datoExtraido);
void DesenListarPosicion(Lista *p, int* error,struct Nodo *datoExtraido, int n);
bool isEmpty(Lista p, int* error);
void vaciarLista(Lista *p, int* error);
void vaciarMudo(Lista *p, int* error);
void destruirLista(Lista* p, int* error);
void MostrarLista(Lista *p, int* error, struct Nodo dato);
void selection_sort(Lista* p, int* error, int* datos);
void insertion_sort(Lista* p, int* error, int* datos);
void sort(int *arreglo, int tam);
void mezcla(int *arrIzq, int tamIzq, int *arrDer, int tamDer, int* arreglo);
void GuardarEnArreglo(Lista* p, int* error, int* datos);
void Burble_sort_Ascendente(Lista *p, int* error);
void Burble_sort_Descendente(Lista *p, int* error);
void BuscarElemento(Lista *p, int* error, struct Nodo *dato);