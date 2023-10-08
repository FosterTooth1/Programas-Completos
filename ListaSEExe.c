#include "ListaSE.h"

int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    int n;
    char Dato[50];
    int* datos= (int*)malloc(sizeof(int));
    Lista *p=crearLista(&error);
    struct Nodo dato;
    srand(time(NULL));
    int opc;
    do{
        printf("\n------------CONTROL DE LISTA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Mostrar el valor en la primera posicion de la Lista\n");
        printf("3. Mostrar el valor en la ultima posicion de la Lista\n");
        printf("4. Mostrar el valor en la posicion 'n' de la lista\n");
        printf("5. Agregar Datos al principio de la lista\n");
        printf("6. Agregar Datos al final de la lista\n");
        printf("7. Agregar Datos en la posicion 'n'\n");
        printf("8. Remover Datos del principio de la Lista\n");
        printf("9. Remover Datos del final de la Lista\n");
        printf("10. Remover Datos de la posicion 'n' de la Lista\n");
        printf("11. Ordenar Lista ascendente o descendente haciendo una nueva lista\n");
        printf("12. Ordenar Lista de forma ascendente o descendente modificando la lista actual\n");
        printf("13. Buscar un dato en la lista\n");
        printf("14. Vaciar toda la Lista\n");
        printf("15. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    switch (opc){
    case 1:
        MostrarLista(p, &error,dato);
        break;

    case 2:
        consultarCabecera(*p, &error);
        break;

    case 3:
        consultarUltimo(*p,&error);
        break;

    case 4:
        puts("Digite la posicion de donde desea obtener el dato de la Lista:");
        fflush(stdin);
        scanf("%d", &n);
        consultarPosicion(*p,&error,n);
        break;

    case 5:
        /*
        puts("Cuantos valores quieres agregar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            dato.valor= 1 + rand() % (10-1+1);
            enListarCabecera(p,&error,dato);
        }
        */
        //Si el usuario tiene que ingresar los datos cambiar el case nada mas
        puts("Cuantos valores quieres agregar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            puts("Ingresa un valor:");
            fflush(stdin);
            //gets(Dato);
            //strcpy(dato.Valores,Dato);
            scanf("%d",&dato.valor);
            enListarCabecera(p,&error,dato);
        }
        puts("Datos agregados correctamente!");
        break;

    case 6:
        /*
        puts("Cuantos valores quieres agregar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            dato.valor= 1 + rand() % (10-1+1);
            enListarUltimo(p,&error,dato);
        }
        */
        //Si el usuario tiene que ingresar los datos cambiar el case nada mas
        puts("Cuantos valores quieres agregar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            puts("Ingresa un valor:");
            fflush(stdin);
            scanf("%d",&dato.valor);
            enListarUltimo(p,&error,dato);
        }
        puts("Datos agregados correctamente!");
        break;
    case 7:
        /*
        puts("Cuantos valores quieres agregar en esta posicion a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        puts("A partir de que posicion quieres agregar los datos:");
        fflush(stdin);
        scanf("%d", &n);
        for(int i=0; i<cantidadDatos; i++){
            dato.valor= 1 + rand() % (10-1+1);
            enListarPosicion(p,&error,dato, n);
        }
        */
        //Si el usuario tiene que ingresar los datos cambiar el case nada mas
        puts("Cuantos valores quieres agregar en esta posicion a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        puts("A partir de que posicion quieres agregar los datos:");
        fflush(stdin);
        scanf("%d", &n);
        for(int i=0; i<cantidadDatos; i++){
            puts("Ingresa un valor:");
            fflush(stdin);
            scanf("%d",&dato.valor);
            enListarPosicion(p,&error,dato, n);
        }
        puts("Datos agregados correctamente!");
        break;

    case 8:
        puts("Cuantos valores quieres quitar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            DesenListarCabecera(p,&error,&dato);
            printf("Valor extraido: %d\n",dato.valor);
        }
        break;

    case 9:
        puts("Cuantos valores quieres quitar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        for(int i=0; i<cantidadDatos; i++){
            DesenListarUltimo(p,&error,&dato);
            printf("Valor extraido: %d\n",dato.valor);
        }
        break;
        
    case 10:
        puts("Cuantos valores quieres quitar a la Lista?");
        fflush(stdin);
        scanf("%d",&cantidadDatos);
        puts("A partir de que posicion quieres eliminar los datos:");
        fflush(stdin);
        scanf("%d", &n);
        for(int i=0; i<cantidadDatos; i++){
            if(n<p->cursor){
                if(n==1){
                    DesenListarCabecera(p,&error,&dato);
                }else{
                    DesenListarPosicion(p,&error,&dato, n);
                }
            }else{
                DesenListarUltimo(p,&error,&dato);
            }
            printf("Valor extraido: %d\n",dato.valor);
        }
        break;       

    case 11:
        puts("De que manera quiere ordenar sus datos, ascendente o descendente?");
        puts("1.Ascendente");
        puts("2.Descendente");
        fflush(stdin);
        scanf("%d",&n);
        int y=p->cursor;
        /*
        En caso de utilizar cualquiera de las otras dos, solo quitar GuardarEnArreglo y sort
        // selection_sort(p,&error, datos);
        //insertion_sort(p,&error, datos);
        */
        GuardarEnArreglo(p,&error,datos);
        sort(datos, y);
        if(n==1){
            vaciarMudo(p, &error);
            for(int i=0; i<y; i++){
                dato.valor=datos[i];
                enListarUltimo(p,&error, dato);
            }
            puts("Lista reorganizada Correctamente!");
        }else if(n==2){
            vaciarMudo(p, &error);
            for(int i=0; i<y; i++){
                dato.valor=datos[i];
                enListarCabecera(p,&error, dato);
            }
            puts("Lista reorganizada Correctamente!");
        }
        break;

    case 12:
    puts("De que manera quiere ordenar sus datos, ascendente o descendente?");
        puts("1.Ascendente");
        puts("2.Descendente");
        fflush(stdin);
        scanf("%d",&n);
        if (n==1)
        {
        Burble_sort_Ascendente(p,&error);            
        }else if(n==2){
        Burble_sort_Descendente(p,&error);
        }
        puts("La lista se ordeno correctamente");
        break;

    case 13:
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.valor);
        BuscarElemento(p,&error, &dato);
        break;
    
    case 14:
        vaciarLista(p,&error);
        puts("Lista Vaciada correctamente!");
        break;

    default:
        break;
    }

    }while (opc!=15);
    vaciarLista(p,&error);
    destruirLista(p, &error);
    return error;
}