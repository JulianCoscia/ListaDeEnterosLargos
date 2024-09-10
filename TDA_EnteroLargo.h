#ifndef TDA_ENTEROLARGO_H_INCLUDED
#define TDA_ENTEROLARGO_H_INCLUDED
#define MAX_LENGTH 101          //100 lugares para los digitos y 1 para el caracter '\0'

typedef struct enteroLargo{
    char digitos[MAX_LENGTH];
} *TEnteroLargo;

/*Crea un nuevo EnteroLargo sin ningun digito*/
TEnteroLargo crearEnteroLargo();

/*Inicializa un EnteroLargo con el valor pasado por parametro*/
void inicializarEnteroLargo(TEnteroLargo nuevo, char* valor);

/*Elimina un EnteroLargo y libera el espacio de memoria asignado para el mismo*/
void eliminarEnteroLargo(TEnteroLargo aEliminar);

/*Muetra por consola el valor del EnteroLargo*/
void mostrarEnteroLargo(TEnteroLargo aMostrar);

/*Compara 2 magnitudes de EnteroLargo. Devuelve:
    * -1 si el primer EnteroLargo tiene una magnitud mayor que el segundo.
    * 1 si el segundo EnteroLargo tiene una magnitud mayor que el primero.
    * 0 si ambos valores de  EnteroLargotienen igual magnitud.
    * 2 Error: Uno de los 2 valores es nulo. */
int compararEnterosLargos(TEnteroLargo a, TEnteroLargo b);

/*Suma las magnitudes de dos EnteroLargos y retorna su resultado.
    * Retorna 'X' si la suma produce overflow (resultado con mas de 100 digitos). */
TEnteroLargo sumarEnterosLargos(TEnteroLargo a, TEnteroLargo b);

#endif // TDA_ENTEROLARGO_H_INCLUDED
