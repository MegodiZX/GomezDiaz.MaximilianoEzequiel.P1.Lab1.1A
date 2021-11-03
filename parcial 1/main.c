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
    void TotalPreciosDeUnaMascota(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam, int* total);
    void PedirMascotaYMostrarImporteTotalDeLosServicios(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam);
    void MostrarMascotaYfechaSegunServicio(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam);
    void mostrarServiciosRealizadosEnFechaIngresada(eTrabajo listaTrabajos[],eServicio listadoServicios[], int tam);
    
    do
    {
        printf("\n1.Alta Mascota\n");
        printf("2.Modificar Mascota\n");
        printf("3.Baja Mascota\n");
        printf("4.Listar mascotas (ordenadas por tipo y nombre)\n");
        printf("5.Listar tipos \n");
        printf("6.Listar colores\n");
        printf("7.Listar servicios\n");
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
                printf("\n1.Mostrar mascotas del color seleccionado\n");
                printf("2.Mascotas vacunadas sobre el promedio\n");
                printf("3.Informar la/s mascotas con menor edad\n");
                printf("4.Listar mascotas por tipo (separadas)\n");
                printf("5.Elegir el color y tipo de mascota\n");
                printf("6.Mostrar los colores con mas cantidad de mascota/s\n");
                printf("7.Mostrar trabajos de una mascota\n");
                printf("8.Mostrar monto total de una mascota\n");
                printf("9.Mostrar mascota y fecha de un servicio especifico\n");
                printf("10.Mostrar todos los servicios de una fecha\n");
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
        	        if(cargoMascota==1)
        	        {
        	            mostrarTodasLasMascotas(listaMascotas,T);
        	            PedirMascotaYMostrarTrabajos(listaTrabajos,listaMascotas,T);
        	        }else
        	        {
        	            printf("primero ingrese una mascota\n");
        	        }
        	        break;
        	        case 8:
        	        if(cargoMascota==1)
        	        {
        	            mostrarTodasLasMascotas(listaMascotas,T);
        	            PedirMascotaYMostrarImporteTotalDeLosServicios(listaTrabajos,listaMascotas,listaServicios,T);
        	        }else
        	        {
        	            printf("primero ingrese una mascota\n");
        	        }
        	        break;
        	        case 9:
        	        if(cargoMascota==1)
        	        {
        	            mostrarServicios(listaServicios,3);
        	            MostrarMascotaYfechaSegunServicio(listaTrabajos,listaMascotas,listaServicios,T);
        	        }else
        	        {
        	            printf("primero ingrese una mascota\n");
        	        }
        	        break;
        	        case 10:
        	        if(cargoMascota==1)
        	        {
        	            mostrarServiciosRealizadosEnFechaIngresada(listaTrabajos,listaServicios,T);
        	        }else
        	        {
        	            printf("primero ingrese una mascota\n");
        	        }
        	        
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

void TotalPreciosDeUnaMascota(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam, int* total)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(listaTrabajos[i].idMascota==listado[j].id)
            {
                for(int j=0;j<3;j++)
                {
                    if(listaTrabajos[i].idServicio==listadoServicios[j].id)
                    {
                        *total=(*total)+listadoServicios[j].precio;
                    }
                }
                
                
            }
        }
        
    }
}

void PedirMascotaYMostrarImporteTotalDeLosServicios(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam)
{
    int idMascota;
    int total=0;
    int* pTotal=&total;
    printf("Ingrese id de la mascota: " );
    scanf("%d",&idMascota);
    for(int i=0;i<tam;i++)
    {
        if(idMascota==listado[i].id)
        {
            TotalPreciosDeUnaMascota(listaTrabajos,listado,listadoServicios,tam,pTotal);
        }
    }
    
    printf("\nMonto total por los servicios: %d\n\n",total);
}

void MostrarMascotaYfechaSegunServicio(eTrabajo listaTrabajos[],eMascota listado[],eServicio listadoServicios[], int tam)
{
    int ServicioIngresado;
    printf("Ingrese id servicio: ");
    printf("--Anotacion del programa-- estan harcodeados los trabajos y hay asignados 2 mascotas,id 100 id 101 ingrese 2 mascotas para que funcione correctamente");
    scanf("%d",&ServicioIngresado);
    while(ServicioIngresado!=20000&&ServicioIngresado!=20001&&ServicioIngresado!=20002)
    {
        printf("Error reingrese id servicio: ");
        scanf("%d",&ServicioIngresado);
    }
    for(int i=0;i<tam;i++)
    {
        if(ServicioIngresado==listaTrabajos[i].idServicio)
        {
            for(int j=0;j<tam;j++)
            {
                if(listaTrabajos[i].idMascota==listado[j].id)
                {
                    mostrarMascota(listado[j]);
                }
            }
            printf("\t fecha del servicio: %d/%d/%d\n",listaTrabajos[i].fecha.dia,listaTrabajos[i].fecha.mes,listaTrabajos[i].fecha.anio);
        }
    }
}

void mostrarServiciosRealizadosEnFechaIngresada(eTrabajo listaTrabajos[],eServicio listadoServicios[], int tam)
{
    eFecha fechaIngresada;
    
    printf("Ingrese fecha de la que desea ver los servicios (dia,mes,anio): ");
    printf("--Anotacion del programa-- 4/9/2021 (2 trabajos) 12/3/2021 (1 trabajo)");
    scanf("%d",&fechaIngresada.dia);
    scanf("%d",&fechaIngresada.mes);
    scanf("%d",&fechaIngresada.anio);
    
    for(int i=0;i<tam;i++)
    {
        if(fechaIngresada.dia==listaTrabajos[i].fecha.dia&&fechaIngresada.mes==listaTrabajos[i].fecha.mes&&fechaIngresada.anio==listaTrabajos[i].fecha.anio)
        {
            switch(listaTrabajos[i].idServicio)
            {
                case 20000:
                mostarServicio(listadoServicios[0]);
                break;
                case 20001:
                mostarServicio(listadoServicios[1]);
                break;
                case 20002:
                mostarServicio(listadoServicios[2]);
                break;
            }
        }
    }
    
}
