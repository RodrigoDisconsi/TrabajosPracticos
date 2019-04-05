#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "operaciones.h"
#include "funcionMenu.h"

/** TRABAJO PRÁCTICO 1
 *  UTN REGIONAL AVELLANEDA
 *  ALUMNO: Franco Rodrigo Disconsi
 *  DIVISIÓN: 1-G
 *  Calculadora que permite ingresar 2 enteros y realizar operaciones con dichos enteros ademas de mostrarlos.
 */


int main()
{
    int flagA = 0;
    int flagB = 0;
    int flagOperaciones = 0;
    int num1;
    int num2;
    int suma, resta, multiplicacion;
    int flagDivision;     //Para saber que retorna la funcion y saber si pudo hacerse correctamente o no
    int flagFactorialA;   //Para saber que retorna la funcion y saber si pudo hacerse correctamente o no
    int flagFactorialB;   //Para saber que retorna la funcion y saber si pudo hacerse correctamente o no
    double factorialA, factorialB;
    float division;
    char seguir = 's';

    do{
        switch(funcionMenu(num1, num2, flagA, flagB))
            {
            case 1:
                printf("\nIngrese un numero: ");
                scanf("%d", &num1);
                printf("\n");
                flagA = 1;                  //El flag sirve para saber que ya se ingreso un entero en A
                break;
            case 2:
                printf("\nIngrese un numero: ");
                scanf("%d", &num2);
                printf("\n");
                flagB = 1;                 //El flag sirve para saber que ya se ingreso un entero en B
                break;
            case 3:
                if (flagA == 0 && flagB == 0)  //Me indica que todavía no ingresaron ningun operando.
                {
                    printf("\n ***Primero debe ingresar los operando A y B***\n\n");
                }
                else if (flagA == 1 && flagB == 0) //Me indica que no se ingreso el operando B
                {

                    printf("\n***Primero debe ingresar el operando B***\n\n");
                }
                else if (flagA == 0 && flagB == 1) //Me indica que no se ingreso el operando A
                {
                    printf("\n***Primero debe ingresar el operando A***\n\n");
                }
                else
                {
                    suma = funcionSumar(num1, num2);
                    resta = funcionResta(num1, num2);
                    flagDivision = funcionDivision(num1, num2, &division);
                    multiplicacion = funcionMultiplcacion(num1, num2);
                    flagFactorialA = funcionFactorial(num1, &factorialA);
                    flagFactorialB =  funcionFactorial(num2, &factorialB);
                    flagOperaciones = 1;     //Sirve para saber si ya se hicieron las operaciones para poder mostrarlas.
                    printf("\n***Las operaciones se hicieron correctamente***\n\n");
                }
                break;
            case 4:
                if (flagOperaciones == 0)  //Me indica que todavía no se realizaron las operaciones.
                {
                    printf("\n***Primero debe realizar las operaciones***\n\n");
                }
                else
                {
                    printf("\nEl resultado de las operaciones son:\n");
                    printf("A- El resultado de A+B es: %d\n", suma);
                    printf("B- El resultado de A-B es: %d\n", resta);
                        if (flagDivision == 0)
                        {
                            printf("C- No es posible dividir por 0\n");
                        }
                        else
                        {
                                printf("C- El resultado de A/B es: %.2f\n", division);
                        }
                    printf("D- El resultado de A*B es: %d\n", multiplicacion);
                        if (flagFactorialA == 0 && flagFactorialB == 0) //Como la función retorna un "-1" me indica que no se pudo realizar correctamente el factorial de dichos números
                        {
                            printf("E- No es posible hacer el factorial de un numero negativo\n\n");
                        }
                        else if (flagFactorialA != 0 && flagFactorialB == 0)
                        {
                            printf("E- El factorial de A es: %.0f y B no es posible por ser negativo\n\n", factorialA);
                        }
                        else if (flagFactorialA == 0 && flagFactorialB != 0)
                        {
                            printf("E- El factorial de A no es posible por ser negativo y el de B es: %.0f\n\n", factorialB);
                        }
                        else
                        {
                            printf("E- El factorial de A es: %.0f y B es %.0f\n\n", factorialA, factorialB);
                        }
                }
                break;
            case 5:
                seguir = 'n';
                break;
            default :
                printf("ERROR. Ingrese una opcion valida");
            }
            printf("Presione una tecla para continuar...");
            getch();      //Utilizo el getch para realizar una pausa en el programa.
        }while(seguir == 's');

}
