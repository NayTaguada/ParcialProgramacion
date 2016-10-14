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
    int contadorAlquiler;

}cAlquiler;

typedef struct
{
    char operador[50];
    int alquilerIndv;
    int cantAmoledora;
    int cantTaladro;
    int cantMezcladora;

}sCompania;

typedef struct
{
    int idAlquiler;
    int statusAlquiler;
    int tiempoEstimado;
    int tiempoReal;

}aActivos;

void funcionMenu(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[],int opcion);

void iniciarEstados(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[]);

char vLargoDeString(cAlquiler nClientes[],int i);

char validarDNI(cAlquiler nClientes[],int i);

char pasarAMayus(char letra);

int validarnumero(int personas,int nInferior,int nSuperior);

void altaCliente(cAlquiler nClientes[]);

int modificarCliente(cAlquiler nClientes[]);

int bajaCliente(cAlquiler nClientes[]);

int nuevoAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[]);

int finAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[]);

void informesAlquileres(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[]);

#endif // FUNCIONES_H_INCLUDED
