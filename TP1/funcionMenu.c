/** \brief  Sirve para mostrar un menu en el cual se van a ingresar 2 enteros y se van a mostrar en el menu
 * \param   Va a ser el entero que recibe y lo va a colocar cuando sea indicado en A=x.
 * \param   Va a ser el segundo entero que recibe y lo va a colocar cuando sea indicado en B=x.
 * \param   Va a indicar cuando muestra el primer entero en el menu o cuando muestra A=x.
 * \param   Va a indicar cuando muestra el segundo entero en el menu o cuando muestra B=x.
 * \return  Retorna un entero que va a indicar que opcion del menu eligio el usuario.
 *
 */
#include "funcionMenu.h"
#include <stdio.h>
#include <stdlib.h>

int funcionMenu(int numero1, int numero2, int flag1, int flag2)
{
      system("cls");
      int opcion;
          if (flag1 == 0)
          {
              printf("1- Ingresar 1er operando A=x\n");
          }
          else
          {
              printf("1- Ingresar 1er operando A=%d\n", numero1);
          }
          if (flag2 == 0)
          {
              printf("2- Ingresar 2do operando B=x\n");
          }
          else
          {
              printf("2- Ingresar 2do operando B=%d\n", numero2);
          }
              printf("3- Calcular todas las operaciones\n");
              printf("4- Informar los resultados\n");
              printf("5- Salir\n");
              printf("Ingrese una opcion:");
              scanf("%d", &opcion);
          return opcion;
}
