typedef struct
{
    int id;
    char nombre[20];
    int idTipo;//validar
    int idColor;//validar
    int edad;
    char vacunado;//s o n
    int isEmpty;
}eMascota;

void inicializarMascotas();
//pone los estados de mascota en LIBRE
int buscarLibre(eMascota lista[],int tam);
//busca una mascota con el estado LIBRE y pasa su direccion de indice
int altaMascota(eMascota listado[], int tam,int* pId);
//Crea una mascota auxiliar, copia los parametros ingresados en una mascota del array
void mostrarMascota(eMascota unaMascota);
//imprime una mascota
int mostrarTodasLasMascotas(eMascota lista[],int tam);
//lista todas las mascotas cargadas
void modificarMascota(eMascota listado[], int tam);
//se permite modificar tipo o vacunado
void bajaMascota(eMascota listado[], int tam);
//pone el estado de la mascota selecionada en ELIMINADO
void ordenarMascotasPorTipo(eMascota listado[], int tam);
//ordena la lista por tipo
void ordenarMascotasPorNombre(eMascota listado[], int tam);
//ordena la lista por nombre
void ordenarMascotasPorTipoYNombre(eMascota listado[], int tam);
//ordena la lista por tipo y nombre y muestra todas las mascotas cargadas
void mostrarMascotaColorSelec(eMascota listado[], int tam);
void promedioVacunados(eMascota listado[], int tam);
void listarMascotasDeMenorEdad(eMascota listado[], int tam);
void listarMascotasSeparadasPorTipo(eMascota listado[], int tam);
int ContarColorYTipo(eMascota listado[], int tam);
void ColorMasCantidadMascota(eMascota listado[], int tam);
