#include "TDA_Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tam;
TNodo lista;                    //Apunta al primer elemento de la lista.

void construir(){
    tam = 0;
    lista = NULL;
}

void insertarFront(TEnteroLargo aInsertar){
    if (aInsertar != NULL){
        TNodo nuevo = (TNodo) malloc(sizeof(struct nodo));
        nuevo->sig = NULL;
        nuevo->elem = aInsertar;

        if (lista != NULL){
            nuevo->ant = lista;
            lista->sig = nuevo;
            lista = nuevo;
        }else{
            nuevo->ant = NULL;
            lista = nuevo;
        }
        tam++;
    }
}

void insertarBack(TEnteroLargo aInsertar){
    if (aInsertar!= NULL){
        TNodo nuevo = (TNodo)malloc(sizeof(struct nodo));
        nuevo->ant = NULL;
        nuevo->elem = aInsertar;

        if (lista != NULL){
            TNodo nav = lista;

            while(nav->ant != NULL){
                nav= nav->ant;
            }

            nav->ant = nuevo;
            nuevo->sig = nav;
        }else{
            lista = nuevo;
            nuevo->sig = NULL;
        }

        tam++;
    }
}

TEnteroLargo removeFront(){
    TEnteroLargo salida = crearEnteroLargo();
    salida = NULL;

    if(lista != NULL){
        salida = lista->elem;
        TNodo aEliminar = lista;
        lista = lista->ant;

        if (lista != NULL){
            lista->sig = NULL;
        }

        eliminarEnteroLargo(aEliminar->elem);
        free(aEliminar);
        tam--;
    }

    return salida;
}


TEnteroLargo removeBack(){
    TEnteroLargo salida = crearEnteroLargo();
    salida = NULL;

    if(lista != NULL){
        TNodo nav = lista;

        while(nav->ant != NULL){
            nav = nav->ant;
        }

        if (nav->sig != NULL){
            nav->sig->ant = NULL;
        }

        salida = nav->elem;
        eliminarEnteroLargo(nav->elem);
        free(nav);
        tam--;
    }

    return salida;
}

int removeAll(TEnteroLargo aEliminar){
    if (aEliminar != NULL){
        int cont = 0;

        if(lista != NULL){
            TNodo nav = lista;

            while (nav != NULL){
                if(strcmp(nav->elem->digitos, aEliminar->digitos) == 0){
                    if(nav->sig != NULL){
                        nav->sig->ant = nav->ant;
                    }

                    if (nav->ant != NULL){
                        nav->ant->sig = nav->sig;
                    }

                    if (nav == lista){
                        lista = lista->ant;

                        if (lista != NULL){
                            lista->sig = NULL;
                        }
                    }

                    cont++;
                    tam--;
                    eliminarEnteroLargo(nav->elem);
                    free(nav);
                }
                nav = nav->ant;
            }
        }
        return cont;
    }
return 0;
}

void removeFirst(TEnteroLargo aEliminar){
    if (aEliminar != NULL && lista != NULL){
        TNodo nav = lista;
        int encontre = FALSE;

        while(nav != NULL && !encontre){
            if(strcmp(nav->elem->digitos, aEliminar->digitos) == 0){
                if(nav->sig != NULL){
                    nav->sig->ant = nav->ant;
                }

                if (nav->ant != NULL){
                    nav->ant->sig = nav->sig;
                }

                if (nav == lista){
                    lista = lista->ant;

                    if (lista != NULL){
                        lista->sig = NULL;
                    }
                }

                eliminarEnteroLargo(nav->elem);
                free(nav);
                tam--;
                encontre = TRUE;
            }
        }
    }
}

void removeLast(TEnteroLargo aEliminar){
    if (aEliminar != NULL && lista != NULL){
        TNodo ultimo = NULL;
        TNodo nav = lista;

        while(nav != NULL){
            if (strcmp(aEliminar->digitos, nav->elem->digitos) == 0){
                ultimo = nav;
            }

            nav = nav->ant;
        }

        if(ultimo != NULL){
            if(nav->sig != NULL){
                nav->sig->ant = nav->ant;
            }

            if (nav->ant != NULL){
                nav->ant->sig = nav->sig;
            }

            if (nav == lista){
                lista = lista->ant;

                if (lista != NULL){
                    lista->sig = NULL;
                }
            }

            eliminarEnteroLargo(ultimo->elem);
            free(ultimo);
            tam--;
        }
    }
}

TEnteroLargo siguiente(TEnteroLargo entero){
    if (entero != NULL){
        TEnteroLargo salida = NULL;
        int encontre = FALSE;
        TNodo nav = lista;

        while(!encontre && nav != NULL){
            if (entero == nav->elem){
                encontre = TRUE;
            }else{
                nav = nav->ant;
            }
        }

        if (encontre && nav->sig != NULL){
            salida = nav->sig->elem;
        }

        return salida;
    }

    return NULL;
}

TEnteroLargo anterior(TEnteroLargo entero){
    if (entero != NULL){
        TEnteroLargo salida = NULL;
        int encontre = FALSE;
        TNodo nav = lista;

        while(!encontre && nav != NULL){
            if (entero == nav->elem){
                encontre = TRUE;
            }else{
                nav = nav->ant;
            }
        }

        if (encontre && nav->ant != NULL){
            salida = nav->ant->elem;
        }

        return salida;
    }

    return NULL;
}

int buscar(TEnteroLargo aBuscar){
    int esta = FALSE;
    if(aBuscar != NULL && lista != NULL){
        TNodo nav = lista;

        while(nav != NULL && !esta){
            if (strcmp(aBuscar->digitos, nav->elem->digitos) == 0){
                esta = TRUE;
            }

            nav = nav->ant;
        }
    }

    return esta;
}

int tamanio(){
    return tam;
}

int isEmpty(){
    if (lista != NULL){
        return FALSE;
    }

    return TRUE;
}

TEnteroLargo frente(){
    TEnteroLargo salida = crearEnteroLargo();
    salida = NULL;

    if (lista != NULL){
        salida = lista->elem;
    }

    return salida;
}

TEnteroLargo cola(){
    TEnteroLargo salida = crearEnteroLargo();
    salida = NULL;

    if (lista != NULL){
        TNodo nav = lista;

        while(nav->ant != NULL){
            nav=nav->ant;
        }

        salida = nav->elem;
    }

    return salida;
}

void toString(){
    if (lista != NULL){
        TNodo nav = lista;

        while(nav != NULL){
            mostrarEnteroLargo(nav->elem);
            nav = nav->ant;
        }

        printf("\nFin de la lista.\n");
    }else{
        printf("\nLa lista esta vacia.\n");
    }
}

void destruir(){
    if (lista != NULL){
        TNodo nav = lista;
        TNodo aELiminar;

        while(nav != NULL){
            aELiminar = nav;
            nav = nav->ant;
            eliminarEnteroLargo(aELiminar->elem);
            free(aELiminar);
            tam--;
        }

        lista = NULL;
    }
}
