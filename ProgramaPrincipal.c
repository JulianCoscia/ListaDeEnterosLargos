#include <stdio.h>
#include <stdlib.h>
#include "TDA_EnteroLargo.h"
#include "TDA_Lista.h"

void ejecutarProgramaPrincipal(){
    printf("ejecutando programa principal");
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
