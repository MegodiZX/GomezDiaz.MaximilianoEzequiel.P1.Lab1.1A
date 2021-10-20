#include "string.h"
typedef struct
{
    int id;//Comienza en 5000
    char nombreColor[20];
}eColor;

int HarcodearColores(eColor listaDeColores[]);
//devuelve 1 si no hubo errores 0 si se le paso vector NULL
void mostarColor(eColor lista);
//muestra un color 
void mostrarColores(eColor lista[],int tam);
//lista los colores cargados