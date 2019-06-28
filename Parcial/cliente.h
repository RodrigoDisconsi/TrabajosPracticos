#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
        int id;
        char nombre[20];
        char sexo;
}eCliente;

void mostrarCliente(eCliente* clientes, int tam);

int obtenerCliente(eCliente* clientes, int tam, int idCliente, char* desc, char* sex);


#endif // CLIENTE_H_INCLUDED
