#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "servicio.h"

int cargarDescripcionServicio(int id, Servicio servicios[], int len, char descrip[])
{
    int response=0;

    if(id>=20000 && id<=20003 && servicios!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(servicios[i].id==id){
                strcpy(descrip,servicios[i].descripcion);
                response=1;
                break;
            }
        }
    }
    return response;
}

int mostrarServicios(Servicio servicios[], int len)
{
    int response=-1;
    if(servicios!=NULL && len>0){
        printf("    *****LISTA DE TIPOS*****\n");
        printf("        ID  Descripcion Costo\n");
        for(int i=0;i<len;i++){
            mostrarServicio(servicios[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

void mostrarServicio(Servicio unServicio)
{
    printf("        %d  %10s $%.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}
