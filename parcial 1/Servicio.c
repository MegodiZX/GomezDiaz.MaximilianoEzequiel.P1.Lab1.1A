#include "Servicio.h"
#include <stdio.h>
int HarcodearServicios(eServicio lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int id[3]={20000,20001,20002};
        char descripcion[3][25]={"Corte","Desparasitado","Castrado"};
        int precio[3]={450,800,600};
        for(int i=0;i<3;i++)
        {
            
            lista[i].id=id[i];
            strcpy(lista[i].descripcion,descripcion[i]);
            lista[i].precio=precio[i];
        }
        todoOk=1;
    }
    return todoOk;
}

void mostarServicio(eServicio listaServicios)
{
    printf("\t%d \t%s \t%d \n",listaServicios.id,listaServicios.descripcion,listaServicios.precio);
}

void mostrarServicios(eServicio listaServicios[],int tam)
{
    printf("\tId \tDescripcion \tPrecio \n");
    for(int i=0;i<tam;i++)
    {
        mostarServicio(listaServicios[i]);
    }
    
}