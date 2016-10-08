#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[50];
    char apellido[50];
    int estadoAlquiler;
    int estadoCliente;
    int maquinaAlquilada;

}cAlquiler;

typedef struct
{
    char operador[50];
    int tiempoEstimado;
    int tiempoReal;

}sCompania;

void funcionMenu(cAlquiler nClientes[],sCompania sMaquinaria[],int opcion);

void iniciarEstados(cAlquiler nClientes[],sCompania sMaquinaria[]);

char vLargoDeString(cAlquiler nClientes[],int i);

char validarDNI(cAlquiler nClientes[],int i);

char pasarAMayus(char letra);

int validarnumero(int personas,int nInferior,int nSuperior);

void altaCliente(cAlquiler nClientes[],int personas);

int modificarCliente(cAlquiler nClientes[]);

int bajaCliente(cAlquiler nClientes[]);

int nuevoAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[]);

int finAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[]);


#endif // FUNCIONES_H_INCLUDED
