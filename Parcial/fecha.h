#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
typedef struct{
        int dia;
        int mes;
        int anio;
}eFecha;

int validacionFecha(eFecha fecha);
int compararFechas (eFecha fecha1, eFecha fecha2);



#endif // FECHA_H_INCLUDED
