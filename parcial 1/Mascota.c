#include <stdio.h>
#include <string.h>
#include "Mascota.h"
#define LIBRE 1
#define OCUPADO -1
#define ELIMINADO 0

void inicializarMascotas(eMascota lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int buscarLibre(eMascota lista[],int tam)
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


int altaMascota(eMascota lista[],int tam,int* pId)
{
    int todoOk=0;
    int indice;
    eMascota auxMascota;
    if(lista!=NULL && tam >0 && pId!=NULL)
    {
        printf("\n          Alta Mascota        \n");
        indice= buscarLibre(lista, tam);
        if(indice==OCUPADO)
        {
            printf("no hay lugar en el sistema \n");
        }else
        {
            auxMascota.id=*pId;
            (*pId)++;
            
            printf("Ingrese nombre: ");
            __fpurge(stdin);
            scanf("%[^\n]",auxMascota.nombre);
            
            printf("Ingrese numero del tipo (Ave 1000 Perro 1001 Roedor 1002 Gato 1003 Pez 1004)");
            scanf("%d",&auxMascota.idTipo);
            
            printf("Ingrese numero del color (Negro 5000 Blanco 5001 Rojo 5002 Gris 5003 Azul 5004)");
            scanf("%d",&auxMascota.idColor);
            
            printf("Ingrese edad: ");
            scanf("%d",&auxMascota.edad);
            
            printf("Ingrese Vacunado ('s' o 'n'): ");
            __fpurge(stdin);
            scanf("%c",&auxMascota.vacunado);
            
            auxMascota.isEmpty=OCUPADO;
            
            lista[indice]=auxMascota;
            todoOk=1;
        }
        
    }
    return todoOk;
}

void mostrarMascota(eMascota unaMascota)
{
    char tipo[20];
    char color[20];
    switch(unaMascota.idTipo)
    {
        case 1000:
        strcpy(tipo,"Ave");
        break;
        case 1001:
        strcpy(tipo,"Perro");
        break;
        case 1002:
        strcpy(tipo,"Roedor");
        break;
        case 1003:
        strcpy(tipo,"Gato");
        break;
        case 1004:
        strcpy(tipo,"Pez");
        break;
    }
    switch(unaMascota.idTipo)
    {
        case 5000:
        strcpy(tipo,"Negro");
        break;
        case 5001:
        strcpy(tipo,"Blanco");
        break;
        case 5002:
        strcpy(tipo,"Rojo");
        break;
        case 5003:
        strcpy(tipo,"Gris");
        break;
        case 5004:
        strcpy(tipo,"Azul");
        break;
    }
    printf("\t%d \t%s \t%s \t%d \t%d \t%c\n",unaMascota.id,unaMascota.nombre,tipo,unaMascota.idColor,unaMascota.edad,unaMascota.vacunado);
}

int mostrarTodasLasMascotas(eMascota lista[],int tam)
{
    int todoOk=0;
    int flag=1;
    if(lista!=NULL && tam >0)
    {
        printf("                 Listado Mascotas       \n");
        printf("\tId \tNombre\t Tipo\t Color\t Edad \t Estado vacunacion \n");
        for(int i=0;i<tam;i++)
        {
            if(lista[i].isEmpty==OCUPADO)
            {
                
                mostrarMascota(lista[i]);
                flag=0;
            }
            
        }
        if(flag)
        {
            printf("               No se cargaron Mascotas       \n");
        }
    }
    
    return todoOk;
}

void modificarMascota(eMascota listado[], int tam)
{
    int idIngresado;
    int i;
    int respuesta;
    printf("Ingrese ID de la mascota a modificar: ");
    scanf("%d", &idIngresado);
    for(i=0; i<tam;i++)
    {
        if(idIngresado == listado[i].id&&listado[i].isEmpty==LIBRE)
        {
            printf("1.Cambiar tipo \n");
            printf("2.Cambiar estado vacunacion \n");
            printf("3.Cancelar \n");
            printf("Elija una opcion: ");
            scanf("%d",&respuesta);
            
            switch (respuesta)
    	    {
    	        case 1:
    	        printf("Ingrese nuevo tipo (Ave 1000 Perro 1001 Roedor 1002 Gato 1003 Pez 1004): ");
                __fpurge(stdin);
                scanf("%d",&listado[i].idTipo);
    	        break;
    	        case 2:
    	        printf("Ingrese nuevo estado de vacunacion ('s' o 'n') ");
                __fpurge(stdin);
                scanf("%c",&listado[i].vacunado);
    	        break;
    	        
    	    }
        }
    }
}

void bajaMascota(eMascota listado[], int tam)
{
    int idIngresado;
    printf("Ingrese ID de la mascota a eliminar");
    scanf("%d",&idIngresado);
    for(int i=0;i<tam;i++)
    {
        if(idIngresado==listado[i].id)
        {
            printf("ELIMINO\n");
            listado[i].isEmpty=ELIMINADO;
            break;
        }
        
    }
}

void ordenarMascotasPorTipo(eMascota listado[], int tam)
{
    int i;
    int j;
    eMascota mascotaPivote;

    for(i=0; i<tam-1; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            
            for(j=i+1; j<tam; j++)
            {
                if(listado[i].idTipo > listado[j].idTipo)
                {
                    mascotaPivote = listado[i];
                    listado[i] = listado[j];
                    listado[j] = mascotaPivote;
                }
            }
        }
    }
}

void ordenarMascotasPorNombre(eMascota listado[], int tam)
{
    int i;
    int j;
    eMascota mascotaPivote;

    for(i=0; i<tam-1; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                {
                    mascotaPivote = listado[i];
                    listado[i] = listado[j];
                    listado[j] = mascotaPivote;
                }
            }
        }
    }
}

void ordenarMascotasPorTipoYNombre(eMascota listado[], int tam)
{
    ordenarMascotasPorNombre(listado,tam);
    ordenarMascotasPorTipo(listado,tam);
}