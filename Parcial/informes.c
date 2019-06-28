#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "disconsi.h"
#include "informes.h"

int mostrarAutosColores(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int opcion;
    int isOk = 0;
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL)
    {
        mostrarColores(colores, tamColor);
        opcion = getInt("Eliga un ID: ");
        for(int i = 0; i<tamAutos; i++)
        {
            if((autos+i)->estado == 1 && (autos+i)->idColor == opcion)
            {
                mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+i);
                isOk = 1;
            }
        }
    }
    return isOk;
}

int mostrarAutosMarca(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int opcion;
    int isOk = 0;
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL)
    {
        mostrarMarca(marcas, tamMarca);
        opcion = getInt("Eliga un ID: ");
        for(int i = 0; i<tamAutos; i++)
        {
            if((autos+i)->estado == 1 && (autos+i)->idMarca == opcion)
            {
                mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+i);
                isOk = 1;
            }
        }
    }
    return isOk;
}

/** \brief Muestra un trabajo por Fecha ingresada
 * \param trabajos Es el array de trabajos donde va a buscar la fecha
 * \param tam Es el tamaño del array
 * \param servicios Es el array de servicios que le va a pasar a mostrarTrabajo
 * \param tamServicios Es el tamaño del array servicios
 * \return void.
 */


int mostrarAutoFecha(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    int isOk = 0;
    if(trabajos != NULL && clientes != NULL && colores != NULL && marcas != NULL && autos != NULL)
    {
        eFecha auxFecha;
        printf("Ingrese fecha: ");
        scanf("%d %d %d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        if(validacionFecha(auxFecha))
        {
            printf("\n");
            printf("FECHA: %d/%d/%d\n\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
            for(int i = 0; i< tamAutos ; i++)
            {
                for(int j=0; j<tamTrabajos; j++)
                {
                    if((trabajos+j)->estado == 1 && (autos+i)->estado == 1 && strcmp((trabajos+j)->patente, (autos+i)->patente) == 0 && compararFechas((trabajos+j)->fecha, auxFecha))
                    {
                        mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, (autos+i));
                        isOk = 1;
                        break;
                    }
                }
            }
        }
        else
            printf("Fecha invalida.\n\n");
    }
    return isOk;
}


int mostrarTrabajoAuto(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int todoOK = 0;
    if(trabajos == NULL || servicios == NULL || colores == NULL || marcas == NULL || autos == NULL || clientes == NULL)
        return todoOK;
    char patente[10];
    char seguir;
    int indice;
    int flag = 0;
    mostrarAutos(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos, tamAutos);
    if(!getStringAlfaNumerico("Ingrese la patente: ", patente))
    {
        printf("Ingrese solo numeros o letras!!\n\n");
        return todoOK;
    }
    if(strlen(patente) > 9)
    {
        printf("La patente es muy larga\n\n");
        return todoOK;
    }
    strupr(patente);
    indice = buscarAuto(autos, tamAutos, patente);
    if(indice == -1)
    {
        printf("La patente no se encuentra en el sistema\n");
        return todoOK;
    }
    printf("El auto que selecciono es: \n");
    mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+indice);
    seguir = tolower(getChar("Desea mostrar los trabajos de este auto? s/n: "));
    printf("\n");
    if(seguir != 's')
    {
        printf("Operacion cancelada. Volviendo al menu...\n");
        return todoOK;
    }
    for(int i = 0; i<tam; i++)
    {
        if((trabajos+i)->estado == 1 && strcmp((trabajos+i)->patente, patente) == 0)
        {
            mostrarTrabajo(servicios, tamServicios, trabajos+i);
            todoOK = 1;
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("No hay trabajos para el auto seleccionado\n");
        todoOK = 0;
    }
    return todoOK;
}

int mostrarAutoSinTrabajo(eTrabajo* trabajos, int tamTrabajo, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int isOk = 0;
    int flag = 0;
    for(int i = 0; i<tamAutos ; i++)
    {
        if((autos+i)->estado == 1)
        {
        for(int j = 0; j<tamTrabajo; j++)
        {
            flag = 0;
            if((trabajos+j)->estado == 1 && (autos+i)->estado == 1 && strcmp((trabajos+j)->patente, (autos+i)->patente) == 0)
            {
                flag = 1;
                break;
            }

        }
        if(flag == 0 )
        {
            mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, (autos+i));
            isOk = 1;
        }
        }
    }
    return isOk;
}

int mostrarImporteDeAuto(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int isOk = 0;
    float importe = 0;
    if(trabajos != NULL && servicios != NULL && colores != NULL && marcas != NULL && autos != NULL && clientes != NULL)
    {
        char patente[10];
        char seguir;
        int indice;
        mostrarAutos(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos, tamAutos);
        if(!getStringAlfaNumerico("Ingrese la patente: ", patente))
        {
            printf("Ingrese solo numeros o letras!!\n\n");
            return isOk;
        }
        if(strlen(patente) > 9)
        {
            printf("La patente es muy larga\n\n");
            return isOk;
        }
        strupr(patente);
        indice = buscarAuto(autos, tamAutos, patente);
        if(indice == -1)
        {
            printf("La patente no se encuentra en el sistema\n");
            return isOk;
        }
        printf("El auto que selecciono es: \n\n");
        mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+indice);
        seguir = tolower(getChar("Desea mostrar los importes de este auto? s/n: "));
        printf("\n");
        if(seguir != 's')
        {
            printf("Operacion cancelada. Volviendo al menu...\n");
            return isOk;
        }
        for(int i = 0; i<tam; i++)
        {
            if((trabajos+i)->estado == 1 && strcmp((trabajos+i)->patente, patente) == 0)
            {
                for(int j = 0; j<tamServicios; j++)
                {
                    if((trabajos+i)->idServicio == (servicios+j)->id)
                    {
                        importe = importe + (servicios+j)->precio;
                        break;
                    }
                }
            }
        }
        printf("El importe total es: %.2f\n", importe);
        isOk = 1;
    }

    return isOk;
}


int mostrarServicioMasPedido(eServicio* servicios, int tamServicios, eTrabajo* trabajos, int tamTrabajo)
{
    int auxMax[tamServicios];
    int indice;
    int max = 0;
    int flag = 0;
    int isOk = 0;
    if(servicios != NULL && trabajos != NULL)
    {
        for(int i=0; i<tamServicios; i++)
        {
            auxMax[i] = 0;
            for(int j=0; j<tamTrabajo; j++)
            {
                if((servicios+i)->id == (trabajos+j)->idServicio)
                {
                    auxMax[i] = auxMax[i] +1;
                }
            }
        }
        for(int i = 0; i<tamServicios; i++)
        {
            if(flag == 0 || max < auxMax[i])
            {
                max = auxMax[i];
                flag = 1;
                indice = i;
            }
        }
        isOk = 1;

        printf("El servicio mas pedido es: %s\n", (servicios+indice)->descripcion);

    }


    return isOk;
}



int mostrarRecaudacionFecha(eTrabajo* trabajos, int tam, eServicio* servicios, int tamServicios)
{
    int isOk = 0;
    float recaudacion = 0;
    if(trabajos != NULL && servicios != NULL)
    {
        eFecha auxFecha;
        printf("Ingrese fecha: ");
        scanf("%d %d %d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        if(validacionFecha(auxFecha))
        {
            printf("\n");
            printf("FECHA: %d/%d/%d\n\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
            for(int i=0; i<tam; i++)
            {
                if(compararFechas((trabajos+i)->fecha, auxFecha))
                {
                    for(int j=0; j<tamServicios; j++)
                    {
                        if((trabajos+i)->idServicio == (servicios+j)->id)
                        {
                            recaudacion += (servicios+j)->precio;
                            isOk = 1;
                        }
                    }
                }
            }
            printf("La recaudacion es: %.2f\n", recaudacion);
        }
        else
            printf("Fecha invalida.\n\n");
    }
    return isOk;
}


int mostrarAutosServicios(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    int opcion;
    int isOk = 0;
    int indice;
    char servicio[21];
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL && servicios != NULL && trabajos != NULL)
    {
        mostrarServicio(servicios, tamServicios);
        opcion = getInt("Eliga un ID: ");
        if(!obtenerServicio(servicios, tamServicios, opcion, servicio))
        {
            printf("El servicio elegido no se encuentra!\n");
            return isOk;
        }
        printf("El servicio que eligio es %s: ", servicio);
        if(!confirma("Confirma? s/n"))
        {
            printf("Informe cancelado! \n");
            return isOk;
        }
        for(int i = 0; i<tamTrabajos; i++)
        {
            if((trabajos+i)->estado == 1 && (trabajos+i)->idServicio == opcion)
            {
                indice = buscarAuto(autos, tamAutos, (trabajos+i)->patente);
                printf("%d/%d/%d    ", (trabajos+i)->fecha);
                mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, (autos+indice));
                isOk = 1;
            }
        }
        isOk = -1;
    }
    return isOk;
}

int trabajosRealizadosAutosXColor(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    int opcion;
    int isOk = 0;
    char color[21];
    //int indice;
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL && servicios != NULL && trabajos != NULL)
    {
        mostrarColores(colores, tamColor);
        opcion = getInt("Eliga un ID: ");
        if(!obtenerColor(colores, tamColor, opcion, color))
        {
            printf("El ID ingresado es invalido!\n");
            return isOk;
        }
        printf("El color que eligio es: %s", color);
        if(!confirma("Confirma? s/n"))
        {
            printf("Informe cancelado!\n");
            return isOk;
        }
        for(int i = 0; i<tamAutos; i++)
        {
            if((autos+i)->estado == 1 && (autos+i)->idColor == opcion)
            {
                for(int j=0; j<tamTrabajos; j++)
                {
                    if((trabajos+j)->estado == 1 && strcmp((trabajos+j)->patente, (autos+i)->patente) == 0)
                    {
                        mostrarTrabajo(servicios, tamServicios, (trabajos+j));
                        isOk = 1;
                    }
                }
            }
        }
        isOk = -1;
    }
    return isOk;
}

int facturacionTotalPorServicio(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    int opcion;
    int isOk = 0;
    float importe = 0;
    int contador = 0;
    char auxServicio[21];
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL && servicios != NULL && trabajos != NULL)
    {
        mostrarServicio(servicios, tamServicios);
        opcion = getInt("Eliga un ID: ");
        if(!obtenerServicio(servicios, tamServicios, opcion, auxServicio))
        {
            printf("El servicio elegido no se encuentra!\n");
            return isOk;
        }
        printf("El servicio que eligio es %s: ", auxServicio);
        if(!confirma("Confirma? s/n: "))
        {
            printf("Informe cancelado! \n");
            return isOk;
        }
        for(int i = 0; i<tamTrabajos; i++)
        {
            if((trabajos+i)->estado == 1 && (trabajos+i)->idServicio == opcion)
            {
                contador ++;
            }
        }
        for(int j = 0; j<tamServicios; j++)
        {
            if((servicios+j)->id == opcion)
            {
                importe = (float) (servicios+j)->precio*contador;
            }
        }
        printf("La facturacion total de %s es: %.2f\n", auxServicio, importe);
        isOk = 1;
    }
    return isOk;
}

int marcaMasServicios(eAuto* autos, int tamAutos, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    int opcion;
    int isOk = 0;
    int auxMax[tamMarca];
    int max;
    int flag = 0;
    int indice;
    char auxServicio[21];
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL && servicios != NULL && trabajos != NULL)
    {
        mostrarServicio(servicios, tamServicios);
        opcion = getInt("Eliga un ID: ");
        if(!obtenerServicio(servicios, tamServicios, opcion, auxServicio))
        {
            printf("El servicio elegido no se encuentra!\n");
            return isOk;
        }
        printf("El servicio que eligio es %s: ", auxServicio);
        if(!confirma("Confirma? s/n: "))
        {
            printf("Informe cancelado! \n");
            return isOk;
        }
        for(int i = 0; i < tamMarca ; i++)
        {
            auxMax[i] = 0;
            for(int j = 0; j < tamAutos; j++)
            {
                if((autos+j)-> estado == 1 && (autos+j)->idMarca == (marcas+i)->id)
                {
                    for(int y = 0; y < tamTrabajos ; y++)
                    {
                        if((trabajos+y)->estado == 1 && (trabajos+y)->idServicio == opcion && strcmp((trabajos+y)->patente, (autos+j)->patente) == 0)
                            auxMax[i]++;
                    }
                }
            }
        }
        for(int i = 0; i < tamMarca; i++)
        {
            if(flag == 0 || max < auxMax[i])
            {
                max = auxMax[i];
                flag = 1;
                indice = i;
            }
        }
        printf("La marca %s es la que efectua mas servicio %s\n", (marcas+indice)->descripcion, auxServicio);
        isOk = 1;
    }
    return isOk;
}


