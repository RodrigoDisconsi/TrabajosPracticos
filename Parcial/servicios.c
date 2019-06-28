#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

/** \brief Muestra un array de eServicio.
 * \param servicios Es el array que va a mostrar.
 * \param tam Es el tamaño del array.
 * \return void.
 */


void mostrarServicio(eServicio* servicios, int tam)
{
    if(servicios != NULL)
    {
        printf("\n    SERVICIOS\n");
        printf(" ID       Descripcion\n");
        printf(" --       -----------\n");
        for(int i=0; i < tam; i++)
        {
            printf("%d     %-10s\n", (servicios+i)->id, (servicios+i)->descripcion);
        }
        printf("\n\n");
    }
}

/** \brief Busca en el array de servicio, un servicio por su ID y lo guarda en una cadena
 * \param servicios Es el array donde va a buscar el idServicio
 * \param tam Es el tamaño del array
 * \param idServicio Es el ID que va a buscar
 * \param desc Es la cadena de caracteres en donde va a guardar el servicio
 * \return 1 si encontro el ID y 0 si no lo encontro
 */


int obtenerServicio(eServicio* servicios, int tam, int idServicio, char desc[])
{
    int todoOk = 0;
    for(int i=0; i < tam; i++)
    {
        if(idServicio == (servicios+i)->id)
        {
            strcpy(desc, (servicios+i)->descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

