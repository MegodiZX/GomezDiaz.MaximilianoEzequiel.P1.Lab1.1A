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
    int IdTrabajo=0;
    
    inicializarMascotas(listaMascotas,T);
    HarcodearTipos(listaTipos);
    HarcodearColores(listaColores);
    HarcodearServicios(listaServicios);
    inicializarTrabajos(listaTrabajos,T);
    
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
        printf("0.Salir\n");
        printf("Elija una opcion: \n");
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
	            altaTrabajo(listaTrabajos,T,&IdTrabajo);
	        }else
	        {
	            printf("primero ingrese una mascota\n");
	        }
	        
	        break;
	        case 9:
	        mostrarTrabajos(listaTrabajos,T);
	        break;
	        
	    }
    }
    while(respuesta != 0);
    return 0;
}