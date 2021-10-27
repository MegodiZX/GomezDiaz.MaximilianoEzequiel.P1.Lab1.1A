#include "string.h"
typedef struct
{
    int id;//comienza en 20000
    char descripcion[25];
    int precio;
}eServicio;

int HarcodearServicios(eServicio lista[]);
//devuelve 1 si no hubo errores 0 si se le paso vector NULL
void mostarServicio(eServicio listaServicios);
void mostrarServicios(eServicio listaServicios[],int tam);
