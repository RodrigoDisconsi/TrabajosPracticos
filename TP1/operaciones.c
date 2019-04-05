#include "operaciones.h"

/** \brief Recibe 2 enteros y retorna la suma de ambos
* \param Recibe el primer entero
* \param Recibe el segundo entero
* \return Retorna la suma de los dos enteros
*/

int funcionSumar(int sumando1, int sumando2)
{
    int resultadoSuma;
    resultadoSuma = sumando1 + sumando2;
    return resultadoSuma;
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
* \param Recibe el primer entero que es el dividendo por valor
* \param Recibe el segundo entero que es el divisor por valor
* \param Recibe por referencia la variable donde se va a guardar la division
* \return Retorna 1 si pudo hacerse correctamente la funcion y 0 si no se pudo
*/

int funcionDivision(int dividendo, int divisor, float* resultadoDivision)
{
    int funciono;
    if ( divisor != 0) //Valido que el divisor no sea 0
    {
        *resultadoDivision = (float) dividendo / divisor;
        funciono = 1;
    }
    else{
        funciono = 0;
    }
    return funciono;
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
* \param Recibe por referencia la variable donde se va a guardar el resultado
* \return Retorna 1 si pudo hacerse correctamente la funcion y 0 si no se pudo
*/

double funcionFactorial(int n, double* factorial)
{
    *factorial = 1;
    int resultado;
    if (n == 0)  //Cuando el entero recibido es 0 el resultado va a ser 1.
    {
        *factorial = 1;
        resultado = 1;
    }
    else if (n>0)
    {
        for (int i = 1; i <= n ; i++)
        {
            *factorial *= i;
            resultado = 1;
        }
    }
    else   //Cuando el entero es negativo informo con un "-1" que no pudo realizarce el factorial
    {
        resultado = 0;
    }

    return resultado;
}
