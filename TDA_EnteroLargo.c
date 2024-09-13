#include "TDA_EnteroLargo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TEnteroLargo crearEnteroLargo(){
    TEnteroLargo nuevo = (TEnteroLargo) malloc(sizeof(struct enteroLargo));
    nuevo->digitos[0] = '\0';

    return nuevo;
}

void inicializarEnteroLargo(TEnteroLargo nuevo, char* valor){
    if (nuevo != NULL && valor != NULL){
        int cantDigitos = strlen(valor) -1;
        int pos = MAX_LENGTH-2;                 //Posicion del digito de menor valor del entero
        nuevo->digitos[MAX_LENGTH-1] = '\0';

        while (cantDigitos >= 0){
            nuevo->digitos[pos] = valor[cantDigitos];
            pos--;
            cantDigitos--;
        }

        //Rellena el resto del entero largo con 0 en caso que el numero tenga menos de 100 digitos.
        while(pos >= 0){
            nuevo->digitos[pos] = '0';
            pos--;
        }
    }
}

void eliminarEnteroLargo(TEnteroLargo aEliminar){
    if (aEliminar != NULL){
        free(aEliminar);
    }
}

void mostrarEnteroLargo(TEnteroLargo aMostrar){
    if (aMostrar != NULL){
        printf("\nNumero: %s\n", aMostrar->digitos);
    }
}

int compararEnterosLargos(TEnteroLargo a, TEnteroLargo b){
    int respuesta = 2;

    if (a != NULL && b != NULL){
        respuesta = strcmp(a->digitos, b->digitos);
    }

    return respuesta;
}

TEnteroLargo sumarEnterosLargos(TEnteroLargo a, TEnteroLargo b){
    if (a != NULL && b != NULL){
        TEnteroLargo resultado = crearEnteroLargo();
        const char cero = '0';                              //Se utiliza para convertir los caracteres a numeros
        int acarreo = 0;
        int resul = 0;
        int pos = MAX_LENGTH-2;                             //Posicion del ultimo digito del numero

        while(pos >= 0){
            //Se suman los digitos
            resul = a->digitos[pos] - cero;
            resul = resul + (b->digitos[pos] - cero);
            resul = resul + acarreo;
            acarreo = 0;

            if (resul >= 10){
                resul = resul % 10;
                acarreo = 1;
            }

            resultado->digitos[pos] = resul + cero;
            pos--;
        }

        //Si se termino la suma y hay acarreo, se produce error.
        if (acarreo){
            resultado->digitos[0] = 'X';
            resultado->digitos[1] = '\0';
        }else{
            resultado->digitos[MAX_LENGTH-1] = '\0';
        }

        return resultado;
    }
    return NULL;
}
