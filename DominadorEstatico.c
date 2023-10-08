#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Este programa genera los datos aleatorios que el usuario desee

void MostrarMenu();
void MostrarPila (); 
void AgregarElementosPila ();
void RemoverElementoPila();
void VerificarDominador();

struct PILA {
    int Dato;
    struct PILA *Siguiente; 
}; //Declaro la estructura de la Pila

struct PILA *Pila = NULL; //Declaro la Pila "Principal"

int main () {
    MostrarMenu();
    return 0;
}

void MostrarMenu()
{
    int opc;
    do{
        printf("\n------------CONTROL DE PILA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Agregar Datos\n");
        printf("3. Remover Datos\n");
        printf("4. Checar si la cima de la pila es un numero dominador\n");
        printf("5. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 5);

    switch (opc){
    case 1:
        MostrarPila();
        break;
    case 2:
        AgregarElementosPila();
        break;
    case 3:
        RemoverElementoPila();
        break;
    case 4:
        VerificarDominador();

    default:
        break;
    }
}

void AgregarElementosPila () {

    srand(time(NULL));
    int cantidad;

    printf ("\nCuantos elementos desea: ");
    scanf ("%d", &cantidad);

    for (size_t i = 0; i < cantidad; i++){

        struct PILA *unidad = malloc(sizeof(struct PILA)); //Inicializo la Pila "Auxiliar" que irá sobreescribiendo datos en la pila "Principal"

        int num =  (rand() % (10 - 1 + 1)) + 1; //(max - min +1) + min
        unidad->Dato = num; 

        if (Pila == NULL){
            Pila = unidad; //Se pasa el primer dato de la Pila "Auxiliar" a la Pila "Principal"
            unidad->Siguiente = NULL; //Se establece el "tope" de el inicio de la Pila
        }
        else {
            unidad->Siguiente = Pila; //Se agregan los datos almacenados de manera encadenada hacia "abajo" de la Pila "Principal" a la "Auxiliar"
            Pila = unidad; //La pila Principal ya almacena todos los datos suministrados
        }

        unidad = NULL;
        free (unidad);

    }  
 
    MostrarMenu ();
}

void MostrarPila () {

    printf ("\nDatos en la Pila\n\n");

    struct PILA *aux;

    aux = Pila; //Se trabaja con una copia de la Pila "Principal"

    if (aux == NULL) {
        printf ("No hay Datos\n");
        MostrarMenu();
    }

    int cantidad = 1;
    while (aux) {
        printf ("%d. %d\n", cantidad, aux->Dato);
        aux = aux->Siguiente;
        cantidad++;
    }
    MostrarMenu();
}

void RemoverElementoPila() {

    int cantidad;

    printf ("\nCuantos Datos deseas remover de la Pila ?: ");
    scanf ("%d", &cantidad);

    struct PILA *aux = Pila; //La Pila Auxiliar sirve para guiar al "for" siguiente...

    for (int i = 0; i < cantidad; i++)
    {
        if (aux = NULL) {
            printf ("\nLa Pila esta vacia\n");
            MostrarMenu ();
        }
        else {
            Pila = Pila->Siguiente;
            free (aux);
            aux = Pila;
        }
    }
    MostrarMenu ();
}

void VerificarDominador() {

    printf ("\nCorroborando dominador:\n\n");

    struct PILA *aux;

    aux = Pila; //Se trabaja con una copia de la Pila "Principal"

    if (aux == NULL) {
        printf ("No hay Datos\n");
        MostrarMenu();
    }

    int cantidad = 0;
    int* datos= (int*)malloc(sizeof(int));

    while (aux) {
        datos[cantidad]= aux->Dato;       
        aux = aux->Siguiente;
        cantidad++;
    }

    int sumatoria = 0;

    if(cantidad==1){
        printf("Solo hay un dato, por lo tanto, %d es un numero dominador\n", aux->Dato);
        MostrarMenu();
    }else{
        for(int i=1; i<cantidad; i++){
        sumatoria+= datos[i];
        }
    }    

    if(sumatoria<datos[0]){
        printf("La cima de la pila con valor '%d' es un numero mayor que la suma de los datos debajo de la pila '%d', por lo tanto la cima es un numero dominador.\n", datos[0], sumatoria);
    }
    
    if(sumatoria>datos[0]){
        printf("La cima de la pila con valor '%d' no es un numero mayor que la suma de los datos debajo de la pila '%d', por lo tanto la cima no es un numero dominador.\n", datos[0], sumatoria);
    }

    MostrarMenu();
}