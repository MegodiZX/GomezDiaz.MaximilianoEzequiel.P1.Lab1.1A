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
            
            printf("Ingrese numero del tipo de mascota(Ave 1000 Perro 1001 Roedor 1002 Gato 1003 Pez 1004)");
            scanf("%d",&auxMascota.idTipo);
            while(auxMascota.idTipo>1004||auxMascota.idTipo<1000)
            {
                printf("Error reingrese numero del tipo de mascota (Ave 1000 Perro 1001 Roedor 1002 Gato 1003 Pez 1004)");
                scanf("%d",&auxMascota.idTipo);
            }
            
            printf("Ingrese numero del color de mascota (Negro 5000 Blanco 5001 Rojo 5002 Gris 5003 Azul 5004)");
            scanf("%d",&auxMascota.idColor);
            
            while(auxMascota.idColor>5004||auxMascota.idColor<5000)
            {
                printf("Error reingrese numero del color de mascota (Negro 5000 Blanco 5001 Rojo 5002 Gris 5003 Azul 5004)");
                scanf("%d",&auxMascota.idColor);
            }
            
            printf("Ingrese edad: ");
            scanf("%d",&auxMascota.edad);
            
            printf("Ingrese Vacunado ('s' o 'n'): ");
            __fpurge(stdin);
            scanf("%c",&auxMascota.vacunado);
            
            while(auxMascota.vacunado!='s'&& auxMascota.vacunado!='n')
            {
                printf("Error reingrese Vacunado ('s' o 'n'): ");
                __fpurge(stdin);
                scanf("%c",&auxMascota.vacunado);
            }
            
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

void mostrarMascotaColorSelec(eMascota listado[], int tam)
{
    int colorSelecionado;
    printf("Ingrese numero del color de mascota (Negro 5000 Blanco 5001 Rojo 5002 Gris 5003 Azul 5004)");
    scanf("%d",&colorSelecionado);
    
    while(colorSelecionado>5004||colorSelecionado<5000)
    {
        printf("Error reingrese numero del color de mascota (Negro 5000 Blanco 5001 Rojo 5002 Gris 5003 Azul 5004)");
        scanf("%d",&colorSelecionado);
    }
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idColor==colorSelecionado)
        {
            mostrarMascota(listado[i]);
        }
    }
}

void promedioVacunados(eMascota listado[], int tam)
{
    int vacunados=0;
    int pacientes=0;
    float promedioVacunados;
    for(int i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            pacientes++;
        }
        if(listado[i].vacunado=='s')
        {
            vacunados++;
        }
    }
    promedioVacunados=(float)vacunados/pacientes;
    printf("El promedio de mascotas vacunadas es: %.2f\n",promedioVacunados);
    
}

void listarMascotasDeMenorEdad(eMascota listado[], int tam)
{
    int menorEdad=0;
    int bandera=0;
    for(int i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==OCUPADO&&listado[i].edad<menorEdad||bandera==0)
        {
            bandera=1;
            menorEdad=listado[i].edad;
        }
    }
    for(int i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==OCUPADO&&listado[i].edad==menorEdad)
        {
            mostrarMascota(listado[i]);
        }
    }
    
}

void listarMascotasSeparadasPorTipo(eMascota listado[], int tam)
{
    ordenarMascotasPorTipo(listado,tam);
    printf("           ---Aves---        \n");
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idTipo==1000)
        {
            mostrarMascota(listado[i]);
        }
    }
    printf("           ---Perros---        \n");
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idTipo==1001)
        {
            mostrarMascota(listado[i]);
        }
    }
    printf("           ---Roedores---        \n");
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idTipo==1002)
        {
            mostrarMascota(listado[i]);
        }
    }
    printf("           ---Gatos---        \n");
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idTipo==1003)
        {
            mostrarMascota(listado[i]);
        }
    }
    printf("           ---Peces---        \n");
    for(int i=0;i<tam;i++)
    {
        if(listado[i].idTipo==1004)
        {
            mostrarMascota(listado[i]);
        }
    }
    
}

int ContarColorYTipo(eMascota listado[], int tam)
{
    int cantidad=0;
    int colorSelecionado;
    int tipoSelecionado;
    printf("Ingrese numero del color de mascota ");
    scanf("%d",&colorSelecionado);
    
    while(colorSelecionado>5004||colorSelecionado<5000)
    {
        printf("Error reingrese numero del color de mascota ");
        scanf("%d",&colorSelecionado);
    }
    
    printf("Ingrese numero del tipo de mascota ");
    scanf("%d",&tipoSelecionado);
    while(tipoSelecionado>1004||tipoSelecionado<1000)
    {
        printf("Error reingrese numero del tipo de mascota ");
        scanf("%d",&tipoSelecionado);
    }
    
    for(int i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==OCUPADO && listado[i].idColor==colorSelecionado && listado[i].idTipo==tipoSelecionado)
        {
            mostrarMascota(listado[i]);
        }
    }
    
    return cantidad;
}

void ColorMasCantidadMascota(eMascota listado[], int tam)
{
    int colorConMasMascotas=0;//5000 5001 5002 5003 5004
    int bandera=0;
    int contNegro=0;
    int contBlanco=0;
    int contRojo=0;
    int contGris=0;
    int contAzul=0;
    for(int i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            colorConMasMascotas=listado[i].idColor;
            switch(colorConMasMascotas)
            {
                case 5000:
                contNegro++;
                break;
                case 5001:
                contBlanco++;
                break;
                case 5002:
                contRojo++;
                break;
                case 5003:
                contGris++;
                break;
                case 5004:
                contAzul++;
                break;
            }
        }
    }
    if(contBlanco<contNegro&&contRojo<contNegro&&contGris<contNegro&&contAzul<contNegro)
    {
        colorConMasMascotas=5000;
    }else
    {
        if(contRojo<contBlanco&&contGris<contBlanco&&contAzul<contBlanco)
        {
            colorConMasMascotas=5001;
        }else
        {
            if(contGris<contRojo&&contAzul<contRojo)
            {
                colorConMasMascotas=5002;
            }else
            {
                if(contAzul<contGris)
                {
                    colorConMasMascotas=5003;
                }else
                {
                    colorConMasMascotas=5004;
                }
            }
        }
    }
    
    printf("(5000 Negro 5001 Blanco 5002 Rojo 5003 Gris 5004 Azul): %d",colorConMasMascotas);
}

