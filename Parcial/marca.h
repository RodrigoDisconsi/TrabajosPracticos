#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct {
        int id;
        char descripcion[21];
}eMarca;

void mostrarMarca(eMarca* marcas, int tam);
int obtenerMarca(eMarca* marcas, int tam, int idMarca, char desc[]);


#endif // MARCA_H_INCLUDED
