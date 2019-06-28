#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "disconsi.h"
#include "trabajo.h"

/** \brief Inicializa el estado en un array del tipo eTrabajo.
 * \param  trabajos Es el array de trabajo que va a inicializar.
 * \param  tam Es el tamaño del array.
 * \return No retorna nada.
 */


void inicializarTrabajos(eTrabajo* trabajos, int tam)
{
    if(trabajos != NULL)
    {
        for(int i = 0; i < tam ; i++)
        {
            (trabajos+i)->estado = 0;
        }
    }
}

/** \brief Busca en el array de trabajos el primer lugar libre y lo devuelve (campo estado = 0).
 * \param  trabajos Es el array de trabajo donde va a buscar el lugar libre.
 * \param  tam Es el tamaño del array.
 * \return Retorna el indice del primer trabajo libre y si no encuentra ninguno retorna -1 y -2 si trabajos es igual a NULL.
 */


int buscarLibreTrabajo(eTrabajo* trabajos, int tam)
{
    int indice = -1;
    if(trabajos != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            if((trabajos+i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
        return indice;
    }
    else
        indice = -2;
    return indice;
}

/** \brief Da de alta un trabajo en el primer lugar libre.
 * \param  trabajos Es el array de trabajos donde va a cagar el trabajo dado de alta.
 * \param  tam Es el tamaño del array.
 * \param  servicios Es el array de servicios para mostrar y que el usuario elija uno.
 * \param  tamServicio Es el tamaño del array servicios.
 * \param  autos Es el array de autos para validar si la patente que ingresa existe.
 * \param  tamAutos Es el tamaño del array autos.
 * \param  colores Es el array de colores para mostrar el auto.
 * \param  tamColor Es el tamaño del array colores.
 * \param  marcas Es el array de marcas para mostrar el auto.
 * \param  tamMarca Es el tamaño del array marcas.
 * \param  id Es un pasaje por referencia del ID para que sea autoincremental y no tenga que ingresarlo el usuario.
 * \return Retorna 1 si se pudo completar el alta sin problemas o 0 si no se pudo completar el alta.
 */


int altaTrabajo(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eAuto* autos, int tamAutos, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamClientes, int* id)
{
    if(trabajos == NULL || servicios == NULL || autos == NULL || colores == NULL || marcas == NULL || clientes == NULL)
        return 0;
    int indice;
    int indiceAuto;
    int auxiliarServicio;
    char confirmaAuto;
    char confirmaServicio;
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    char auxServicio[26];
    char auxPatente[10];
    eFecha auxFecha;
    indice = buscarLibreTrabajo(trabajos, tam);
    if(indice == -1)
    {
        printf("No hay lugar en el sistema.\n");
        return 0;
    }
    if(!getStringAlfaNumerico("Ingrese la patente: ", auxPatente))
    {
        printf("Ingrese solo numeros o letras!!\n\n");
        return 0;
    }
    if(strlen(auxPatente) > 9)
    {
        printf("La patente es muy larga\n\n");
        return 0;
    }
    strupr(auxPatente);
    indiceAuto = buscarAuto(autos, tam, auxPatente);
    if(indiceAuto == -1)
    {
        printf("La patente no se encuentra en el sistema\n\n");
        return 0;
    }
    mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamClientes, autos+indiceAuto);
    confirmaAuto = tolower(getChar("\nConfirma? s/n: "));
    if(confirmaAuto != 's')
    {
        printf("Alta cancelada\n");
        return 0;
    }
    mostrarServicio(servicios, tamServicios);
    auxiliarServicio = getInt("Ingrese el servicio: ");
    if(!obtenerServicio(servicios, tamServicios, auxiliarServicio, auxServicio))
    {
        printf("El servicio ingresado es invalido\n\n");
        return 0;
    }
    printf("El servicio que ingreso es %s.\n", auxServicio);
    confirmaServicio = tolower(getChar("Confirma? s/n: "));
    if(confirmaServicio != 's')
    {
        printf("Alta cancelada.\n\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese dia: ", auxDia, "Ingrese solo numeros!!\n\n"))
        return 0;
    auxFecha.dia = atoi(auxDia);
    if(!getStringNumeros("Ingrese mes: ", auxMes, "Ingrese solo numeros!!\n\n"))
        return 0;
    auxFecha.mes = atoi(auxMes);
    if(!getStringNumeros("Ingrese anio: ", auxAnio, "Ingrese solo numeros!!\n\n"))
        return 0;
    auxFecha.anio = atoi(auxAnio);
    if(!validacionFecha(auxFecha))
    {
        printf("ERROR. Fecha invalida\n\n");
        return 0;
    }
    (trabajos+indice)->id = *id;
    (trabajos+indice)->idServicio = auxiliarServicio;
    strcpy((trabajos+indice)->patente, auxPatente);
    (trabajos+indice)->fecha = auxFecha;
    (trabajos+indice)->estado = 1;
    *id = *id + 1;
    return 1;
}

/** \brief Muestra un trabajo.
 * \param servicios Es el array de servicios donde va a buscar el servicio.
 * \param tam Es el tamaño del array de servicios.
 * \param trabajo Es el trabajo que va a mostrar.
 * \return void.
 */


void mostrarTrabajo(eServicio* servicios, int tam, eTrabajo* trabajo)
{
    char nombreServicio[26];
    int consiguioServicio;

    consiguioServicio =  obtenerServicio(servicios, tam, trabajo->idServicio, nombreServicio);

    if( !consiguioServicio)
    {
        strcpy(nombreServicio, "Sin definir");
    }

    printf("%d       %-10s    %-10s     %d/%d/%d\n", trabajo->id, trabajo->patente, nombreServicio, trabajo->fecha);
}

/** \brief Muestra un array de eTrabajo*.
 * \param trabajos Es el array que va a mostrar.
 * \param tam Es el tamaño del array de trabajos.
 * \param servicios Es el array que le pasa a mostrarTrabajo.
 * \param tamServicio Es tamaño del array servicios.
 * \return void.
 */

void mostrarTrabajos(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicio)
{
    if(trabajos != NULL && servicios != NULL)
    {
        system("cls");
        int contador = 0;
        printf(" ID        Patente       Servicio        FECHA\n");
        printf(" --        -------       --------        -----\n");
        for(int i=0; i < tam; i++)
        {
            if((trabajos+i)->estado == 1)
            {
                mostrarTrabajo(servicios, tamServicio, trabajos+i);
                contador ++;
            }
        }
        if(contador == 0 )
            printf("No hay empleados para mostrar\n");
        printf("\n\n");
    }
}

/** \brief Busca si hay un trabajo activo en el array de trabajos.
 * \param trabajos Es el array donde va a buscar.
 * \param tam Es el tamaño del array de trabajos.
 * \return -1 si no encuentra ninguno o el indice si lo encuentra.
 */

int hayTrabajoParaMostrar(eTrabajo* trabajos, int tam)
{
    int indice = -1;
    if(trabajos != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            if((trabajos+i)->estado == 1)
            {
                indice = i;
                break;
            }
        }
        return indice;
    }
    else
        indice = -2;
    return indice;

}

