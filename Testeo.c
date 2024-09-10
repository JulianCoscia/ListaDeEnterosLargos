#include <stdio.h>
#include <stdlib.h>
#include "TDA_EnteroLargo.h"
#include "TDA_Lista.h"

void testear()
{
    //____________________________TESTEO DE ENTERO LARGO______________________________________________
    printf("\nIniciando testeo de Lista + Entero largo...\n\n");

    TEnteroLargo prueba;
    printf("Prueba de Crear un entero largo...\n");
    prueba = crearEnteroLargo();
    printf("El EnteroLargo fue creado? %i\n\n", prueba != NULL);

    TEnteroLargo prueba2;
    printf("Prueba de Crear un entero largo 2...\n");
    prueba2 = crearEnteroLargo();
    printf("El EnteroLargo fue creado? %i\n\n", prueba2 != NULL);

    TEnteroLargo prueba3;
    printf("Prueba de Crear un entero largo 3...\n");
    prueba3 = crearEnteroLargo();
    printf("El EnteroLargo fue creado? %i\n\n", prueba3 != NULL);

    printf("Prueba de Inicializacion de un entero largo...\n");
    char valor[] = "5365313691926369518477323663920451560197720722190088385589406806651666731227264565638853857429116646";
    valor[MAX_LENGTH-1] = '\0';
    inicializarEnteroLargo(prueba, valor);
    printf("Se inicializo correctamente? primer digito: %i - ultimo digito: %i\n\n", prueba->digitos[0]-'0', prueba->digitos[MAX_LENGTH-2]-'0');

    printf("Prueba de Inicializacion de un entero largo 2...\n");
    char valor2[] = "9999999999";
    valor2[MAX_LENGTH-1] = '\0';
    inicializarEnteroLargo(prueba2, valor2);
    printf("Se inicializo correctamente el 2? primer digito: %i - ultimo digito: %i\n\n", prueba2->digitos[0]-'0', prueba2->digitos[MAX_LENGTH-2]-'0');

    printf("Prueba de Inicializacion de un entero largo 3...\n");
    char valor3[] = "14157895625928561819156";
    valor3[MAX_LENGTH-1] = '\0';
    inicializarEnteroLargo(prueba3, valor3);
    printf("Se inicializo correctamente el 3? primer digito: %i - ultimo digito: %i\n\n", prueba3->digitos[0]-'0', prueba3->digitos[MAX_LENGTH-2]-'0');

    printf("Prueba de mostrar por pantalla un entero largo...");
    mostrarEnteroLargo(prueba);

    printf("\nPrueba de mostrar por pantalla un entero largo 2...\n");
    mostrarEnteroLargo(prueba2);

    printf("\nPrueba de mostrar por pantalla un entero largo 3...\n");
    mostrarEnteroLargo(prueba3);

    printf("\n\nInicio de prueba de suma...");
    TEnteroLargo resultado = sumarEnterosLargos(prueba, prueba2);
    printf("\nResultado de la suma: ");
    mostrarEnteroLargo(resultado);
    eliminarEnteroLargo(resultado);

    //_____________________________FIN DE TESTEO DE ENTERO LARGO_____________________________________

    //_____________________________INICIO DE TESTEO DE LISTA DE ENTEROS LARGOS_______________________
    printf("\n\nIniciando testeo de la lista...\n\n");

    printf("Probando construir()\n");
    construir();
    printf("Construir finalizado\n\n");

    // Verificar si la lista está vacía
    printf("La lista esta vacia?\n");
    if (isEmpty()) {
        printf("La lista esta vacia.\n\n");
    }else{
        printf("La lista NO esta vacia.\n\n");
    }

    // Insertar elementos en la lista
    printf("_________________Prueba de insertar...\n\n");
    insertarFront(prueba2);
    insertarBack(prueba);
    insertarFront(prueba);
    insertarFront(prueba);
    insertarFront(prueba);
    insertarFront(prueba);
    printf("Insertados los 6 elementos.\n\n");

    // Mostrar el contenido de la lista
    printf("Contenido de la lista despues de insertar:");
    toString();

    // Verificar el tamaño de la lista
    printf("\nTamanio de la lista: %d\n\n", tamanio());

    // Buscar un elemento en la lista
    printf("_________________Prueba de buscar...\n\n");
    printf("Buscando 'prueba': ");
    if (buscar(prueba)) {
        printf("Elemento encontrado en la lista. (deberia estar)\n\n");
    }

    printf("Buscando 'prueba3': ");
    if (buscar(prueba3)) {
        printf("Elemento encontrado en la lista. (NO deberia estar)\n");
    }else{
        printf("Elemento no encontrado. (no deberia estar)\n\n");
    }

    // Remover el primer y último elemento
    TEnteroLargo frente = removeFront();
    TEnteroLargo cola = removeBack();
    printf("Removiendo el primer elemento:");
    mostrarEnteroLargo(frente);
    printf("Removiendo el ultimo elemento:");
    mostrarEnteroLargo(cola);

    // Mostrar el contenido de la lista después de remover elementos
    printf("\nContenido de la lista despues de remover:");
    toString();

    // Eliminar todos los elementos con una cadena específica
    printf("\n_________________Prueba de insertar repetidos...\n\n");
    insertarFront(prueba3);
    insertarBack(prueba3);
    insertarFront(prueba3);
    printf("\nInsertados las tres prueba3 repetidos.\n");
    removeAll(prueba3);
    printf("Ahora se supone que fueron removidos los 3 prueba 3.\n");

    printf("Contenido de la lista despues de eliminar todas las apariciones de prueba3:");
    toString();

    printf("\nTamaño de la lista ahora? %i\n", tamanio());

    // Destruir la lista
    printf("\n_________________Prueba de destruir la cola...\n\n");
    destruir();

    // Verificar si la lista está vacía después de destruirla
    if (isEmpty()) {
        printf("La lista esta vacia despues de destruirla.\n");
    }

    printf("\nPor si acaso pregunto el tamanio: %i\n",tamanio());

    /*  Se eliminan los enteros largos para probar la lista  */
    printf("\nPrueba de eliminacion de enteros largos...\n\n");
    printf("Eliminando prueba 1...\n");
    eliminarEnteroLargo(prueba);
    printf("Eliminando prueba 2...\n");
    eliminarEnteroLargo(prueba2);
    printf("Eliminando prueba 3...\n");
    eliminarEnteroLargo(prueba3);

    return 0;
}
