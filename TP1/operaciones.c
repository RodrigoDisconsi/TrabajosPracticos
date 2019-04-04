#include "operaciones.h"

/** \brief Recibe 2 enteros y retorna la suma de ambos
* \param Recibe el primer entero
* \param Recibe el segundo entero
* \return Retorna la suma de ambos enteros
*/

int funcionSumar(int sumando1, int sumando2)
{
    int suma;
    suma = sumando1 + sumando2;
    return suma;
}

/** \brief Recibe 2 enteros y retorna la resta de ambos
* \param Recibe el primer entero
* \param Recibe el segundo entero
* \return Retorna la resta de los dos enteros
*/

int funcionResta(int minuendo, int sustraendo)
{
    int diferencia;
    diferencia = minuendo - sustraendo;
    return diferencia;
}

/** \brief Recibe 2 enteros y retorna el resultado de su division
* \param Recibe el primer entero que es el dividendo
* \param Recibe el segundo entero que es el divisor
* \return Retorna el resultado de la division
*/

float funcionDivision(int dividendo, int divisor)
{
    float result;
    if ( divisor != 0) //Valido que el divisor no sea 0
    {
        result = (float) dividendo / divisor;
    }
    return result;
}

/** \brief Recibe 2 enteros y retorna su producto
* \param Recibe el primer entero que es el primer Factor
* \param Recibe el segundo entero que es el segundo Factor
* \return Retorna el producto de ambos factores
*/

int funcionMultiplcacion (int factor1, int factor2)
{
    int producto;
    producto = factor1 * factor2;
    return producto;
}

/** \brief Recibe 1 entero y retorna su factorial
* \param Recibe el entero con el que se va a operar
* \return Retorna el factorial del entero recibido
*/

double funcionFactorial(int n)
{
    double resultado = 1;
    if (n == 0)  //Cuando el entero recibido es 0 el resultado va a ser 1.
    {
        resultado = 1;
    }
    else if (n>0)
    {
        for (int i = 1; i <= n ; i++)
        {
            resultado *= i;
        }
    }
    else   //Cuando el entero es negativo informo con un "-1" que no pudo realizarce el factorial
    {
        resultado = -1;
    }

    return resultado;
}
