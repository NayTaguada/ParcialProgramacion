#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AMOLEDORA 1
#define MEZCLADORA 2 // Equipos
#define TALADRO 3

#define ALQUILADO 1  //Estados alquileres
#define FINALIZADO -1

#define ALTA 1
#define BAJA -1
#define VACIO 0
#define CANT 10

void iniciarEstados(cAlquiler nClientes[],sCompania sMaquinaria[])
{
    int i;
    for(i = 0; i<CANT; i++){
        nClientes[i].estadoCliente = VACIO;
        nClientes[i].estadoAlquiler = VACIO;
        strcpy(sMaquinaria[i].operador,"Laura");
        sMaquinaria[i].alquilerIndv = VACIO;
        sMaquinaria[i].cantAmoledora = VACIO;
        sMaquinaria[i].cantMezcladora = VACIO;
        sMaquinaria[i].cantTaladro = VACIO;
        sMaquinaria[i].tiempoReal = VACIO;
        sMaquinaria[i].tiempoEstimado = VACIO;

    }
}

void funcionMenu(cAlquiler nClientes[],sCompania sMaquinaria[],int opcion)
{
    int personas;
    int nInferior = 1;
    int nSuperior = 10;
    int error;
    int informe=0;
    if(opcion > 0 && opcion < 7)
    {
        switch(opcion)
        {
        case 1:
            printf("Cuantas personas desea ingresar?\n");
            scanf("%d",&personas);
            error = validarnumero(personas,nInferior,nSuperior);
            if(error == 1)
            {
                altaCliente(nClientes,personas);
            }
            else
            {
                printf("No es posible esa cantidad de personas, maximo 10\n");
            }

        break;

        case 2:
            printf("Solo puede modificarse una persona a la vez\n");
            error = modificarCliente(nClientes);
            if (error == 1)
            {
                printf("El cliente ha sido modificado satisfactoriamente\n");
            }
            else
            {
                printf("No se pudo modificar el usuario\n");
            }
        break;

        case 3:
            printf("Solo puede darse de baja a una persona a la vez\n");
            error = bajaCliente(nClientes);
            if (error == 1)
            {
                printf("El cliente ha sido dado de baja satisfactoriamente\n");
            }
            else
            {
                printf("No se pudo dar de baja el usuario\n");
            }

        break;

        case 4:
            printf("Solo puede realizarse un alquiler a la vez\n");
            error = nuevoAlquiler(nClientes,sMaquinaria);
            if(error == 1)
            {
                printf("Su operador es: %s\n",sMaquinaria[0].operador);
                printf("El alquiler se ha hecho satisfactoriamente\n");
            }
            else
            {
                printf("No se pudo realizar el alquiler\n");
            }

        break;

        case 5:
            printf("Solo puede finarlizarse un alquiler a la vez\n");
            error = finAlquiler(nClientes,sMaquinaria);
            if(error == 1)
            {
                printf("La finalizacion del alquiler se ha hecho satisfactoriamente\n");
            }
            else
            {
                printf("No se pudo realizar el alquiler\n");
            }

        break;

        case 6:
            printf("Se informa:\n 1- Asociado con mas alquileres\n 2-Equipos mas alquilados\n 3-Promedio de tiempo real de alquiler de equipos\n");
            informesAlquileres(nClientes,sMaquinaria);
        break;
        }
    }
}

char vLargoDeString(cAlquiler nClientes[],int i){

    int aux;
    char retorno;
    nClientes[i].nombre;

    aux = strlen(nClientes[i].nombre);

    if (aux > 50){
        retorno = 'n';
    }
    return retorno;
}

char validarDNI(cAlquiler nClientes[],int i){
    char retorno;
    if(nClientes[i].dni<1000000 || nClientes[i].dni>99999999){
         retorno = 'n';
         return retorno;
    }
}

char pasarAMayus(char letra){
    char retorno;
    retorno = toupper(letra);
    return retorno;
}

int validarnumero(int personas,int nInferior,int nSuperior)
{
    int retorno = 1;
    if(personas<nInferior || personas>nSuperior)
    {
        retorno = -1;
    }
    return retorno;
}

void altaCliente(cAlquiler nClientes[],int personas)
{
    int i;
    char auxNombre,rtaNombre = 'S';
    char auxApellido,rtaApellido = 'S';
    char auxDni,rtaDni = 'S';

    for(i=0;i<personas;i++)
    {
        if(nClientes[i].estadoCliente == VACIO)
        {
            //Nombre
            do{
            printf("Ingrese el nombre N %d:\n",i+1);
            fflush(stdin);
            gets(nClientes[i].nombre);
            auxNombre = vLargoDeString(nClientes,i);
                if (auxNombre == 'n'){
                    printf("Es un nombre muy largo, desea ingresar nuevamente? S/N \n");
                    scanf("%c",&rtaNombre);
                    rtaNombre = pasarAMayus(rtaNombre);
                }else{
                    break;
                }
                    if(rtaNombre == 'N'){
                        break;
                    }

            }while(rtaNombre == 'S');

            //Apellido
            do{
            printf("Ingrese el apellido N %d:\n",i+1);
            fflush(stdin);
            gets(nClientes[i].apellido);
            auxApellido = vLargoDeString(nClientes,i);
                if (auxApellido == 'n'){
                    printf("Es un apellido muy largo, desea ingresar nuevamente? S/N \n");
                    scanf("%c",&rtaApellido);
                    rtaApellido = pasarAMayus(rtaApellido);
                }else{
                    break;
                }
                    if(rtaApellido == 'N'){
                        break;
                    }

            }while(rtaApellido == 'S');

            // DNI
            while(rtaDni == 'S'){
                printf("Ingrese el dni de %s %s\n",nClientes[i].nombre,nClientes[i].apellido);
                scanf("%d",&nClientes[i].dni);
                auxDni = validarDNI(nClientes,i);
                if(auxDni == 'n'){
                    printf("Ese no es un dni valido. Desea ingresarlo nuevamente? S/N \n");
                    fflush(stdin);
                    scanf("%c",&rtaDni);
                    rtaDni = pasarAMayus(rtaDni);
                    if(rtaDni == 'N'){
                        break;
                    }
                }else{
                    break;
                }

            }

            nClientes[i].id = i+1;
            nClientes[i].estadoCliente = ALTA;
            printf("El id de %s %s es: %d\n",nClientes[i].nombre,nClientes[i].apellido,nClientes[i].id);
        }
    }
}

int modificarCliente(cAlquiler nClientes[])
{
    int i, idAux = 0;
    int error;
    int retorno = 1;

    printf("Ingrese el ID de la persona a modificar\n");
    scanf("%d",&idAux);
    error = validarnumero(idAux,1,CANT);
    if (error == 1)
    {
        for(i=0;i<CANT;i++)
        {
            if(nClientes[i].estadoCliente == ALTA && idAux == nClientes[i].id)
            {
                printf("El usuario que quiere modificar es: %s %s\n",nClientes[i].nombre,nClientes[i].apellido);
                printf("Ingrese el nuevo nombre\n");
                fflush(stdin);
                gets(nClientes[i].nombre);
                printf("Ingrese el nuevo apellido\n");
                fflush(stdin);
                gets(nClientes[i].apellido);
                break;
            }
            retorno = -1;
        }
    }
    else
    {
    printf("ID invalido\n");
    }

    return retorno;
}

int bajaCliente(cAlquiler nClientes[])
{
    int i, idAux = 0;
    int error;
    int retorno = 1;

    printf("Ingrese el ID de la persona a dar de baja\n");
    scanf("%d",&idAux);
    error = validarnumero(idAux,1,CANT);
    if (error == 1)
    {
        for(i=0;i<10;i++)
        {
            if(nClientes[i].estadoCliente = ALTA && idAux == nClientes[i].id)
            {
                printf("El usuario que se dio de baja es: %s %s\n",nClientes[i].nombre,nClientes[i].apellido);
                nClientes[i].estadoCliente = BAJA;
                break;
            }
            retorno = -1;
        }
    }
    else
    {
    printf("ID invalido\n");
    }

    return retorno;
}


int nuevoAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[])
{
    int retorno;
    int auxId, i;
    int auxAlquiler,error;


    printf("Ingrese el ID del cliente que alquila\n");
    scanf("%d",&auxId);
    error = validarnumero(auxId,1,CANT);
    if (error == 1)
    {
    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente == ALTA && auxId == nClientes[i].id)
        {
            if(nClientes[i].estadoAlquiler == ALQUILADO)
            {
                printf("El cliente %s %s de id:%d ya tiene un alquiler activo.\n",nClientes[i].nombre,nClientes[i].apellido,nClientes[i].id);
                retorno = -1;
                break;
            }
            else
            {
                printf("El cliente que desea alquilar es: %s %s\n",nClientes[i].nombre,nClientes[i].apellido);
                printf("Que desea alquilar?\n 1-Amoledora\n 2-Mezcladora\n 3-Taladro\n");
                scanf("%d",&auxAlquiler);
                error = validarnumero(auxAlquiler,1,3);
                if(error == 1)
                {
                    if (auxAlquiler == AMOLEDORA){
                    nClientes[i].estadoAlquiler = ALQUILADO;
                    nClientes[i].maquinaAlquilada = AMOLEDORA;
                    printf("Cuantos dias desea alquilar la Amoledora?\n");
                    scanf("%d",&sMaquinaria[i].tiempoEstimado);
                    sMaquinaria[i].cantAmoledora++;
                    }
                        else if(auxAlquiler == MEZCLADORA)
                        {
                        nClientes[i].estadoAlquiler = ALQUILADO;
                        nClientes[i].maquinaAlquilada = MEZCLADORA;
                        printf("Cuantos dias desea alquilar la Mezcladora?\n");
                        scanf("%d",&sMaquinaria[i].tiempoEstimado);
                        sMaquinaria[i].cantMezcladora++;
                        }
                            else
                            {
                            nClientes[i].estadoAlquiler = ALQUILADO;
                            nClientes[i].maquinaAlquilada = TALADRO;
                            printf("Cuantos dias desea alquilar el Taladro?\n");
                            scanf("%d",&sMaquinaria[i].tiempoEstimado);
                            sMaquinaria[i].cantTaladro++;
                            }
                    retorno = 1;
                    sMaquinaria[i].alquilerIndv = sMaquinaria[i].alquilerIndv + 1;
                    break;
                }
            }
        } // Fin de if id=id
        retorno = -1;
    }
    }

    return retorno;
}

int finAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[])
{
    int retorno;
    int auxId, i;
    int auxAlquiler,error;

    printf("Ingrese el ID del cliente que alquilo\n");
    scanf("%d",&auxId);

    printf("Ingrese cuanto tiempo realmente alquilo la maquina\n");
    scanf("%d",&auxAlquiler);

    error = validarnumero(auxId,1,CANT);
    if (error == 1)
    {
        for(i=0;i<CANT;i++)
        {
            if(nClientes[i].estadoCliente == ALTA && auxId == nClientes[i].id && nClientes[i].estadoAlquiler == ALQUILADO)
            {
                nClientes[i].estadoAlquiler = FINALIZADO;
                sMaquinaria[i].tiempoReal = auxAlquiler;
                retorno = 1;
                break;
            }
            else {
            retorno = -1;
            }
        }
    }
    return retorno;
}

void informesAlquileres(cAlquiler nClientes[],sCompania sMaquinaria[])
{
    int i;
    int auxMasAlq = 0;
    int pMasAlquileres = 0;
    int cAmoledora = 0;
    int cTaladro = 0;
    int cMezcladora = 0;
    int pTiempoReal = 0;
    int cantTotal = 0;
    int informeTres = 0;
    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente != VACIO)
        {
            if(sMaquinaria[i].alquilerIndv > auxMasAlq)
            {
            auxMasAlq = sMaquinaria[i].alquilerIndv;
            pMasAlquileres = i;
            }
        }
    }
    printf("Los asociados con mas alquileres son: ");
    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente != VACIO)
        {
            if(sMaquinaria[i].alquilerIndv == auxMasAlq)
            {
                printf("%s %s ID: %d y alquilo %d veces\n",nClientes[pMasAlquileres].nombre,nClientes[pMasAlquileres].apellido,nClientes[pMasAlquileres].id,auxMasAlq);
            }
        }
    }
//Finaliza primer informe

    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente != VACIO)
        {
            cAmoledora = cAmoledora + sMaquinaria[i].cantAmoledora;
            cTaladro = cTaladro + sMaquinaria[i].cantTaladro;
            cMezcladora = cMezcladora + sMaquinaria[i].cantMezcladora;
            //cantTotal = cantTotal + sMaquinaria[i].cantAmoledora + sMaquinaria[i].cantTaladro + sMaquinaria[i].cantMezcladora;
        }
    }
    printf("La o las maquinas mas alquiladas son: ");
    if(cAmoledora > cTaladro && cAmoledora > cMezcladora)
    {
        printf("La Amoledora con: %d alquileres\n",cAmoledora);
    }
    else if(cTaladro > cAmoledora && cTaladro > cMezcladora)
    {
        printf("El Taladro con: %d alquileres\n",cTaladro);
    }
    else if(cMezcladora > cAmoledora && cMezcladora > cTaladro)
    {
        printf("La Mezcladora con: %d alquileres\n",cMezcladora);
    }
    else if(cTaladro == cAmoledora && cTaladro == cMezcladora)
    {
        printf("Todas con %d alquileres\n",cTaladro);
    }
    else if(cTaladro == cAmoledora && cTaladro > cMezcladora)
    {
        printf("El Taladro y La Amoledora con %d alquileres\n",cTaladro);
    }
    else if(cTaladro > cAmoledora && cTaladro == cMezcladora)
    {
        printf("El Taladro y La Mezcladora con %d alquileres\n",cTaladro);
    }
    else if(cAmoledora == cMezcladora && cAmoledora > cTaladro)
    {
        printf("La Amoledora y La Mezcladora con %d alquileres\n",cAmoledora);
    }

    //Fin de segundo informe

    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente != VACIO && nClientes[i].estadoAlquiler == FINALIZADO)
        {
            pTiempoReal = pTiempoReal + sMaquinaria[i].tiempoReal;
            informeTres = informeTres + sMaquinaria[i].alquilerIndv;
        }
        cantTotal = sMaquinaria[i].alquilerIndv + cantTotal;
    }

    informeTres = ((pTiempoReal * informeTres) * 100)/cantTotal;
    printf("El tiempo promedio real de alquiler es: %d\n",informeTres);
}







