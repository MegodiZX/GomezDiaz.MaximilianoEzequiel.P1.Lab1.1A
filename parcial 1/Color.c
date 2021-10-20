#include "Color.h"
#include <stdio.h>
int HarcodearColores(eColor lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int id[5]={5000,5001,5002,5003,5004};
        char nombreColor[5][20]={"Negro","Blanco","Rojo","Gris","Azul"};
        for(int i=0;i<5;i++)
        {
            
            lista[i].id=id[i];
            strcpy(lista[i].nombreColor,nombreColor[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

void mostarColor(eColor lista)
{
    printf("\t%d \t%s \n",lista.id,lista.nombreColor);
}

void mostrarColores(eColor lista[],int tam)
{
    printf("\tId \tDescripcion \n");
    for(int i=0;i<tam;i++)
    {
        mostarColor(lista[i]);
    }
    
}