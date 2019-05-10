#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include <ctype.h>
#include "ArrayEmpleado.h"
#include "disconsi.h"

/** \brief Inicializa el ocupado en un array de eEmpleados.
 * \param  empleados Es el array de empleados que va a inicializar.
 * \param  tam Es el tamaño del array.
 * \return No retorna nada.
 */


void inicializarEmpleados(eEmpleado empleados[], int tam)
{
        for(int i = 0; i < tam ; i++)
        {
            empleados[i].ocupado = 0;
        }
}

/** \brief Busca en el array de empleado el primer lugar libre y lo devuelve (campo ocupado = 0).
 * \param  empleados Es el array de empleados donde va a buscar el lugar libre.
 * \param  tam Es el tamaño del array.
 * \return Retorna el indice del primer empleado libre y si no encuentra ninguno retorna -1.
 */

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

/** \brief Da de alta un empleado con todas las validaciones correspondientes.
 * \param  empleados Es el array de empleados donde va a cagar el empleado dado de alta.
 * \param  tam Es el tamaño del array.
 * \param  id Es un pasaje por referencia del ID para que sea autoincremental y no tenga que ingresarlo el usuario.
 * \return Retorna 1 si se pudo completar el alta sin problemas o 0 si no se pudo completar el alta.
 */

int altaEmpleado(eEmpleado empleado[], int tam, int* id)
{
    int indice;
    int auxiliarSector;
    float auxiliarSueldo;
    char auxSector[10];
    char auxApellido[100];
    char auxNombre[100];
    char auxSueldo[20];
    indice = buscarLibre(empleado, tam);
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
    //strlwr(auxNombre);    A VECES ME TIRA WARNING COMO SI NO HUBIESE PUESTO LA BIBLITOECA STRING.H POR ESO LA COMENTE
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
    //strlwr(auxApellido); A VECES ME TIRA WARNING COMO SI NO HUBIESE PUESTO LA BIBLITOECA STRING.H POR ESO LA COMENTE
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
    empleado[indice].id = *id;
    *id = *id + 1;
    strcpy(empleado[indice].nombre, auxNombre);
    strcpy(empleado[indice].apellido, auxApellido);
    empleado[indice].sueldo = auxiliarSueldo;
    empleado[indice].sector = auxiliarSector;
    empleado[indice].ocupado = 1;
    return 1;
}

/** \brief Busca un empleado por su ID.
 * \param empleados Es el array de empleados donde va a buscar el ID.
 * \param empleados Es el tamaño del array de empleados.
 * \param empleados Es el ID que va a buscar.
 * \return retorna -1 si no lo encuentra y si lo encuentra retorna el indice del empleado
 */


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

/** \brief Da de baja lógica un empleado buscandolo por su ID
 * \param  empleados Es el array de empleados donde va a buscar el ID
 * \param  empleados Es el tamaño del array de empleados
 * \return No retorna nada
 */


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

/** \brief Muestra un solo empleado.
 * \param empleados Es 1 empleado.
 * \return No retorna nada.
 */

void mostrarEmpleado(eEmpleado empleados)
{
    printf("%d        %2d           %-10s      %-10s        %.2f\n", empleados.id, empleados.sector, empleados.nombre, empleados.apellido, empleados.sueldo);
}

/** \brief Muestra varios empleados llamando a la función mostrarEmpleado
 * \param  empleados Es el array de empleados que va a mostrar
 * \param  empleados Es el tamaño del array de empleados
 * \return No retorna nada
 */


void mostrarEmpleados(eEmpleado empleados[], int tam)
{
    system("cls");
    printf("Legajo     Sector        Nombre          Apellido          Sueldo\n");
    printf("------     ------        ------          --------          ------\n");
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].ocupado == 1)
        {
            mostrarEmpleado(empleados[i]);  //Acá por cada iteración va a llamar a la función mostrarEmpleados y lo va a mostrar
        }
    }
    printf("\n\n");
}

/** \brief Ordena los empleados de forma ascendente o descendete.
 * \param empleados Es el array de empleados el cual va a ordenar.
 * \param empleados Es el tamaño del array de empleados.
 * \param empleados Es 0 si se ordena de forma descente o 1 ascendente.
 * \return No retorna nada.
 */


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

/** \brief Calcula el total de los sueldos, el promedio, cuantos superan el promedio y muestra los resultados.
 * \param empleados Es el array de empleados con el que va a trabajar.
 * \param empleados Es el tamaño del array.
 * \return No retorna nada
 */


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

/** \brief Modifica el nombre, apellido, sueldo o sector de un empleado buscandolo por ID.
 * \param empleados Es el array de empleados.
 * \param tam Es el tamaño del array de empleados.
 * \return No retorna nada.
 */


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
            // strlwr(auxNameOrLastname); A VECES ME TIRA WARNING COMO SI NO HUBIESE PUESTO LA BIBLITOECA STRING.H POR ESO LA COMENTE
            auxNameOrLastname[0] = toupper(auxNameOrLastname[0]);
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
            //strlwr(auxNameOrLastname); A VECES ME TIRA WARNING COMO SI NO HUBIESE PUESTO LA BIBLITOECA STRING.H POR ESO LA COMENTE
            auxNameOrLastname[0] = toupper(auxNameOrLastname[0]);
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


/** \brief Busca si hay algún empleado para mostrar.
 * \param  empleados Es el array de empleados.
 * \param  tam Es el tamaño del array de empleados
 * \return retorna -1 si no hay ningún empleado para mostrar y retorna el indice del empleado si lo encuentra.
 */


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
