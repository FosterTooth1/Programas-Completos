#include "ColaDinamica.h"

int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Cola *p=crearCola(&error);
    struct Nodo dato;
    srand(time(NULL));
    int opc;
    do{
        printf("\n------------CONTROL DE COLA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Mostrar el valor en la primera posicion de la Cola\n");
        printf("3. Mostrar el valor en la ultima posicion de la Cola\n");
        printf("4. Agregar Datos\n");
        printf("5. Remover Datos\n");
        printf("6. Vaciar toda la Cola\n");
        printf("7. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    switch (opc){
    case 1:
        MostrarCola(p, &error,dato);
        break;

    case 2:
        consultarCabecera(*p, &error);
        break;

    case 3:
        consultarUltimo(*p,&error);
        break;

    case 4:
        /*
        puts("Cuantos valores quieres agregar a la Cola?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            dato.valor= 1 + rand() % (10-1+1);
            encolar(p,&error,dato);
        }
        */
        //Si el usuario tiene que ingresar los datos cambiar el case nada mas
        puts("¿Cuantos valores quieres agregar a la Cola?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            puts("Ingresa un valor:");
            fflush(stdin);
            scanf("%d",&dato.valor);
            encolar(p,&error,dato);
        }

        puts("Datos agregados correctamente!");
        break;

    case 5:
        puts("Cuantos valores quieres quitar a la Cola?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            Desencolar(p,&error,&dato);
            printf("Valor extraido: %d\n",dato.valor);
        }
        break;

    case 6:
        vaciarCola(p,&error);
        break;

    default:
        break;
    }

    }while (opc!=7);

    vaciarCola(p,&error);
    destruirCola(p, &error);
    return error;

}