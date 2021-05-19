#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "utn_validaciones.h"
#include "tipo.h"

int initBicicletas(Bicicleta list[], int len)
{
    int response=1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            list[i].isEmpty=1;
        }
        response=0;
    }
    return response;
}

int addBicicleta(Bicicleta list[], int len, int* pCodigo, Tipo tipos[], int lenT, Color colores[], int lenC)
{
    int response=-1;

    Bicicleta newBicicleta;
    int index;

    if(list!=NULL && len>0 && pCodigo!=NULL && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0){
        printf("\nCODIGO: %d\n\n", *pCodigo);
        index=findEmptyIndex(list,len);
        if(index==-1){
            printf("No hay lugar disponible en el sistema");
            response=1;
        }
        else{
            mostrarTipos(tipos, lenT);
            mostrarColores(colores, lenC);

            if(!utn_getDescripcion(newBicicleta.marca,20,"\nIngrese marca: ","Error dato no valido\n",5) &&
               !utn_getNumero(&newBicicleta.idTipo, "\nIngrese ID de Tipo: ","Error dato no valido\n", 1000,1003,5) &&
               !utn_getNumero(&newBicicleta.idColor, "\nIngrese ID de Color: ","Error dato no valido\n", 5000,5004,5) &&
               !utn_getNumeroFlotante(&newBicicleta.rodado, "\nIngrese rodado (20, 26, 27.5, 29): ","Error dato no valido\n", 20,29,5))
               {
                    newBicicleta.id=*pCodigo;
                    (*pCodigo)++;
                    newBicicleta.isEmpty=0;
                    list[index]=newBicicleta;
                    response=0;
               }
        }
    }

    return response;
}

int findEmptyIndex(Bicicleta list[], int len)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}

void printBicicleta(Bicicleta bici)
{
    printf("%d \t%10s \t%d \t%d \t%.2f \n",
               bici.id,
               bici.marca,
               bici.idTipo,
               bici.idColor,
               bici.rodado);
}

int printBicicletas(Bicicleta list[], int len)
{
    int response=-1;
    int flag=1;
    if(list!=NULL && len>0){
        printf("\n\t\t*****LISTADO DE CLIENTES******\n");
        printf("-------------------------------------------------------------------------\n");
        printf("ID \t\tMarca \tTipo \tColor \tRodado\n");
        for(int i=0;i<len;i++){
            if(!list[i].isEmpty){
                printBicicleta(list[i]);
                flag=0;
            }
        }
        if(flag){
            printf("\n\tNo hay empleados que mostrar\n");
        }
    response=0;
    printf("\n\n");
    }
    return response;
}

int removeBicicleta(Bicicleta list[], int len)
{
    int response=-1;
    int codigo;
    int index;
    int confirm;

    if(list!=NULL && len>0){
        printBicicletas(list,len);
        if(!utn_getNumero(&codigo,"\nIngrese ID de Bicicleta: \n","Dato no valido",2000,50000,5)){
            index=findBicicletaById(list,len,codigo);

            if(index==-1){
                printf("No hay cliente registrado con el codigo %d",codigo);
            }
            else{
                printf("\n");
                printBicicleta(list[index]);
                if(!utn_getNumero(&confirm,"\n[1] Confirmar baja\n[2] Cancelar\n","\nDato no valido",1,2,10) && confirm){
                    list[index].isEmpty=1;
                    response=0;
                }
                else{
                    printf("\nBaja Cancelada\n");
                    response=1;
                }
            }
        }
    }
    return response;
}

int findBicicletaById(Bicicleta list[], int len, int id)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].id==id && list[i].isEmpty==0){
                index=i;
            }
        }
    }
    return index;
}

int updateBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC)
{
    int response=-1;
    int codigo;
    int index;

    if(list!=NULL && len>0){
        printBicicletas(list,len);
        if(!utn_getNumero(&codigo,"\nIngrese codigo del cliente: \n","Dato no valido",2000,50000,5)){
            index=findBicicletaById(list,len,codigo);
            if(index==-1){
                printf("\nNo hay cliente registrado con el codigo %d\n",codigo);
            }
            else{
                if(!modifyBicicleta(list,len,index, tipos, lenT, colores, lenC)){
                    printf("\nDatos Actualizados:\n");
                    printBicicleta(list[index]);
                    printf("---------------------------------------------------------------\n\n");
                    response=0;
                }
            }
        }
    }
    return response;
}

int modifyBicicleta(Bicicleta list[], int len, int index, Tipo tipos[], int lenT, Color colores[], int lenC)
{
    int response=-1;
    Bicicleta auxBicicleta;
    int option;

    if(list!=NULL && len>0){
        do{
            system("cls");
            printf("\n");
            printBicicleta(list[index]);
            printf("\nSeleccione el campo que desea modificar o 5 para Terminar:\n");
            if(!utn_getNumero(&option,"\n[1] Nombre - [2] Apellido - [3] Sexo - [4] Telefono - [5] Domicilio - [5] Terminar Modificacion\n","\nDato no valido",1,5,10)){
                switch(option){
                    case 1:
                        if(!utn_getDescripcion(auxBicicleta.marca,20,"\nIngrese Marca: ","\nError dato no valido",5)){
                            strcpy(list[index].marca,auxBicicleta.marca);
                            printf("Informacion Actualizada. Nuevo marca: %s\n\n",auxBicicleta.marca);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(!utn_getNumero(&auxBicicleta.idTipo,"\nIngrese ID Tipo: ","\nError dato no valido",1000,1003,5)){
                            list[index].idTipo=auxBicicleta.idTipo;
                            printf("Informacion Actualizada. Nuevo ID Tipo: %d\n\n",auxBicicleta.idTipo);
                            system("pause");
                        }
                        break;
                    case 3:
                        if(!utn_getNumero(&auxBicicleta.idColor,"\nIngrese ID de Color: ","\nError dato no valido", 5000,5004,5)){
                            list[index].idColor=auxBicicleta.idColor;
                            printf("Informacion Actualizada. Nuevo ID Color: %d\n\n",auxBicicleta.idColor);
                            system("pause");
                        }
                        break;
                    case 4:
                        if(!utn_getNumeroFlotante(&auxBicicleta.rodado,"\nIngrese rodado (20, 26, 27.5, 29): ","\nError dato no valido",20,29,5)){
                            list[index].rodado=auxBicicleta.rodado;
                            printf("Informacion Actualizada. Nuevo rodado: %.2f\n\n",auxBicicleta.rodado);
                            system("pause");
                        }
                        break;
                    }
                }
        }while(option!=5);
        response=0;
    }
    return response;
}

int ordenarBicicletasPorTipo(Bicicleta list[], int len)
{
    int response=-1;
    Bicicleta auxBicicleta;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(list[i].idTipo>list[j].idTipo || (list[i].idTipo==list[j].idTipo && list[i].rodado>list[j].rodado)){
                    auxBicicleta=list[i];
                    list[i]=list[j];
                    list[j]=auxBicicleta;
                }
            }
        }
        response=0;
    }
    return response;
}
