#include "TipoDeMascota.h"
#include <stdio.h>
int HarcodearTipos(eTipo lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int id[5]={1000,1001,1002,1003,1004};
        char descripcion[5][20]={"Ave","Perro","Roedor","Gato","Pez"};
        for(int i=0;i<5;i++)
        {
            
            lista[i].id=id[i];
            strcpy(lista[i].descripcion,descripcion[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

void mostarTipo(eTipo listaDeTipos)
{
    printf("\t%d \t%s \n",listaDeTipos.id,listaDeTipos.descripcion);
}

void mostrarTipos(eTipo listaDeTipos[], int tam)
{
    printf("\tId \tDescripcion \n");
    for(int i=0;i<tam;i++)
    {
        mostarTipo(listaDeTipos[i]);
    }
    
}