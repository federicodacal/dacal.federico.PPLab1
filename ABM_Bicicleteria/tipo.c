#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"

int cargarDescripcionTipo(int id, Tipo tipos[], int len, char descrip[])
{
    int response=0;

    if(id>=1000 && id<=1003 && tipos!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(tipos[i].id == id){
                strcpy(descrip,tipos[i].descripcion);
                response=1;
                break;
            }
        }
    }
    return response;
}

int mostrarTipos(Tipo tipos[], int len)
{
    int response=-1;
    if(tipos!=NULL && len>0){
        printf("    *****LISTA DE TIPOS*****\n");
        printf("        ID  Descripcion\n");
        for(int i=0;i<len;i++){
            mostrarTipo(tipos[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

void mostrarTipo(Tipo unTipo)
{
    printf("        %d  %10s\n", unTipo.id, unTipo.descripcion);
}
