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

void iniciarEstados(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[])
{
    int i,j;
    for(i = 0; i<CANT; i++)
    {
        nClientes[i].estadoCliente = VACIO;
        nClientes[i].estadoAlquiler = VACIO;
        strcpy(sMaquinaria[i].operador,"Laura");
        sMaquinaria[i].alquilerIndv = VACIO;
        sMaquinaria[i].cantAmoledora = VACIO;
        sMaquinaria[i].cantMezcladora = VACIO;
        sMaquinaria[i].cantTaladro = VACIO;
        nClientes[i].id = VACIO;

    }
    for(j=0;j<5;j++)
    {
        Alquileres[j].idAlquiler = VACIO;
        Alquileres[j].statusAlquiler = VACIO;
        Alquileres[j].tiempoReal = VACIO;
        Alquileres[j].tiempoEstimado = VACIO;
    }
}

void funcionMenu(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[],int opcion)
{
    int personas;
    int nInferior = 1;
    int nSuperior = 10;
    int error;
    if(opcion > 0 && opcion < 7)
    {
        switch(opcion)
        {
        case 1:
            printf("Se pueden ingresar de a 1 persona\n");
            altaCliente(nClientes);
        break;

        case 2:
            if(nClientes[0].id != 0)
            {
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
            } else
            {
                printf("No existen usuarios aun\n");
            }
        break;

        case 3:
            if(nClientes[0].id != 0)
            {
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
            }else
            {
                printf("No existen usuarios aun\n");
            }
        break;

        case 4:
            if(nClientes[0].id != 0)
            {
                printf("Solo puede realizarse un alquiler a la vez\n");
                error = nuevoAlquiler(nClientes,sMaquinaria,Alquileres);
                if(error == 1)
                {
                    printf("Su operador es: %s\n",sMaquinaria[0].operador);
                    printf("El alquiler se ha hecho satisfactoriamente\n");
                }
                else
                {
                    printf("No se pudo realizar el alquiler\n");
                }
            } else
            {
                printf("No existen usuarios aun\n");
            }
        break;

        case 5:
            if(nClientes[0].id != 0 && Alquileres[0].idAlquiler != 0)
            {
                printf("Solo puede finarlizarse un alquiler a la vez\n");
                error = finAlquiler(nClientes,sMaquinaria,Alquileres);
                if(error == 1)
                {
                    printf("La finalizacion del alquiler se ha hecho satisfactoriamente\n");
                }
                else
                {
                    printf("No se pudo realizar el alquiler\n");
                }
            }else
            {
                printf("No existe usuario o no existe alquiler\n");
            }

        break;

        case 6:
            if(nClientes[0].id != 0 && Alquileres[0].idAlquiler != 0)
            {
                printf("Se informa:\n 1- Asociado con mas alquileres\n 2-Equipos mas alquilados\n 3-Promedio de tiempo real de alquiler de equipos\n");
                informesAlquileres(nClientes,sMaquinaria,Alquileres);
            }else
            {
                printf("No existe usuario o no existe alquiler\n");
            }
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

void altaCliente(cAlquiler nClientes[])
{
    int i;
    char auxNombre,rtaNombre = 'S';
    char auxApellido,rtaApellido = 'S';
    char auxDni,rtaDni = 'S';

    for(i=0;i<CANT;i++)
    {
        if(nClientes[i].estadoCliente == VACIO)
        {
            //Nombre
            do{
            printf("Ingrese el nombre\n");
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
            printf("Ingrese el apellido\n");
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
            break;
        }
        else if(nClientes[i].estadoCliente != VACIO){
           continue;
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


int nuevoAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[])
{
    int retorno=-1;
    int auxId, i,j;
    int auxAlquiler,error;

    printf("Ingrese el ID del cliente que alquila\n");
    scanf("%d",&auxId);
    error = validarnumero(auxId,1,CANT);
    if (error == 1)
    {
    for(i=0;i<CANT;i++)
    {
        for(j=0;j<5;j++)
        {
        if(nClientes[i].estadoCliente == ALTA && auxId == nClientes[i].id)
        {
            if(nClientes[i].estadoAlquiler == ALQUILADO && Alquileres[j].statusAlquiler == ALQUILADO)
            {
                printf("El cliente %s %s de id:%d ya tiene el alquiler n. %d activo.\n",nClientes[i].nombre,nClientes[i].apellido,nClientes[i].id,j+1);
                continue;
            }
            else
            {
                printf("El cliente que desea alquilar es: %s %s\n",nClientes[i].nombre,nClientes[i].apellido);
                printf("Sera su alquiler n. %d\n",j+1);
                printf("Que desea alquilar?\n 1-Amoledora\n 2-Mezcladora\n 3-Taladro\n");
                scanf("%d",&auxAlquiler);
                error = validarnumero(auxAlquiler,1,3);
                if(error == 1)
                {
                    if(auxAlquiler == AMOLEDORA){
                    nClientes[i].maquinaAlquilada = AMOLEDORA;
                    printf("Cuantos dias desea alquilar la Amoledora?\n");
                    scanf("%d",&Alquileres[j].tiempoEstimado);
                    sMaquinaria[i].cantAmoledora++;
                    }
                        else if(auxAlquiler == MEZCLADORA)
                        {
                        nClientes[i].maquinaAlquilada = MEZCLADORA;
                        printf("Cuantos dias desea alquilar la Mezcladora?\n");
                        scanf("%d",&Alquileres[j].tiempoEstimado);
                        sMaquinaria[i].cantMezcladora++;
                        }
                            else
                            {
                            nClientes[i].maquinaAlquilada = TALADRO;
                            printf("Cuantos dias desea alquilar el Taladro?\n");
                            scanf("%d",&Alquileres[j].tiempoEstimado);
                            sMaquinaria[i].cantTaladro++;
                            }
                    Alquileres[j].statusAlquiler = ALQUILADO;
                    nClientes[i].estadoAlquiler = ALQUILADO;
                    sMaquinaria[i].alquilerIndv = sMaquinaria[i].alquilerIndv + 1;
                    Alquileres[j].idAlquiler = j+1;
                    printf("Su numero de alquiler se pedira luego, recuerdelo: %d\n",Alquileres[j].idAlquiler);
                    retorno = 1;
                    break;
                }
            }
        } // Fin de if id=id
        }//fin del for j
    }//fin del for i
    }

    return retorno;
}

int finAlquiler(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[])
{
    int retorno;
    int auxId, i,j;
    int tiempoAlquiler,errorId,errorTiempo;
    int idAlquiler,errorAl;

    printf("Ingrese el ID del cliente que alquilo\n");
    scanf("%d",&auxId);

    printf("Ingrese el numero de alquiler\n");
    scanf("%d",&idAlquiler);

    printf("Ingrese cuanto tiempo realmente alquilo la maquina\n");
    scanf("%d",&tiempoAlquiler);

    errorId = validarnumero(auxId,1,CANT);
    errorAl = validarnumero(idAlquiler,1,5);
    errorTiempo = validarnumero(tiempoAlquiler,1,CANT);

    if (errorId == 1 && errorAl == 1 && errorTiempo == 1)
    {
        for(i=0;i<CANT;i++)
        {
            if(auxId == nClientes[i].id && nClientes[i].estadoAlquiler == ALQUILADO)
            {
                for(j=0;j<5;j++)
                {
                    if(Alquileres[i].idAlquiler == idAlquiler)
                    {
                        nClientes[i].estadoAlquiler = FINALIZADO;
                        Alquileres[j].statusAlquiler = FINALIZADO;
                    }
                }
                Alquileres[j].tiempoReal = tiempoAlquiler;
                retorno = 1;
                break;
            }
            else {
            retorno = -1;
            }
        }//Fin for
    }
    return retorno;
}

void informesAlquileres(cAlquiler nClientes[],sCompania sMaquinaria[],aActivos Alquileres[])
{
    int i,j;
    int auxMasAlq = 0;
    int contadorAlq = 0;
    int masAlq = 0;
    int cAmoledora = 0;
    int cTaladro = 0;
    int cMezcladora = 0;
    int pTiempoReal = 0;
    int cantTotal = 0;
    int informeTres = 0;
    printf("-------\n");
    printf("1- Los asociados con mas alquileres son: \n");
    for(i=0;i<CANT;i++)
    {
        for(j=0;j<5;j++)
        {
            if(nClientes[i].estadoCliente != VACIO && Alquileres[j].statusAlquiler != VACIO)
            {
                contadorAlq++;
                if(contadorAlq > auxMasAlq)
                {
                    auxMasAlq = contadorAlq;
                    masAlq = i;
                }
            }
        }//for j
    }
    for(i=0;i<CANT;i++)
    {
        if(sMaquinaria[i].alquilerIndv == auxMasAlq)
        {
            printf("%s %s ID: %d y alquilo %d veces\n",nClientes[masAlq].nombre,nClientes[masAlq].apellido,nClientes[masAlq].id,auxMasAlq);
        }
        else
        {
        continue;
        }
    }
//Finaliza primer informe
printf("-------\n");

    for(i=0;i<CANT;i++)
    {
        for(j=0;j<5;j++)
        {
            if(nClientes[i].estadoCliente != VACIO && Alquileres[j].statusAlquiler != VACIO)
            {
                if(sMaquinaria[i].cantAmoledora == AMOLEDORA)
                {
                cAmoledora =+ sMaquinaria[i].cantAmoledora;
                }
                    else if(sMaquinaria[i].cantTaladro == TALADRO)
                    {
                    cTaladro =+ sMaquinaria[i].cantTaladro;
                    }
                        else if(sMaquinaria[i].cantMezcladora == MEZCLADORA)
                        {
                        cMezcladora =+ sMaquinaria[i].cantMezcladora;
                        }
            }
        }
    }
    printf("2- La o las maquinas mas alquiladas son: \n");
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
        printf("Todas las maquinas tienen %d alquileres\n",cTaladro);
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
    printf("-------\n");

    for(i=0;i<CANT;i++)
    {
       for(j=0;j<5;j++)
        {
            if(nClientes[i].estadoCliente != VACIO && Alquileres[j].statusAlquiler != VACIO)
            {
                pTiempoReal =+ Alquileres[j].tiempoReal;
            }
            cantTotal++;
       }
    }

    informeTres = (pTiempoReal * 100)/cantTotal;
    printf("3- El tiempo promedio real de alquiler es: %d\n",informeTres);
}







