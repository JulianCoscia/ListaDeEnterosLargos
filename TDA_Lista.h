#ifndef TDA_LISTA_H_INCLUDED
#include "TDA_EnteroLargo.h"
#define TDA_LISTA_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef struct nodo{
    TEnteroLargo elem;
    struct nodo* sig;
    struct nodo* ant;
}*TNodo;

/*Inicializa una nueva lista vacia.*/
void construir();

/*Inserta un nuevo elemento al principio de la lista*/
void insertarFront(TEnteroLargo aInsertar);

/*Inserta un nuevo elemento al final de la lista.*/
void insertarBack(TEnteroLargo aInsertar);

/*Remueve el primer elemento de la lista. Es responsabilidad de quien lo usa liberar la memoria utilizada por el elemento retornado*/
TEnteroLargo removeFront();

/*Remueve el elemento final de la lista. Es responsabilidad de quien lo usa liberar la memoria utilizada por el elemento retornado*/
TEnteroLargo removeBack();

/*Remueve todas las apariciones del elemento de la lista.*/
int removeAll(TEnteroLargo aEliminar);

/*Remueve la primera aparicion del elemento de la lista.*/
void removeFirst(TEnteroLargo aEliminar);

/*Remueve la ultima aparicion del elemento de la lista.*/
void removeLast(TEnteroLargo aEliminar);

/*Retorna el siguiente entero largo en la lista del indicado por parametro. Retorna NULL en caso de ser el primer elemento de la lista o si no pertenece a la lista.*/
TEnteroLargo siguiente(TEnteroLargo entero);

/*Retorna el anterior entero largo en la lista del indicado por parametro. Retorna NULL en caso de ser el ultimo elemento de la listao o si no pertenece a la lista.*/
TEnteroLargo anterior(TEnteroLargo entero);

/*Busca si el elemento pertenece a la lista. Retorna TRUE si el elemento pertenece. FALSE en caso contrario.*/
int buscar(TEnteroLargo aBuscar);

/*Devuelve la cantidad de elementos que tiene la lista.*/
int tamanio();

/*Consulta si la lista esta vacia. Retonrna TRUE si la lista esta vacia. FALSE en caso contrario.*/
int isEmpty();

/*Devuelve el primer elemento de la lista.*/
TEnteroLargo frente();

/*Devuelve el ultimo elemento de la lista.*/
TEnteroLargo cola();

/*Imprime por consola el contenido de cada elemento de la lista.*/
void toString();

/*Elimina todo el contenido de la lista y libera el espacio reservado. Dela la lista como recien inicializada.*/
void destruir();
#endif // TDA_LISTA_H_INCLUDED
