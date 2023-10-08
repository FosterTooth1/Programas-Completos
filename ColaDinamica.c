#include "ColaDinamica.h"

Cola* crearCola(int* error){
    Cola* ColaAsignacion=(Cola*) malloc(sizeof(Cola));
    if(ColaAsignacion==NULL){
        perror("No hay memoria para la Cola");
        *error=-2;
        return NULL;
    }
    ColaAsignacion->Cabecera=NULL;
    ColaAsignacion->Ultimo=NULL;
    ColaAsignacion->cursor=0;
    *error=0;
    return ColaAsignacion;
}

void consultarCabecera(Cola p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la primera posicion de la cola: %d\n", p.Cabecera->valor);
    }
    *error=0;
}

void consultarUltimo(Cola p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la ultima posicion de la cola: %d\n", p.Ultimo->valor);
    }
    *error=0;
}

//@param p Cola donde se alamcenaran los datos
//@param error variable que gestiona errores
//@param dato Nodo con la información del usuario
void encolar(Cola *p, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }else{
        nodoUsuario->valor=dato.valor;
        nodoUsuario->NodoInferior=NULL;
    }
    if(isEmpty(*p,error)){
        p->Cabecera=nodoUsuario;
        p->Ultimo=nodoUsuario;
    }else{
        p->Ultimo->NodoInferior=nodoUsuario;
        p->Ultimo=nodoUsuario;
    }
    p->cursor++;
    *error=0;
}

void Desencolar(Cola *p, int* error,struct Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        struct Nodo *aux = NULL; //Se trabaja con una copia de la Cola "Principal"
        if (p->cursor>1){
            aux=p->Cabecera;
            p->Cabecera=p->Cabecera->NodoInferior;
            aux->NodoInferior=NULL;    
        }else if(p->cursor==1){
            aux=p->Cabecera;
            p->Cabecera=NULL;
            p->Ultimo=NULL;
        }
        p->cursor--;
        datoExtraido->valor=aux->valor;
    }else{
    *error=-3;
    }
}

bool isEmpty(Cola p, int* error){
    if(p.Cabecera==NULL){
        *error=-3;
        return true;
    } else{
        *error=0;
        return false;   
    }
}

void vaciarCola(Cola *p, int* error){
    puts("Vaciando la Cola...");
    while(!isEmpty(*p, error)){
        struct Nodo datoExtraido;
        Desencolar(p,error,&datoExtraido);
        printf("Valor extraido: %d\n",datoExtraido.valor);
        *error=0;
    }
}

void destruirCola(Cola* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo Cola...");
        free(p);
        puts("Cola Destruida!");
    }
    else{
        puts("No se puede destruir la Cola debido a que contiene informacion");
    }
}

void MostrarCola(Cola* p, int* error, struct Nodo Dato){
    printf ("\nDatos en la Cola:\n\n");
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Cola "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }
    int cantidad = 1;
    while (aux) {
        printf ("%d. %d\n", cantidad, aux->valor);
        aux = aux->NodoInferior;
        cantidad++;
    }
}