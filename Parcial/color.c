#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/** \brief Muestra un array de eColor.
 * \param colores Es el array que va a mostrar.
 * \param tam Es el tamaño del array.
 * \return void.
 */

void mostrarColores(eColor* colores, int tam)
{
    printf("\n    COLORES\n");
    printf(" ID       Descripcion\n");
    printf(" --       -----------\n");
    for(int i=0; i < tam; i++)
    {
        printf(" %d     %-10s\n", (colores+i)->id, (colores+i)->nombreColor);
    }
    printf("\n\n");
}

/** \brief Busca en el array de colores, un color por su ID y lo guarda en una cadena.
 * \param colores Es el array donde va a buscar el idColor.
 * \param tam Es el tamaño del array.
 * \param idColor Es el ID que va a buscar.
 * \param desc Es la cadena de caracteres en donde va a guardar el color.
 * \return 1 si encontro el ID y 0 si no lo encontro.
 */

int obtenerColor(eColor* colores, int tam, int idColor, char* desc)
{
    int todoOk = 0;
    if(colores != NULL && desc != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(idColor == colores[i].id)
            {
                strcpy(desc, (colores+i)->nombreColor);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
