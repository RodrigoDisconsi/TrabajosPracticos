#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "disconsi.h"
#include "auto.h"
#include "menu.h"

/** \brief Inicializa el estado en un array del tipo eAuto.
 * \param  autos Es el array de autos que va a inicializar.
 * \param  tam Es el tamaño del array.
 * \return No retorna nada.
 */


void inicializarAutos(eAuto* autos, int tam)
{
    if(autos != NULL)
    {
        for(int i = 0; i < tam ; i++)
        {
            (autos+i)->estado = 0;
        }
    }
}

/** \brief Busca en el array de autos el primer lugar libre y lo devuelve (campo estado = 0).
 * \param  autos Es el array de autos donde va a buscar el lugar libre.
 * \param  tam Es el tamaño del array.
 * \return Retorna el indice del primer autos libre y si no encuentra ninguno retorna -1.
 */

int buscarLibre(eAuto* autos, int tam)
{
    int indice = -1;
    if(autos != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            if((autos+i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

/** \brief Da de alta un auto en el primer lugar libre.
 * \param  autos Es el array de autos donde va a cagar el auto dado de alta.
 * \param  tam Es el tamaño del array.
 * \param  marcas Es el array de marcas para mostrarlas y que el usuario elija una.
 * \param  tamMarca Es el tamaño del array marcas.
 * \param  colores Es el array de colores para mostrarlos y que el usuario elija.
 * \param  tamColor Es el tamaño del array colores.
 * \param  id Es un pasaje por referencia del ID para que sea autoincremental y no tenga que ingresarlo el usuario.
 * \return Retorna 1 si se pudo completar el alta sin problemas o 0 si no se pudo completar el alta.
 */

int altaAuto(eAuto* autos, int tam, eMarca* marcas, int tamMarca, eColor* colores, int tamColor, eCliente* clientes, int tamClientes, int* id)
{
    int isOk = 0;
    int indice;
    int auxiliarColor;
    int auxiliarMarca;
    int auxiliarModelo;
    int auxiliarCliente;
    char auxMarca[11];
    char auxCliente[11];
    char auxColor[11];
    char sexo;
    char confirmaMarca;
    char confirmaColor;
    char confirmaCliente;
    char auxPatente[10];
    char auxModelo[10];
    indice = buscarLibre(autos, tam);
    if(autos != NULL && marcas != NULL && colores != NULL && id != NULL && clientes != NULL)
    {
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
            return isOk;
        }
        if(!getStringAlfaNumerico("Ingrese la patente: ", auxPatente))
        {
            printf("Ingrese solo numeros o letras!!\n\n");
            return isOk;
        }
        if(strlen(auxPatente) > 9)
        {
            printf("La patente es muy larga\n\n");
            return isOk;
        }
        strupr(auxPatente);
        if(buscarAuto(autos, tam, auxPatente) != -1)
        {
            printf("La patente ya se encuentra en el sistema\n\n");
            return isOk;
        }
        fflush(stdin);
        if(!getStringNumeros("Ingrese el modelo(anio de fabricacion): ", auxModelo, "Ingrese solo numeros"))
            return isOk;
        if(strlen(auxModelo) > 9)
        {
            printf("El modelo es muy grande\n\n");
            return isOk;
        }
        auxiliarModelo = atoi(auxModelo);
        mostrarCliente(clientes, tamClientes);
        auxiliarCliente = getInt("Ingrese el numero de cliente: ");
        if(!obtenerCliente(clientes, tamClientes, auxiliarCliente, auxCliente, &sexo))
        {
            printf("Cliente invalido!\n");
        }
        printf("El cliente que ingreso es: %s\n", auxCliente);
        confirmaCliente = tolower(getChar("Confirma? s/n: "));
        if(confirmaCliente != 's')
        {
            printf("Alta cancelada.\n\n");
            return isOk;
        }
        mostrarMarca(marcas, tamMarca);
        auxiliarMarca = getInt("Ingrese la marca: ");
        if(!obtenerMarca(marcas, tamMarca, auxiliarMarca, auxMarca))
        {
            printf("La marca ingresada es invalida\n\n");
            return isOk;
        }
        printf("La marca que ingreso es: %s\n", auxMarca);
        confirmaMarca = tolower(getChar("Confirma? s/n: "));
        if(confirmaMarca != 's')
        {
            printf("Alta cancelada.\n\n");
            return isOk;
        }
        mostrarColores(colores, tamColor);
        auxiliarColor = getInt("Ingrese el color: ");
        if(!obtenerColor(colores, tamColor, auxiliarColor, auxColor))
        {
            printf("El color es invalido\n\n");
            return isOk;
        }
        printf("El color que ingreso es %s\n", auxColor);
        confirmaColor = tolower(getChar("Confirma? s/n: "));
        if(confirmaColor != 's')
        {
            printf("Alta cancelada.\n\n");
            return isOk;
        }

        (autos+indice)->id = *id;
        (autos+indice)->idColor = auxiliarColor;
        (autos+indice)->idMarca = auxiliarMarca;
        (autos+indice)->modelo = auxiliarModelo;
        (autos+indice)->idCliente = auxiliarCliente;
        strcpy((autos+indice)->patente, auxPatente);
        (autos+indice)->estado = 1;
        *id = *id + 1;
        isOk = 1;
    }
    return isOk;
}

/** \brief Busca un auto por su patente y retorna el indice.
 * \param autos Es el array de autos donde va a buscar la patente
 * \param tam Es el tamaño del array de autos
 * \param patente Es la patente que va a buscar
 * \return retorna el indice donde se encuentra la patente o -1 si no la encontro.
 */


int buscarAuto(eAuto* autos, int tam, char* patente)
{
    int indice = -1;
    if(autos != NULL && patente != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if((autos+i)->estado == 1 && strcmp((autos+i)->patente, patente) == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

/** \brief Muestra 1 auto.
 * \param colores Es el array para buscar el color del auto.
 * \param tamColor Es el tamaño del array colores.
 * \param marcas Es el array para buscar la marca del auto.
 * \param tamMarca Es el tamaño del array marcas.
 * \param aAuto Es el auto que se va a mostrar.
 * \return void
 */


void mostrarAuto(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* aAuto)
{
    char nombreColor[21];
    char nombreMarca[21];
    char nombreCliente[21];
    char sexo;
    int consiguioCliente;
    int consiguioColor;
    int consiguioMarca;

    if(colores != NULL && marcas != NULL && clientes != NULL && aAuto != NULL)
    {
        consiguioColor =  obtenerColor(colores, tamColor, aAuto->idColor, nombreColor);

        if( !consiguioColor)
        {
            strcpy(nombreColor, "Sin definir");
        }

        consiguioMarca =  obtenerMarca(marcas, tamMarca, aAuto->idMarca, nombreMarca);

        if( !consiguioMarca)
        {
            strcpy(nombreMarca, "Sin definir");
        }

        consiguioCliente = obtenerCliente(clientes, tamCliente, aAuto->idCliente, nombreCliente, &sexo);
        if( !consiguioCliente)
        {
            strcpy(nombreCliente, "Sin definir");
        }

        printf("          %-2d    %-10s    %c         %-10s     %-10s     %-10s  %d\n", aAuto->id, nombreCliente, sexo, aAuto->patente, nombreMarca, nombreColor, aAuto->modelo);
    }
}

/** \brief Muestra un array de autos
 * \param autos Es el array de autos que se va a mostrar
 * \param tam Es el tamaño del array de autos
 * \param colores Es el array de eColor que le va a pasar a mostrarAuto
 * \param tamColor Es el tamaño del array colores
 * \param marcas Es el array de eMarca que le va a pasar a mostrarAuto
 * \param tamMarca Es el tamaño del array marcas
 * \return void
 */



void mostrarAutos(eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente, eAuto* autos, int tamAutos)
{
    int contador = 0;
    if(colores != NULL && marcas != NULL && clientes != NULL && autos != NULL)
    {
        system("cls");
        printf("          ID    Nombre       Sexo       Patente        Marca          Color      Modelo\n");
        printf("          --    ------       ----       -------        -----          -----      ------\n");
        for(int i=0; i < tamAutos; i++)
        {
            if((autos+i)->estado == 1)
            {
                mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+i);
                contador++;
            }
        }
        printf("\n\n");
        if( contador == 0)
        {
            printf("\nNo hay empleados que mostrar\n");
        }
    }
}


/** \brief Da de baja lógica un auto buscandolo por su patente
 * \param autos Es el array de autos donde se va a buscar la patente
 * \param tam Es el tamaño del array de autos
 * \param colores Es el array de eColor que le va a pasar a mostrarAuto
 * \param tamColor Es el tamaño del array colores
 * \param marcas Es el array de eMarca que le va a pasar a mostrarAuto
 * \param tamMarca Es el tamaño del array marcas
 * \return void
 */


int bajaAuto(eAuto* autos, int tam, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    char patente[10];
    char confirma;
    int esta;
    int isOk = 0;
    if(autos != NULL && colores != NULL && marcas != NULL && clientes != NULL)
    {
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
        esta = buscarAuto(autos, tam, patente);
        if( esta == -1)
        {
            printf("\nLa patente %s no esta registrado en el sistema\n", patente);

        }
        else
        {
            printf("          ID    Nombre       Sexo       Patente        Marca          Color      Modelo\n");
            printf("          --    ------       ----       -------        -----          -----      ------\n");
            mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, autos+esta);
            confirma = tolower(getChar("\nConfirma la eliminiacion? s/n: "));
            if(confirma == 's')
            {
                (autos+esta)->estado = 0;
                printf("Baja empleado exitosa!!\n");
                isOk = 1;
            }
            else
            {
                printf("\nLa eliminacion ha sido cancelada\n");

            }

        }
    }
    return isOk;
}

/** \brief Ordena un array de autos por marca y por patente
 * \param autos Es el array de autos que va a ordenar
 * \param tam Es el tamaño del array de autos
 * \return void
 */

void ordenarAutos(eAuto* autos, int tam)
{
    eAuto auxAuto;
    if(autos != NULL)
    {
        for (int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j<tam ; j++)
            {
                if((autos+i)->estado == 1 && (autos+i)->idMarca > (autos+j)->idMarca)
                {
                    auxAuto = *(autos+i);
                    *(autos+i) = *(autos+j);
                    *(autos+j) = auxAuto;
                }
                if((autos+i)->estado == 1 && (autos+i)->idMarca == (autos+j)->idMarca)
                {
                    if(strcmp((autos+i)->patente, (autos+j)->patente) > 0)
                    {
                        auxAuto = *(autos+i);
                        *(autos+i) = *(autos+j);
                        *(autos+j) = auxAuto;
                    }
                }
            }
        }
    }
}

/** \brief Modifica el color o modelo de un auto buscandolo por su patente.
 * \param autos Es el array de autos donde se va a buscar la patente.
 * \param tam Es el tamaño del array de autos.
 * \param colores Es el array de eColor que va a mostrar para modificar el color.
 * \param tamColor Es el tamaño del array colores.
 * \param marcas Es el array de eMarca que le va a pasar a mostrarAuto.
 * \param tamMarca Es el tamaño del array marcas.
 * \return void.
 */

int modificarAuto(eAuto* autos, int tam, eColor* colores, int tamColor, eMarca* marcas, int tamMarca, eCliente* clientes, int tamCliente)
{
    char patente[10];
    char auxColor[21];
    char auxModelo[21];
    char confirmaModelo;
    char confirmaColor;
    int auxiliarColor;
    int isOk = 0;
    int auxiliarModelo;
    int esta;

    if(autos != NULL && colores != NULL && marcas != NULL && clientes != NULL)
    {
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
        esta = buscarAuto(autos, tam, patente);
        if( esta == -1)
        {
            printf("\nLa patente %s no esta registrado en el sistema\n", patente);
        }
        else
        {
            system("cls");
            printf("          ID    Nombre       Sexo       Patente        Marca          Color      Modelo\n");
            printf("          --    ------       ----       -------        -----          -----      ------\n");
            mostrarAuto(colores, tamColor, marcas, tamMarca, clientes, tamCliente, (autos+esta));
            printf("\n\n");
            switch(menuModificar())
            {
            case 1:
                mostrarColores(colores, tamColor);
                auxiliarColor = getInt("Ingrese el color deseado: ");
                if(!obtenerColor(colores, tamColor, auxiliarColor, auxColor))
                {
                    printf("El color es invalido\n\n");
                    break;
                }
                printf("El color que ingreso es %s\n", auxColor);
                confirmaColor = tolower(getChar("Desea cambiar el color? s/n: "));
                if(confirmaColor != 's')
                {
                    printf("Modificacion cancelada.\n\n");
                    break;
                }
                (autos+esta)->idColor = auxiliarColor;
                isOk = 1;
                break;
            case 2:
                if(!getStringNumeros("Ingrese el nuevo modelo: ", auxModelo, "Ingrese solo numeros.\n\n"))
                    break;
                auxiliarModelo = atoi(auxModelo);
                printf("El modelo que ingreso es %d\n", auxiliarModelo);
                confirmaModelo = tolower(getChar("Desea cambiar el modelo? s/n: "));
                if(confirmaModelo == 's')
                {
                    (autos+esta)->modelo = auxiliarModelo;
                    printf("Modificacion exitosa!\n\n");
                    isOk = 1;
                    break;
                }
                else
                    printf("Modificacion cancelada.\n\n");
            case 3:
                printf("Modificacion cancelada.\n\n");
                break;
            default:
                printf("Opcion invalida");
                break;
            }
        }
    }
    return isOk;
}

/** \brief Busca en el array de autos si hay algún auto para mostrar (campo estado = 1)
 * \param autos Es el array de autos donde va a buscar algún auto
 * \param tam Es el tamaño del array de autos
 * \return -1 si no hay ningún auto para mostrar o el indice del array de autos.
 */

int hayAutoParaMostrar(eAuto* autos, int tam)
{
    int indice = -1;
    if(autos != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            if((autos+i)->estado == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


