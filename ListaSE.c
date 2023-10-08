#include "ListaSE.h"

Lista* crearLista(int* error){
    Lista* ListaAsignacion=(Lista*) malloc(sizeof(Lista));
    if(ListaAsignacion==NULL){
        perror("No hay memoria para la Lista");
        *error=-2;
        return NULL;
    }
    ListaAsignacion->Cabecera=NULL;
    ListaAsignacion->Ultimo=NULL;
    ListaAsignacion->cursor=0;
    *error=0;
    return ListaAsignacion;
}

void consultarCabecera(Lista p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la Cabecera: %d\n", p.Cabecera->valor);
    }
    *error=0;
}

void consultarUltimo(Lista p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la ultima posicion de la Lista: %d\n", p.Ultimo->valor);
    }
    *error=0;
}

void consultarPosicion(Lista p, int* error, int n){
    if(isEmpty(p,error)){
        printf("La Lista esta Vacia\n");
    }else{
    struct Nodo* Puntero= p.Cabecera;
    int posicion=1;
    while(posicion<n && Puntero->NodoInferior){
        Puntero=Puntero->NodoInferior;
        posicion++;
    }
    if(posicion!=n){
        printf("No existe esa posicion porque no hay suficientes datos en la lista");
    }else{
        printf("Valor en la %d posicion de la Lista: %d\n", n, Puntero->valor);
    }
    }    
    *error=0;
}

//@param p Lista donde se alamcenaran los datos
//@param error variable que gestiona errores
//@param dato Nodo con la información del usuario
void enListarUltimo(Lista *p, int* error, struct Nodo dato){
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

void enListarCabecera(Lista *p, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    if(isEmpty(*p,error)){
        nodoUsuario->valor=dato.valor;
        //strcpy(nodoUsuario->Valores,dato.Valores);
        nodoUsuario->NodoInferior=NULL;
        p->Cabecera=nodoUsuario;
        p->Ultimo=nodoUsuario;
    }else{
    nodoUsuario->valor=dato.valor;
    //strcpy(nodoUsuario->Valores,dato.Valores);
    nodoUsuario->NodoInferior=p->Cabecera;
    p->Cabecera=nodoUsuario;
    }
    p->cursor++;
    *error=0;
}

void enListarPosicion(Lista *p, int* error, struct Nodo dato, int n){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    nodoUsuario->valor=dato.valor;
    nodoUsuario->NodoInferior=NULL;
    if(isEmpty(*p,error)){
        puts("La lista esta vacia por lo tanto el dato se anadio al principio de la Lista");
        p->Cabecera=nodoUsuario;
        p->Ultimo=nodoUsuario;
    }else{
    struct Nodo* Puntero= p->Cabecera;
    int posicion=1;
    while(posicion<n && Puntero->NodoInferior){
        Puntero=Puntero->NodoInferior;
        posicion++;
    }
    nodoUsuario->NodoInferior=Puntero->NodoInferior;
    Puntero->NodoInferior=nodoUsuario;
    }
    p->cursor++;
    *error=0;
}

void DesenListarCabecera(Lista *p, int* error,struct Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        struct Nodo *aux = NULL; //Se trabaja con una copia de la Lista "Principal"
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

void DesenListarUltimo(Lista *p, int* error,struct Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        struct Nodo *aux = NULL; //Se trabaja con una copia de la Lista "Principal"
        if (p->cursor>1){
            aux=p->Cabecera;
            while (aux->NodoInferior!=p->Ultimo){
                aux=aux->NodoInferior;
            }
            datoExtraido->valor=p->Ultimo->valor;
            p->Ultimo=aux;
            p->Ultimo->NodoInferior=NULL;
            aux->NodoInferior=NULL;    
        }else if(p->cursor==1){
            aux=p->Cabecera;
            p->Cabecera=NULL;
            p->Ultimo=NULL;
            datoExtraido->valor=aux->valor;
        }
        p->cursor--;
    }else{
    *error=-3;
    }
}

void DesenListarPosicion(Lista *p, int* error,struct Nodo *datoExtraido, int n){
    if(!isEmpty(*p,error)){
        struct Nodo *aux = NULL; //Se trabaja con una copia de la Lista "Principal"
        struct Nodo *aux2 = NULL;
        if (p->cursor>1){
            aux = p->Cabecera;
            for (int i=1; i<(n-1); ++i){ //Si no funciona correctamente cambiar (n-1) a solo n
                aux = aux->NodoInferior;
            }
            aux2 = aux->NodoInferior;
            datoExtraido->valor=aux2->valor;
            aux->NodoInferior = aux->NodoInferior->NodoInferior;
            if(aux->NodoInferior == NULL){
                p->Ultimo = aux;
            }
            free(aux2);
        }else if(p->cursor==1){
            aux=p->Cabecera;
            datoExtraido->valor=aux->valor;
            p->Cabecera=NULL;
            p->Ultimo=NULL;
        }
        p->cursor--;
    }else{
    *error=-3;
    }
}

bool isEmpty(Lista p, int* error){
    if(p.Cabecera==NULL){
        *error=-3;
        return true;
    } else{
        *error=0;
        return false;   
    }
}

void vaciarLista(Lista *p, int* error){
    puts("Vaciando la Lista...");
    while(!isEmpty(*p, error)){
        struct Nodo datoExtraido;
        DesenListarCabecera(p,error,&datoExtraido);
        printf("Valor extraido: %d\n",datoExtraido.valor);
        *error=0;
    }
}

void vaciarMudo(Lista *p, int* error){
    while(!isEmpty(*p, error)){
        struct Nodo datoExtraido;
        DesenListarCabecera(p,error,&datoExtraido);
        *error=0;
    }
}

void destruirLista(Lista* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo Lista...");
        free(p);
        puts("Lista Destruida!");
    }
    else{
        puts("No se puede destruir la Lista debido a que contiene informacion");
    }
}

void MostrarLista(Lista* p, int* error, struct Nodo Dato){
    printf ("\nDatos en la Lista:\n\n");
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }
    int cantidad = 1;
    while (aux) {
        //printf ("%d. %s\n", cantidad, aux->Valores);
        printf ("%d. %d\n", cantidad, aux->valor);
        aux = aux->NodoInferior;
        cantidad++;
    }
}

void Burble_sort_Ascendente(Lista *p, int* error){
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }else{
        while(aux!=NULL){
            struct Nodo *aux2 = aux->NodoInferior;
            while(aux2!=NULL){
                if(aux->valor>aux2->valor){
                    int aux3 = aux2->valor;
                    aux2->valor = aux->valor;
                    aux->valor=aux3;
                }
                aux2=aux2->NodoInferior;
            }
            aux=aux->NodoInferior;
        }
    }
}

void Burble_sort_Descendente(Lista *p, int* error){
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }else{
        while(aux!=NULL){
            struct Nodo *aux2 = aux->NodoInferior;
            while(aux2!=NULL){
                if(aux->valor<aux2->valor){
                    int aux3 = aux2->valor;
                    aux2->valor = aux->valor;
                    aux->valor=aux3;
                }
                aux2=aux2->NodoInferior;
            }
            aux=aux->NodoInferior;
        }
    }
}


void GuardarEnArreglo(Lista* p, int* error, int* datos){
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }else{
        int cantidad = 0;
        while (aux) {
            datos[cantidad]= aux->valor;       
            aux = aux->NodoInferior;
            cantidad++;
        }
    }
}

void selection_sort(Lista* p, int* error, int* datos){
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
        *error=-3;
    }else{
        int cantidad = 0;
        while (aux) {
            datos[cantidad]= aux->valor;       
            aux = aux->NodoInferior;
            cantidad++;
        }
        int temp;
        for (int i=0; i<(p->cursor-1); i++){
            for (int j =(i+1); j<p->cursor; j++){
                if (datos[i] > datos[j]){
                    temp = datos[i];
                    datos[i] = datos[j];
                    datos[j] = temp;
                }
            }
        }
        *error=0;
    }
}

void insertion_sort(Lista* p, int* error, int* datos){
    struct Nodo *aux;
    aux = p->Cabecera; //Se trabaja con una copia de la Lista "Principal"
    if (aux == NULL) {
        perror("No hay Datos\n");
        *error=-3;
    }else{
        int cantidad = 0;
        while (aux) {
            datos[cantidad]= aux->valor;       
            aux = aux->NodoInferior;
            cantidad++;
        }
        int temp, j;
        for (int i = 1; i<p->cursor; i++){	   
		    temp = datos[i];
		    j = i-1;
		    //Comparar el valor selecionado con todos los valores anteriores
		    while (j >= 0 && datos[j] > temp){
			    //Insertar el valor donde corresponda
			    datos[j+1] = datos[j];
			    j--;
		    }
		    datos[j+1] = temp;
	    } 
        *error=0;
    }
}

void sort(int *arreglo, int tam){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        int arrIzq[mitad];
        int arrDer[tam-mitad];
        for(i=0, k=0; i<mitad; i++, k++){
            arrIzq[i]=arreglo[k];
        }
        for(j=0; j< (tam-mitad); j++, k++){
            arrDer[j]=arreglo[k];
        }
        sort(arrIzq,mitad);
        sort(arrDer,tam-mitad);
        mezcla(arrIzq,mitad, arrDer,tam-mitad,arreglo);
    }
}

void mezcla(int *arrIzq, int tamIzq, int *arrDer, int tamDer, int* arreglo){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arrIzq[i]<arrDer[j]){
            arreglo[k]=arrIzq[i];
            i++;   
        } else{
            arreglo[k]=arrDer[j];
            j++;  
        }
        k++;
    }
    while(j<tamDer){
        arreglo[k]=arrDer[j];
        j++;
        k++;
    }
    while(i<tamIzq){
        arreglo[k]=arrIzq[i];
        i++;
        k++;
    }
}

void BuscarElemento(Lista *p, int* error, struct Nodo *dato){
    struct Nodo* Aux= p->Cabecera;
    int Posicion=1;
    int encontrados=0; 
    if(Aux==NULL){
        perror("No hay Datos\n");
        *error=-3;
    }else{
        while(Aux){
            if(Aux->valor==dato->valor){
                printf("\nDato %d encontrado en la posicion %d", dato->valor, Posicion);
                encontrados++;
            }
            Posicion++;
            Aux=Aux->NodoInferior;
        }
        if(encontrados==0){
            puts("El dato no se encuentra en la lista");
        }

    }
    *error=0;
}