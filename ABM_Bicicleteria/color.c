#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "color.h"

int cargarDescripcionColor(int id, Color colores[], int len, char descrip[])
{
    int response=0;

    if(id>=5000 && id<=5004 && colores!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(colores[i].id == id){
                strcpy(descrip,colores[i].nombreColor);
                response=1;
                break;
            }
        }
    }
    return response;
}

int mostrarColores(Color colores[], int len)
{
    int response=-1;
    if(colores!=NULL && len>0){
        printf("    *****LISTA DE COLORES*****\n");
        printf("        ID  Descripcion\n");
        for(int i=0;i<len;i++){
            mostrarColor(colores[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

void mostrarColor(Color unColor)
{
    printf("        %d  %10s\n", unColor.id, unColor.nombreColor);
}
