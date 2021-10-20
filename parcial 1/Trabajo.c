#include "Trabajo.h"
#define LIBRE 1
#define OCUPADO -1
#define ELIMINADO 0

void mostrarTrabajo(eTrabajo lista)
{
    printf("\t%d \t%s \t%d \n",lista.id,lista.descripcion,lista.precio,lista.fecha);
}

void mostrarTrabajos(eTrabajo lista[],int tam)
{
    printf("\tId \tIdMascota \tIdservicio \tfecha\n");
    if(lista!=NULL)
    {
        mostrarTrabajo(lista[i]);
    }
}


int buscarLibreTrabajo(eTrabajo lista[],int tam)
{
    int indice=-1;
    if(lista!=NULL && tam >0)
    {
       for(int i=0;i<tam;i++)
       {
           if(lista[i].isEmpty==LIBRE)
           {
               
               indice=i;
               break;
           }
       }
    }else
    {
        printf("Error al buscar libre, array vacio o tamaño menor a 0");
    }
    return indice;
}


int altaTrabajo(eTrabajo lista[],int tam,int* pIdT);
{
    int todoOk=0;
    int indice;
    eTrabajo auxTrabajo;
    if(lista!=NULL && tam >0 && pIdT!=NULL)
    {
        printf("\n          Alta Mascota        \n");
        indice= buscarLibreTrabajo(lista, tam);
        if(indice==OCUPADO)
        {
            printf("no hay lugar en el sistema \n");
        }else
        {
            auxTrabajo.id=*pIdT;
            (*pIdT)++;
            
            printf("Ingrese id mascota: ");
            scanf("%d",&auxTrabajo.idMascota);
            
            printf("Ingrese id id Servicio: ");
            scanf("%d",&auxTrabajo.idServicio);
            
            auxMascota.isEmpty=OCUPADO;
            
            lista[indice]=auxTrabajo;
            todoOk=1;
        }
        
    }
    return todoOk;
}