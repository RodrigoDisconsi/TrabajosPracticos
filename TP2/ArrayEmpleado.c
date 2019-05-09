#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include <ctype.h>
#include "ArrayEmpleado.h"
#include "disconsi.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{
        for(int i = 0; i < tam ; i++)
        {
            vec[i].ocupado = 0;
        }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
         for(int i= 0; i<tam; i++)
         {
             if(vec[i].ocupado == 0)
             {
                 indice = i;
                 break;
             }
         }
    return indice;
}

int altaEmpleado(eEmpleado vec[], int tam, int* legajo)
{
    int indice;
    int auxiliarSector;
    float auxiliarSueldo;
    char auxSector[10];
    char auxApellido[100];
    char auxNombre[100];
    char auxSueldo[20];
    indice = buscarLibre(vec, tam);
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
    if(strlen(auxApellido) >50 )
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
    if(auxiliarSector < 0 || auxiliarSector > 5)
    {
        printf("El sector ingresado es invalido.\n\n");
        return 0;
    }
    *legajo = *legajo + 1;
    vec[indice].legajo = *legajo;
    strcpy(vec[indice].nombre, auxNombre);
    strcpy(vec[indice].apellido, auxApellido);
    vec[indice].sueldo = auxiliarSueldo;
    vec[indice].sector = auxiliarSector;
    vec[indice].ocupado = 1;
    return 1;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaEmpleado(eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    int esta;
    legajo = getInt("Ingrese un legajo: ");
    esta = buscarEmpleado(vec, tam, legajo);
    if( esta == -1)
    {
        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);
        confirma = tolower(getChar("\nConfirma la eliminiacion? s/n: "));

        if(confirma == 's')
        {
            vec[esta].ocupado = 0;
            printf("Baja empleado exitosa!!\n");
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("%d        %d     %10s       %10s        %.2f\n", emp.legajo, emp.sector, emp.nombre, emp.apellido, emp.sueldo);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;
    system("cls");
    printf("Legajo     Sector      Nombre         Apellido        Sueldo\n");
    printf("------     ------      ------         --------        ------\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }
    printf("\n\n");
    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam, int order)
{
    eEmpleado auxEmpleado;
    for (int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j<tam ; j++)
            {
            if(!order)
            {
                if(vec[j-1].ocupado == 1 && vec[i].sector < vec[j].sector)
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
                if(vec[j-1].ocupado == 1 && vec[i].sector == vec[j].sector)
                {
                    if(strcmp(vec[i].apellido, vec[j].apellido) < 0)
                    {
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                    }
                }

            }
            else
            {
                if(vec[j-1].ocupado == 1 && vec[i].sector > vec[j].sector)
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
                if(vec[j-1].ocupado == 1 && vec[i].sector == vec[j].sector)
                {
                    if(strcmp(vec[i].apellido, vec[j].apellido) > 0)
                    {
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                    }
                }
            }
            }
        }
}

void totalPromedioSalarios(eEmpleado vec[], int tam)
{
    int sueldoMayorAProm = 0;
    int contador = 0;
    float acumulador = 0;
    float promedio;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].ocupado == 1)
            {
                acumulador += vec[i].sueldo;
                contador ++;
            }
        }
        promedio = (float) acumulador / contador;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].sueldo > promedio)
            {
                sueldoMayorAProm ++;
            }
        }
    printf("El total de los salarios es %.1f, el promedio %.2f y la cantidad que superan el promedio %d\n\n", acumulador, promedio, sueldoMayorAProm);
}

void modificarEmpleado(eEmpleado vec[], int tam)
{
    int legajo, indice, auxSector;
    char auxCharSector[5];
    char auxCharSalario[10];
    char confirma;
    char auxNameOrLastname[51];
    float auxSalario;
    legajo = getInt("Ingrese un legajo: ");
    indice = buscarEmpleado(vec, tam, legajo);
    if(indice == -1)
    {
        printf("El legajo no se encuentra en el sistema\n");
    }
    else
    {
        mostrarEmpleado(vec[indice]);
        system("pause");
        switch(menuModificar())
        {
        case 1:
            if(!getStringLetras("Ingrese el nuevo nombre: ", auxNameOrLastname) || strlen(auxNameOrLastname) > strlen(vec[indice].nombre))
            {
                printf("El nombre es muy largo o contiene caracteres invalidos\n\n");
                break;
            }
            printf("El nombre que ingreso fue %s \n", auxNameOrLastname);
            confirma = getChar("Desea cambiar el nombre? s/n");
            if(confirma == 's')
            {
                strcpy(vec[indice].nombre, auxNameOrLastname);
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
        case 2:
            if(!getStringLetras("Ingrese el nuevo apellido: ", auxNameOrLastname) || strlen(auxNameOrLastname) > strlen(vec[indice].apellido))
            {
                printf("El apellido es muy largo o contiene caracteres invalidos\n\n");
                break;
            }
            printf("El apellido que ingreso fue %s \n", auxNameOrLastname);
            confirma = tolower(getChar("Desea cambiar el sector? s/n: "));
            if(confirma == 's')
            {
                strcpy(vec[indice].apellido, auxNameOrLastname);
                printf("Modificacion exitosa!\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                break;
            }
        case 3:
            if(!getStringNumeros("Ingrese un nuevo sueldo", auxCharSalario))
            {
                printf("Error: Ingrese solo numeros\n\n");
                break;
            }
            auxSalario = atof(auxCharSalario);
            printf("El sueldo que ingreso fue %.2f \n", auxSalario);
            confirma = tolower(getChar("Desea cambiar el sector? s/n: "));
            if(confirma == 's')
            {
                vec[indice].sueldo = auxSalario;
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
                vec[indice].sector = auxSector;
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


