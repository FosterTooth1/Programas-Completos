#include "DominadorDinamico.h"

int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Pila *p=crearPila(&error);
    struct Nodo dato;
    srand(time(NULL));
    int opc;
    do{
        printf("\n------------CONTROL DE PILA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Mostrar la cima de la Pila\n");
        printf("3. Agregar Datos\n");
        printf("4. Remover Datos\n");
        printf("5. Vaciar toda la Pila\n");
        printf("6. Verificar si la cima es un numero dominador\n");
        printf("7. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    switch (opc){
    case 1:
        MostrarPila(p, &error,dato);
        break;

    case 2:
        consultarCima(*p, &error);
        break;

    case 3:
        puts("Cuantos valores quieres agregar a la pila?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            dato.valor= 1 + rand() % (10-1+1);
            apilar(p,&error,dato);
        
        //Si el usuario tiene que ingresar los datos cambiar el case nada mas

       /*
        puts("¿Cuantos valores quieres agregar a la pila?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            puts("Ingresa un valor:");
            fflush(stdin);
            scanf("%d",&dato.valor);
            apilar(p,&error,dato);
        }
       */
        
        }
        puts("Datos agregados correctamente!");
        break;

    case 4:
        puts("Cuantos valores quieres quitar a la pila?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            Desapilar(p,&error,&dato);
            printf("Valor extraido: %d\n",dato.valor);
        }
        break;

    case 5:
        vaciarPila(p,&error);
        break;

    case 6:
        VerificarDominador(p,&error);

    default:
        break;
    }

    }while (opc!=7);

    vaciarPila(p,&error);
    destruirPila(p, &error);
    return error;

}

