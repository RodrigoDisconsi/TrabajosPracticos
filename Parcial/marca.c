#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"


/** \brief Muestra un array de eMarca.
 * \param marcas Es el array que va a mostrar.
 * \param tam Es el tamaño del array.
 * \return void.
 */

void mostrarMarca(eMarca* marcas, int tam)
{
    if(marcas != NULL)
    {
        printf("\n    MARCAS\n");
        printf(" ID       Descripcion\n");
        printf(" --       -----------\n");
        for(int i=0; i < tam; i++)
        {
            printf(" %d     %-10s\n", (marcas+i)->id, (marcas+i)->descripcion);
        }
        printf("\n\n");
    }
}

/** \brief Busca en el array de marcas, una marca por su ID y lo guarda en una cadena.
 * \param marcas Es el array donde va a buscar el idMarca.
 * \param tam Es el tamaño del array.
 * \param idMarca Es el ID que va a buscar.
 * \param desc Es la cadena de caracteres en donde va a guardar la marca.
 * \return 1 si encontro el ID y 0 si no lo encontro.
 */

int obtenerMarca(eMarca* marcas, int tam, int idMarca, char desc[])
{
    int todoOk = 0;
    if(marcas != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(idMarca == (marcas+i)->id)
            {
                strcpy(desc, (marcas+i)->descripcion);
                todoOk = 1;
                break;
            }
        }
        return todoOk;
    }
}
