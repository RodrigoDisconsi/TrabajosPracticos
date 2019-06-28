#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disconsi.h"

/** \brief Soicita un n�mero de tipo float al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El n�mero de tipo float ingresado por el usuario.
 */


float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

/** \brief Soicita un n�mero de tipo int al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El n�mero de tipo int ingresado por el usuario.
 */

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/** \brief Soicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El caracter ingresado por el usuario.
 */

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}

/** \brief Verifica si el valor recibido es n�merico
 * \param str Array con la cadena analizada
 * \return 1 si es n�merico y 0 si no lo es
 */


int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] != '.') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido es solo letras
 * \param str Array con la cadena analizada
 * \return 1 si es solo letras y 0 si no lo es
 */

int esSoloLetras (char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido es solo letras y numeros
 * \param str Array con la cadena analizada
 * \return 1 si es alfa-n�merico  y 0 si no lo es
 */

int esAlfaNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')&& (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido es numeros, + y -
 * \param str Array con la cadena analizada
 * \return 1 si es del tipo tel�fono y 0 si no lo es
 */

int esTelefono(char str[])
{
    int i = 0;
    int contadorGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        if (str[i] == '-')
        {
            contadorGuiones ++;
        }
    }
    if(contadorGuiones <= 1)  //Debe tener un guion
    {
        return 1;
    }
    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return No retorna nada.
 */


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

/** \brief Solicita un texto al usuario de solo letras y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si es solo letras y 0 si no lo es.
 */

int getStringLetras(char mensaje[], char input[], char msgError[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    else
        printf(msgError);
    return 0;
}

/** \brief Solicita un texto al usuario de solo n�meros y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si es solo n�meros y 0 si no lo es.
 */

int getStringNumeros(char mensaje[], char input[], char msgError[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    else
        printf(msgError);
    return 0;
}

/** \brief Solicita un texto al usuario de solo n�meros y letras, y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si es solo n�meros y letras, y 0 si no lo es.
 */


int getStringAlfaNumerico(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}



int validarInt(int desde, int hasta, char* numero, char* msgError)
{
    int isOk = 0;
    int number = atoi(numero);
    if(number >= desde && number <= hasta)
        isOk = 1;
    else
        printf(msgError);
    return isOk;
}

int confirma(char* mensaje)
{
    char confirma;
    int isOk = 0;
    if(mensaje != NULL )
    {
        confirma = tolower(getChar(mensaje));
        if(confirma == 's')
        {
            isOk = 1;
        }
    }
    return isOk;
}
