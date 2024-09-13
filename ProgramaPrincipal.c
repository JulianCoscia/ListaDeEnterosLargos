#include <stdio.h>
#include <stdlib.h>
#include "TDA_EnteroLargo.h"
#include "TDA_Lista.h"
//remove pide un enterolargo pero le paso un string.........
int realizarOperaciones(){
        fflush(stdin);
        int op = 0;

        printf("\n\nQue operaciones desea realizar?\n");
        printf("1) Sumar toda la lista.\n");
        printf("2) Resta (Sin implementar).\n");
        printf("3) Multiplicacion (Sin implementar).\n");
        printf("4) Division (Sin implementar).\n");
        printf("5) Volver al menu anterior.\n");
        printf("Operacion: ");
        scanf("%i", &op);

        switch(op){
            case 1:{
                printf("\nIniciando la sumatoria...\n");

                TEnteroLargo resultado = crearEnteroLargo();
                TEnteroLargo aSumar = frente();
                char* cero = "0";
                inicializarEnteroLargo(resultado, cero);

                for (int i = 0; i < tamanio(); i++){
                    resultado = sumarEnterosLargos(resultado, aSumar);
                    aSumar = anterior(aSumar);
                }

                printf("Resultado de la sumatoria: ");
                mostrarEnteroLargo(resultado);
                eliminarEnteroLargo(resultado);
                break;
            }
            case 5:{
                return 1;
                break;
            }
        }//Fin del switch-case
    return 1;
}

void ejecutarProgramaPrincipal(){
    printf("\n\nIniciado el programa.");
    construir();
    int opcion = -1;

    while(opcion < 0 || opcion > 9){
        printf("\n\nQue operacion desea realizar?\n");
        printf("1) Ingresar un entero largo.\n");
        printf("2) Ingresar un entero largo aleatorio.\n");
        printf("3) Realizar operaciones.\n");
        printf("4) Eliminar un entero largo ingresado.\n");
        printf("5) Mostrar el contenido de la lista.\n");
        printf("6) Consultar cual fue el primer entero ingresado a la lista.\n");
        printf("7) Consultar cual fue el ultimo entero ingresado a la lista.\n");
        printf("8) Consultar el tamanio de la lista.\n");
        printf("9) Consultar si la lista esa vacia.\n");
        printf("0) Salir del programa.\n");
        printf("Operacion: ");

        scanf("%i",&opcion);

        switch(opcion){
        case 1:{
            char* aIngresar = (char*)malloc(sizeof(char)*(MAX_LENGTH));

            printf("\n\nEntero a ingresar (Maximo 100 digitos): ");
            scanf("%100s", aIngresar);
            fflush(stdin);

            TEnteroLargo nuevo = crearEnteroLargo();
            inicializarEnteroLargo(nuevo, aIngresar);
            insertarFront(nuevo);
            opcion = -1;
            break;
        }
        case 2:{
            imprimirTutorial();
            opcion = -1;
            break;
        }
        case 3:{
            realizarOperaciones();
            opcion = -1;
            break;
        }
        case 4:{
            char* aRemover = (char*)malloc(sizeof(char)*(MAX_LENGTH));
            fflush(stdin);
            printf("\Entero largo que desea remover: ");
            scanf("%100s", aRemover);

            removeFirst(aRemover);
            free(aRemover);
            printf("\nElemento eliminado.\n");
            opcion = -1;
            break;
        }
        case 5:{
            toString();
            opcion = -1;
            break;
        }
        case 6:{
            printf("\nEl primer elemento ingresado fue: ");
            TEnteroLargo primero = cola();
            mostrarEnteroLargo(primero);
            opcion = -1;
            break;
        }
        case 7:{
            printf("\nEl ultimo elemento ingresado fue: ");
            TEnteroLargo ultimo = frente();
            mostrarEnteroLargo(ultimo);
            opcion = -1;
            break;
        }
        case 8:{
            printf("\nEl tamanio de la lista es de %i enteros largos.\n", tamanio());
            opcion = -1;
            break;
        }
        case 9:{
            if (isEmpty()){
                printf("\nLa lista esta vacia.\n");
            }else{
                printf("\nLa lista no esta vacia.\n");
            }
            opcion = -1;
            break;
        }
        case 0:{
            printf("\nLiberando el espacio en memoria...\n");
            destruir();
            printf("\nEspacio en memoria liberado\n\n");
            break;
        }
        default:{
            printf("\nEl valor ingresado no corresponde a ninguna operacion.\n");
            break;
        }
    }

    }//Fin del while

    return 0;
}

void imprimirTutorial(){
    printf("Mostrando info");
}

int main(){
    int operacion = 0;
    printf("  ###########################################################################################\n");
    printf("  #                                                                                         #\n");
    printf("  #                    Bienvenido a la lista sumadora de enteros largos                     #\n");
    printf("  #                                                                                         #\n");
    printf("  ###########################################################################################\n\n");

    printf(" Que desea hacer: \n");
    printf(" 1) Iniciar el programa. \n");
    printf(" 2) Como funciona el programa?. \n");
    printf(" 3) Salir. \n");
    printf(" Operacion: ");
    scanf("%i", &operacion);

    switch(operacion){
        case 1:{
            ejecutarProgramaPrincipal();
            break;
        }
        case 2:{
            imprimirTutorial();
            break;
        }
        case 3:{
            return 0;
            break;
        }
        default:{
            printf("\nEl valor ingresado no corresponde a ninguna operacion.\n");
            break;
        }
    }
    return 0;
}
