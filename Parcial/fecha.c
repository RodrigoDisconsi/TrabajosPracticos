#include "fecha.h"

/** \brief Valida una fecha.
 * \param fecha Es la fecha que recibe del tipo eFecha
 * \return 1 si es valida 0 si no lo es
 */

int validacionFecha(eFecha fecha)
{
    int todoOk = 0;
    if((fecha.dia >0 && fecha.dia <= 31) && (fecha.mes > 0 && fecha.mes <= 12) && (fecha.anio > 0 && fecha.anio <= 2019))
    {
        todoOk = 1;
        if((fecha.mes == 2) && (fecha.dia > 28))
            todoOk = 0;
        if((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && (fecha.dia > 30 ))
            todoOk = 0;
    }
    return todoOk;
}

/** \brief Compara 2 fechas
 * \param fecha Es una de las fechas a comparar del tipo eFecha
 * \param fecha2 Es la otra fecha a comparar del tipo eFecha
 * \return 0 si son distintas y 1 si son iguales
 */


int compararFechas (eFecha fecha1, eFecha fecha2)
{
    int todoOK = 0;
    if(fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes && fecha1.anio == fecha2.anio)
        todoOK = 1;
    return todoOK;
}
