//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "trabajo.h"
//#include "bicicleta.h"
//#include "tipo.h"
//#include "servicio.h"
//
//int initTrabajos(Trabajo trabajos[], int len)
//{
//    int response=1;
//    if(trabajos!=NULL && len>0){
//        for(int i=0;i<len;i++){
//            trabajos[i].isEmpty=1;
//        }
//        response=0;
//    }
//    return response;
//}
//
//int addTrabajo(Trabajo trabajos[], int len, int* pCodigo, Tipo tipos[], int lenT, Servicio servicios[], int lenS)
//{
//    int response=-1;
//
//    Trabajo newTrabajo;
//    int index;
//
//    if(trabajos!=NULL && len>0 && pCodigo!=NULL){
//        printf("\nCODIGO: %d\n\n", *pCodigo);
//        index=findEmptyIndex(trabajos,len);
//        if(index==-1){
//            printf("No hay lugar disponible en el sistema");
//            response=1;
//        }
//        else{
//            printBicicletas(tipos, lenT);
//            mostrarServicios(servicios, lenS);
//
//            if(!utn_getNumero(&newTrabajo.idBicicleta, "\nIngrese ID de Bici: ","Error dato no valido\n", 2000,50000,5) &&
//               !utn_getNumero(&newTrabajo.idServicio, "\nIngrese ID de Servicio: ","Error dato no valido\n", 20000,20003,5))
//               {
//                    newTrabajo.id=*pCodigo;
//                    (*pCodigo)++;
//                    newTrabajo.isEmpty=0;
//                    trabajos[index]=newTrabajo;
//                    response=0;
//               }
//        }
//    }
//
//    return response;
//}
//
////int findEmptyIndex(Trabajo trabajos[], int len)
////{
////    int index=-1;
////
////    if(trabajos!=NULL && len>0){
////        for(int i=0;i<len;i++){
////            if(trabajos[i].isEmpty){
////                index=i;
////                break;
////            }
////        }
////    }
////    return index;
////}
//
//void printTrabajo(Trabajo unTrabajo)
//{
//    printf("%d \t%d \t%d \t%2d/2d/d \n",
//               unTrabajo.id,
//               unTrabajo.idBicicleta,
//               unTrabajo.idServicio,
//               unTrabajo.fechaTrabajo.dia,
//               unTrabajo.fechaTrabajo.mes,
//               unTrabajo.fechaTrabajo.anio);
//}
//
//int printBicicletas(Trabajo trabajos[], int len)
//{
//    int response=-1;
//    int flag=1;
//    if(trabajos!=NULL && len>0){
//        printf("\n\t\t*****LISTADO DE TRABAJOS******\n");
//        printf("-------------------------------------------------------------------------\n");
//        printf("ID \t\tID BICI \tID SERVICIO \tFecha \n");
//        for(int i=0;i<len;i++){
//            if(!trabajos[i].isEmpty){
//                printTrabajo(trabajos[i]);
//                flag=0;
//            }
//        }
//        if(flag){
//            printf("\n\tNo hay empleados que mostrar\n");
//        }
//    response=0;
//    printf("\n\n");
//    }
//    return response;
//}
