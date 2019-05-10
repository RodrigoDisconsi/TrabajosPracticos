#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include <ctype.h>
#include "ArrayEmpleado.h"
#include "disconsi.h"

void inicializarEmpleados(eEmpleado empleados[], int tam)
{
        for(int i = 0; i < tam ; i++)
        {
            empleados[i].ocupado = 0;
        }
}

int buscarLibre(eEmpleado empleados[], int tam)
{
    int indice = -1;
         for(int i= 0; i<tam; i++)
         {
             if(empleados[i].ocupado == 0)
             {
                 indice = i;
                 break;
             }
         }
    return indice;
}

int altaEmpleado(eEmpleado empleados[], int tam, int* id)
{
    int indice;
    int auxiliarSector;
    float auxiliarSueldo;
    char auxSector[10];
    char auxApellido[100];
    char auxNombre[100];
    char auxSueldo[20];
    indice = buscarLibre(empleados, tam);
    if(indice == -1)
    {
        printf("No hay lugar en el sistema.\n");
        return 0;
    }
    if(!getStringLetras("Ingrese el nombre: ", auxNombre))
    {
        printf("Ingrese solo letras!!\n\n");
        return 0;
    }
    if(strlen(auxNombre) > 50)
    {
        printf("El nombre es muy largo\n\n");
        return 0;
    }
    auxNombre[0] = toupper(auxNombre[0]);
    if(!getStringLetras("Ingrese el apellido: ", auxApellido))
    {
        printf("Ingrese solo letras!!\n\n");
        return 0;
    }
    if(strlen(auxApellido) > 50)
    {
        printf("El apellido es muy largo\n\n");
        return 0;
    }
    auxApellido[0] = toupper(auxApellido[0]);
    if(!getStringNumeros("Ingrese el sueldo: ", auxSueldo))
    {
        printf("Ingrese solo numeros!!\n\n");
        return 0;
    }
    auxiliarSueldo = atof(auxSueldo);
    if(!getStringNumeros("Ingrese un sector entre 1 y 5: ", auxSector))
    {
        printf("Ingrese solo numeros");
        return 0;
    }
    auxiliarSector = atoi(auxSector);
    if(auxiliarSector < 1 || auxiliarSector > 5)
    {
        printf("El sector ingresado es invalido.\n\n");
        return 0;
    }
    empleados[indice].id = *id;
    *id = *id + 1;
    strcpy(empleados[indice].nombre, auxNombre);
    strcpy(empleados[indice].apellido, auxApellido);
    empleados[indice].sueldo = auxiliarSueldo;
    empleados[indice].sector = auxiliarSector;
    empleados[indice].ocupado = 1;
    return 1;
}

int buscarEmpleado(eEmpleado empleados[], int tam, int id)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].ocupado == 1 && empleados[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaEmpleado(eEmpleado empleados[], int tam){

    int id;
    char confirma;
    int esta;
    id = getInt("Ingrese un id: ");
    esta = buscarEmpleado(empleados, tam, id);
    if( esta == -1)
    {
        printf("\nEl id %d no esta registrado en el sistema\n", id);
    }
    else{
        mostrarEmpleado(empleados[esta]);
        confirma = tolower(getChar("\nConfirma la eliminiacion? s/n: "));

        if(confirma == 's')
        {
            empleados[esta].ocupado = 0;
            printf("Baja empleado exitosa!!\n");
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }
}

void mostrarEmpleado(eEmpleado empleados)
{
    printf("%d        %2d           %-10s      %-10s        %.2f\n", empleados.id, empleados.sector, empleados.nombre, empleados.apellido, empleados.sueldo);
}

void mostrarEmpleados(eEmpleado empleados[], int tam)
{
    system("cls");
    printf("Legajo     Sector        Nombre          Apellido          Sueldo\n");
    printf("------     ------        ------          --------          ------\n");
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].ocupado == 1)
        {
            mostrarEmpleado(empleados[i]);
        }
    }
    printf("\n\n");
}

void ordenarEmpleados(eEmpleado empleados[], int tam, int order)
{
    eEmpleado auxEmpleado;
    for (int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j<tam ; j++)
            {
            if(!order)
            {
                if(empleados[j-1].ocupado == 1 && empleados[i].sector < empleados[j].sector)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
                if(empleados[j-1].ocupado == 1 && empleados[i].sector == empleados[j].sector)
                {
                    if(strcmp(empleados[i].apellido, empleados[j].apellido) < 0)
                    {
                        auxEmpleado = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxEmpleado;
                    }
                }

            }
            else
            {
                if(empleados[j-1].ocupado == 1 && empleados[i].sector > empleados[j].sector)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
                if(empleados[j-1].ocupado == 1 && empleados[i].sector == empleados[j].sector)
                {
                    if(strcmp(empleados[i].apellido, empleados[j].apellido) > 0)
                    {
                        auxEmpleado = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxEmpleado;
                    }
                }
            }
            }
        }
}

void totalPromedioSalarios(eEmpleado empleados[], int tam)
{
    int sueldoMayorAProm = 0;
    int contador = 0;
    int flag = 0;
    float acumulador = 0;
    float promedio;
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].ocupado == 1)
            {
                acumulador += empleados[i].sueldo;
                contador ++;
                flag ++;
            }
        }
        promedio = (float) acumulador / contador;
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].sueldo > promedio)
            {
                sueldoMayorAProm ++;
            }
        }
        if(flag)
            printf("El total de los salarios es %.1f, el promedio %.2f y la cantidad que superan el promedio %d\n\n", acumulador, promedio, sueldoMayorAProm);
}

void modificarEmpleado(eEmpleado empleados[], int tam)
{
    int id, indice, auxSector;
    char auxCharSector[5];
    char auxCharSalario[10];
    char confirma;
    char auxNameOrLastname[51];
    float auxSalario;
    id = getInt("Ingrese un ID: ");
    indice = buscarEmpleado(empleados, tam, id);
    if(indice == -1)
    {
        printf("El ID no se encuentra en el sistema\n");
    }
    else
    {
        system("cls");
        printf("Legajo     Sector        Nombre          Apellido          Sueldo\n");
        printf("------     ------        ------          --------          ------\n");
        mostrarEmpleado(empleados[indice]);
        printf("\n\n");
        switch(menuModificar())
        {
        case 1:
            if(!getStringLetras("Ingrese el nuevo nombre: ", auxNameOrLastname) || strlen(auxNameOrLastname) > strlen(empleados[indice].nombre))
            {
                printf("El nombre es muy largo o contiene caracteres invalidos\n\n");
                break;
            }
            printf("El nombre que ingreso fue %s \n", auxNameOrLastname);
            confirma = getChar("Desea cambiar el nombre? s/n: ");
            if(confirma == 's')
            {
                strcpy(empleados[indice].nombre, auxNameOrLastname);
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
        case 2:
            if(!getStringLetras("Ingrese el nuevo apellido: ", auxNameOrLastname) || strlen(auxNameOrLastname) > strlen(empleados[indice].apellido))
            {
                printf("El apellido es muy largo o contiene caracteres invalidos\n\n");
                break;
            }
            printf("El apellido que ingreso fue %s \n", auxNameOrLastname);
            confirma = tolower(getChar("Desea cambiar el sector? s/n: "));
            if(confirma == 's')
            {
                strcpy(empleados[indice].apellido, auxNameOrLastname);
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
        case 3:
            if(!getStringNumeros("Ingrese un nuevo sueldo: ", auxCharSalario))
            {
                printf("Error: Ingrese solo numeros\n\n");
                break;
            }
            auxSalario = atof(auxCharSalario);
            printf("El sueldo que ingreso fue %.2f \n", auxSalario);
            confirma = tolower(getChar("Desea cambiar el sector? s/n: "));
            if(confirma == 's')
            {
                empleados[indice].sueldo = auxSalario;
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
        case 4:
            if(!getStringNumeros("Ingrese un nuevo sector: ", auxCharSector))
            {
                printf("Error: Ingrese solo numeros\n\n");
                break;
            }
            auxSector = atoi(auxCharSector);
            if(auxSector < 1 || auxSector >5)
            {
                printf("El sector es invalido\n");
                break;
            }
            printf("El sector que ingreso fue %d\n", auxSector);
            confirma = tolower(getChar("Desea cambiar el sector? s/n: "));
            if(confirma == 's')
            {
                empleados[indice].sector = auxSector;
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
            break;
        case 5:
            printf("Modificacion cancelada. \n\n");
            break;
        default:
            printf("Opcion invalida");
        }
    }
}

int hayEmpleadoParaMostrar(eEmpleado empleados[], int tam)
{
    int indice = -1;
         for(int i= 0; i<tam; i++)
         {
             if(empleados[i].ocupado == 1)
             {
                 indice = i;
                 break;
             }
         }
    return indice;
}
