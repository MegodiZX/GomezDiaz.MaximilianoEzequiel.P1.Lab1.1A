/******************************************************************************
Parcial 1 Laboratorio Maximiliano E Gomez Diaz
*******************************************************************************/
#include <stdio.h>
#include "TipoDeMascota.h"
#include "Color.h"
#include "Mascota.h"
#include "Servicio.h"
#include "Trabajo.h"
#define T 5

int main()
{
    int respuesta;
    eMascota listaMascotas[T];
    eTipo listaTipos[5];
    eColor listaColores[5];
    eServicio listaServicios[3];
    eTrabajo listaTrabajos[T];
    int nextId=100;
    int cargoMascota=0;
    //int IdTrabajo=0;
    int Subrespuesta;
    
    inicializarMascotas(listaMascotas,T);
    HarcodearTipos(listaTipos);
    HarcodearColores(listaColores);
    HarcodearServicios(listaServicios);
    inicializarTrabajos(listaTrabajos,T);
    HarcodearTrabajos(listaTrabajos);
    
    void PedirMascotaYMostrarTrabajos(eTrabajo listaTrabajos[],eMascota listado[], int tam);
    void mostrarTrabajosDeLaMascota(eTrabajo listaTrabajos[],eMascota listado[], int tam);
    
    do
    {
        printf("1.Alta Mascota\n");
        printf("2.Modificar Mascota\n");
        printf("3.Baja Mascota\n");
        printf("4.Listar mascotas (ordenadas por tipo y nombre)\n");
        printf("5.Listar tipos \n");
        printf("6.Listar colores\n");
        printf("7.Listar colores\n");
        printf("8.Alta trabajo\n");
        printf("9.Listrar trabajo\n");
        printf("10.Menu Informes\n");
        printf("0.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d",&respuesta);
        switch (respuesta)
	    {
	        case 1:
	        altaMascota(listaMascotas,T,&nextId);
	        cargoMascota=1;
	        break;
	        case 2:
	        mostrarTodasLasMascotas(listaMascotas,T);
	        modificarMascota(listaMascotas,T);
	        break;
	        case 3:
	        mostrarTodasLasMascotas(listaMascotas,T);
	        bajaMascota(listaMascotas,T);
	        break;
	        case 4:
	        ordenarMascotasPorTipoYNombre(listaMascotas,T);
	        mostrarTodasLasMascotas(listaMascotas,T);
	        break;
	        case 5:
	        mostrarTipos(listaTipos,5);
	        break;
	        case 6:
	        mostrarColores(listaColores,5);
	        break;
	        case 7:
	        mostrarServicios(listaServicios,3);
	        break;
	        case 8:
	        if(cargoMascota==1)
	        {
	            mostrarTodasLasMascotas(listaMascotas,T);
	            mostrarServicios(listaServicios,3);
	            //altaTrabajo(listaTrabajos,T,&IdTrabajo);
	        }else
	        {
	            printf("primero ingrese una mascota\n");
	        }
	        
	        break;
	        case 9:
	        mostrarTrabajos(listaTrabajos,T);
	        break;
	        case 10:
	        do
            {
                printf("1.Mostrar mascotas del color seleccionado\n");
                printf("2.Mascotas vacunadas sobre el promedio\n");
                printf("3.Informar la/s mascotas con menor edad\n");
                printf("4.Listar mascotas por tipo (separadas)\n");
                printf("5.Elegir el color y tipo de mascota\n");
                printf("6.Mostrar los colores con mas cantidad de mascota/s\n");
                printf("7.Mostrar trabajos de una mascota\n");
                /*printf("8.Alta trabajo\n");
                printf("9.Listrar trabajo\n");
                printf("10.Menu Informes\n");*/
                printf("0.Salir submenu\n");
                printf("Elija una opcion: ");
                scanf("%d",&Subrespuesta);
                switch (Subrespuesta)
    	        {
    	            case 1:
        	        mostrarMascotaColorSelec(listaMascotas,T);
        	        break;
        	        case 2:
        	        promedioVacunados(listaMascotas,T);
        	        break;
        	        case 3:
        	        listarMascotasDeMenorEdad(listaMascotas,T);
        	        break;
        	        case 4:
        	        listarMascotasSeparadasPorTipo(listaMascotas,T);
        	        break;
        	        case 5:
        	        mostrarColores(listaColores,5);
        	        mostrarTipos(listaTipos,5);
        	        if(cargoMascota==1)
        	        {
        	            printf("El numero de mascotas con ese color y ese tipo es: %d",ContarColorYTipo(listaMascotas,T));
        	        }
        	        break;
        	        case 6:
        	        ColorMasCantidadMascota(listaMascotas,T);
        	        break;
        	        case 7:
        	        mostrarTodasLasMascotas(listaMascotas,T);
        	        PedirMascotaYMostrarTrabajos(listaTrabajos,listaMascotas,T);
        	        break;
    	        }
            }while(Subrespuesta!=0);
	        break;
	    }
    }
    while(respuesta != 0);
    return 0;
}


void mostrarTrabajosDeLaMascota(eTrabajo listaTrabajos[],eMascota listado[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(listaTrabajos[i].idMascota==listado[j].id)
            {
                mostrarTrabajo(listaTrabajos[i]);
            }
        }
        
    }
}

void PedirMascotaYMostrarTrabajos(eTrabajo listaTrabajos[],eMascota listado[], int tam)
{
    int idMascota;
    
    
    printf("Ingrese id de la mascota: " );
    scanf("%d",&idMascota);
    for(int i=0;i<tam;i++)
    {
        if(idMascota==listado[i].id)
        {
            mostrarTrabajosDeLaMascota(listaTrabajos,listado,tam);
        }
    }
    
}

