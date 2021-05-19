#include "tipo.h"
#include "color.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}Bicicleta;

int initBicicletas(Bicicleta list[], int len);
int addBicicleta(Bicicleta list[], int len,  int* pCodigo, Tipo tipos[], int lenT, Color colores[], int lenC);
int findEmptyIndex(Bicicleta list[], int len);
void printBicicleta(Bicicleta bici);
int printBicicletas(Bicicleta list[], int len);
int removeBicicleta(Bicicleta list[], int len);
int findBicicletaById(Bicicleta list[], int len, int id);
int updateBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC);
int modifyBicicleta(Bicicleta list[], int len, int index, Tipo tipos[], int lenT, Color colores[], int lenC);
int ordenarBicicletasPorTipo(Bicicleta list[], int len);
#endif // BICICLETA_H_INCLUDED
