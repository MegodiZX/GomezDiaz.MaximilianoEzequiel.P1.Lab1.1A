typedef struct
{
    int id;//autoincremental
    int idMascota;//debe existir
    int idServicio;//debe existir
    eFecha fecha;// validar dia,mes,año
}eTrabajo;

void mostrarTrabajo(eTrabajo lista);
void mostrarTrabajos(eTrabajo lista[],int tam);
int buscarLibreTrabajo(eTrabajo lista[],int tam);
int altaTrabajo(eTrabajo lista[],int tam,int* pIdT);