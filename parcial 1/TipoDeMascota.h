#include "string.h"
typedef struct
{
    int id;//Comienza en 1000
    char descripcion[20];
}eTipo;

int HarcodearTipos(eTipo listaDeTipos[]);
//devuelve 1 si no hubo errores 0 si se le paso vector NULL
void mostarTipo(eTipo listaDeTipos);
//muestra el id y la descripcion de un tipo
void mostrarTipos(eTipo listaDeTipos[],int tam);
//muestra la lista de tipos