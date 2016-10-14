#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"

int main()
{
    int opcion;
    char salir = 0;
    cAlquiler nClientes[10];
    sCompania sMaquinaria[10];
    aActivos Alquileres[5];

    iniciarEstados(nClientes,sMaquinaria,Alquileres);

    do{

    printf("Bienvenido, que desea hacer?\n");
    printf("1- Dar de alta a un cliente\n");
    printf("2- Modificar a un cliente\n");
    printf("3- Dar de baja a un cliente\n");
    printf("4- Ingresar nuevo alquiler\n");
    printf("5- Finalizar un alquiler existente\n");
    printf("6- Informes\n");
    printf("7- Salir\n");
    scanf("%d",&opcion);

    if(opcion == 7){
        salir = -1;
    }

    funcionMenu(nClientes,sMaquinaria,Alquileres,opcion);

    system("pause");
    system("cls");

    }while(salir == 0);


    return 0;
}
