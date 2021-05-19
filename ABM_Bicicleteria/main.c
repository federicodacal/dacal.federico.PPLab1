#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"
#include "trabajo.h"
#include "utn_validaciones.h"
#include "datawarehouse.h"

#define BICICLETA_LEN 50000
#define TIPOS_LEN 4
#define COLORES_LEN 5
#define SERVICIOS_LEN 4
#define TRABAJOS_LEN 1000

int menu();

int main()
{
    int nextBicicleta=2000;
    //int nextIdTrabajo=30000;

    char exit='n';
    int option;

    Tipo tipos[]={
    {1000, "Rutera"},
    {1001, "Carrera"},
    {1002, "Mountain"},
    {1003, "BMX"},
    };

    Color colores[COLORES_LEN]={
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Azul"},
    {5004, "Rojo"}
    };

    Servicio servicios[SERVICIOS_LEN]={
    {20000, "Limpieza",250},
    {20001, "Parche",300},
    {20002, "Centrado",400},
    {20003, "Cadena",350}
    };

    Bicicleta list[BICICLETA_LEN];

    initBicicletas(list, BICICLETA_LEN);

    hcodeBicicletas(list, BICICLETA_LEN, 20, &nextBicicleta);

  //  Trabajo trabajos[TRABAJOS_LEN];

    //initTrabajos(trabajos, TRABAJOS_LEN);

    do{
        option=menu();
        if(option!=-1){
            switch(option){
                case 1:
                    system("cls");
                    printf("\n*****GESTIONAR ALTA*****\n");
                    printf("-------------------------------------\n");
                    if(!addBicicleta(list, BICICLETA_LEN, &nextBicicleta, tipos, TIPOS_LEN, colores, COLORES_LEN)){
                        printf("ALTA EXITOSA\n\n");
                    }
                    else{
                        printf("\nNo se realizo la alta\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("\n*****GESTIONAR MODIFICACION*****\n");
                    printf("-------------------------------------\n");
                    if(!updateBicicleta(list, BICICLETA_LEN, tipos, TIPOS_LEN, colores, COLORES_LEN)){
                        printf("Modificacion exitosa\n\n");
                    }
                    else{
                        printf("\nOcurrio un problema\n\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    printf("\n\t\t*****GESTIONAR BAJA*****\n");
                    printf("\t------------------------------------------------------------\n");
                    if(!removeBicicleta(list, BICICLETA_LEN)){
                        printf("BAJA EXITOSA\n\n");
                    }
                    else{
                        printf("\nNo se realizo baja\n\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if(!ordenarBicicletasPorTipo(list, BICICLETA_LEN)){
                        printBicicletas(list,BICICLETA_LEN);
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    mostrarTipos(tipos,TIPOS_LEN);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    mostrarColores(colores,COLORES_LEN);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    mostrarServicios(servicios, SERVICIOS_LEN);
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    printf("\n\t\t*****GESTIONAR ALTA DE TRABAJO*****\n");
                    printf("\t------------------------------------------------------------\n");
//                    addTrabajo(trabajos, TRABAJOS_LEN, &nextIdTrabajo, tipos, TIPOS_LEN, servicios, SERVICIOS_LEN);
                    system("pause");                   break;
                case 9:
                    system("cls");
                    system("pause");
                    break;
                case 10:
                    printf("Confirmar salida: s/n");
                    fflush(stdin);
                    exit=getchar();
                    break;
                }
        }
    }while(exit!='s');

    return 0;
}

int menu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****ADMINISTRACION DE BICICLETERIA*****\n");
    printf("------------------------------------------\n");
    printf("[1] ALTA BICICLETA\n");
    printf("[2] MODIFICAR BICICLETA\n");
    printf("[3] BAJA BICICLETA\n");
    printf("[4] LISTAR BICICLETAS\n");
    printf("[5] LISTAR TIPOS\n");
    printf("[6] LISTAR COLORES\n");
    printf("[7] LISTAR SERVICIOS\n");
    printf("[8] ALTA TRABAJO\n");
    printf("[9] LISTAR TRABAJOS\n");
    printf("------------------------------------------\n");
    printf("[10] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,10,10)==0){
        response=optionAux;
    }

    return response;
}
