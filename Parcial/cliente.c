#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

void mostrarCliente(eCliente* clientes, int tam)
{
    if(clientes != NULL)
    {
        printf("\n    CLIENTES\n");
    printf("    ID       Descripcion    SEX\n");
    printf("    --       -----------    ---\n");
    for(int i=0; i < tam; i++){
        printf("    %-5d     %-10s     %c\n", (clientes+i)->id, (clientes+i)->nombre, (clientes+i)->sexo);
    }
    printf("\n\n");
    }
}

int obtenerCliente(eCliente* clientes, int tam, int idCliente, char* desc, char* sex)
{
    int todoOk = 0;
    if(clientes != NULL && desc != NULL && sex != NULL)
    {
        for(int i=0; i < tam; i++)    {
        if(idCliente == (clientes+i)->id)
        {
            strcpy(desc, (clientes+i)->nombre);
            *sex = toupper((clientes+i)->sexo);
            todoOk = 1;
            break;
        }
        }
    }
    return todoOk;
}
