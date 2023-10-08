#include "PilaDinamica.h"

Pila* crearPila(int* error){
    Pila* pilaAsignacion=(Pila*) malloc(sizeof(Pila));
    if(pilaAsignacion==NULL){
        perror("No hay memoria para la pila");
        *error=-2;
        return NULL;
    }
    pilaAsignacion->cima=NULL;
    pilaAsignacion->cursor=0;
    *error=0;
    return pilaAsignacion;
}

void consultarCima(Pila p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la cima: %d\n", p.cima->valor);
    }
    *error=0;
}

//@param p Pila donde se alamcenaran los datos
//@param error variable que gestiona errores
//@param dato Nodo con la información del usuario
void apilar(Pila *p, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    nodoUsuario->valor=dato.valor;
    nodoUsuario->NodoInferior=p->cima;
    p->cima=nodoUsuario;
    p->cursor++;
    *error=0;
}

void Desapilar(Pila *p, int* error,struct Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        struct Nodo* aux=p->cima;
        datoExtraido->valor=aux->valor;
        p->cima=aux->NodoInferior;//p->cima=p->cima->NodoInferior
        aux->NodoInferior=NULL;
        p->cursor--;
        free(aux);
        *error=0;
    } else{
        *error=-3;
    }
}

bool isEmpty(Pila p, int* error){
    if(p.cima==NULL){
        *error=-3;
        return true;
    } else{
        *error=0;
        return false;   
    }
}

void vaciarPila(Pila *p, int* error){
    puts("Vaciando la pila...");
    while(!isEmpty(*p, error)){
        struct Nodo datoExtraido;
        Desapilar(p,error,&datoExtraido);
        printf("Valor extraido: %d\n",datoExtraido.valor);
        *error=0;
    }
}

void destruirPila(Pila* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo pila...");
        free(p);
        puts("Pila Destruida!");
    }
    else{
        puts("No se puede destruir la pila debido a que contiene informacion");
    }
}

void MostrarPila(Pila* p, int* error, struct Nodo Dato){
    printf ("\nDatos en la Pila:\n\n");
    struct Nodo *aux;
    aux = p->cima; //Se trabaja con una copia de la Pila "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }
    int cantidad = p->cursor;
    while (aux) {
        printf ("%d. %d\n", cantidad, aux->valor);
        aux = aux->NodoInferior;
        cantidad--;
    }
}