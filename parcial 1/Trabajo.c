#include <stdio.h>
#include "Trabajo.h"
#define LIBRE 1
#define OCUPADO -1
#define ELIMINADO 0

void mostrarTrabajo(eTrabajo lista)
{ 
    printf("\t%d      \t%d       \t%d/%d/%d\n",lista.idMascota,lista.idServicio,lista.fecha.dia,lista.fecha.mes,lista.fecha.anio);
}

void mostrarTrabajos(eTrabajo lista[],int tam)
{
    int todoOk=0;
    int flag=1;
    
    if(lista!=NULL&& tam>0)
    {
        printf("                 Listado Trabajos        \n");
        printf("\tId mascota \tId servicio \tfecha\n");
        for(int i=0;i<tam;i++)
        {
            if(lista[i].isEmpty==OCUPADO)
            {
                
                mostrarTrabajo(lista[i]);
                flag=0;
            }
            
        }
        if(flag)
        {
            printf("               No se cargaron Trabajos       \n");
        }
        
    }
}

void inicializarTrabajos(eTrabajo lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
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
        printf("Error al buscar libre, array vacio o tamaño menor a 0\n");
    }
    return indice;
}

int altaTrabajo(eTrabajo lista[],int tam,int* pId)
{
    int todoOk=0;
    int indice;
    eTrabajo auxTrabajo;
    if(lista!=NULL && tam >0 && pId!=NULL)
    {
        indice= buscarLibreTrabajo(lista, tam);
        if(indice==OCUPADO)
        {
            printf("no se pueden cargar mas trabajos \n");
        }else
        {
            auxTrabajo.id=*pId;
            (*pId)++;
            
            printf("Ingrese id mascota: ");
            scanf("%d",&auxTrabajo.idMascota);
            
            printf("Ingrese id Servicio: ");
            scanf("%d",&auxTrabajo.idServicio);
            
            printf("Ingrese fecha (dia, mes, anio): ");
            scanf("%d",&auxTrabajo.fecha.dia);
            scanf("%d",&auxTrabajo.fecha.mes);
            scanf("%d",&auxTrabajo.fecha.anio);
            
            
            auxTrabajo.isEmpty=OCUPADO;
            
            lista[indice]=auxTrabajo;
            todoOk=1;
        }
        
    }
    return todoOk;
}