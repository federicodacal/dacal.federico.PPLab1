#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char marcas[20][20]={
    "Cannondale",
    "Felt",
    "Fuji",
    "Fuji",
    "Top Mega",
    "Master Bici",
    "Master Bici",
    "Raleigh",
    "Trek",
    "Trek",
    "Cannondale",
    "Venzo",
    "Olmo",
    "Master Bici",
    "Top Mega",
    "Olmo",
    "Cannondale",
    "Trinx",
    "Felt",
    "Felt"
};


float rodados[20]={20,26,26,29,26,27.5,20,27.5,26,26,26,27.5,27.5,29,27.5,26,29,20,20,20};

int idTipos[20]={1000,1001,1002,1003,1003,1002,1002,1001,1000,1000,1003,1002,1001,1003,1000,1001,1002,1003,1002,1000};

int idColores[20]={5000,5001,5002,5003,5004,5000,5000,5000,5004,5003,5002,5004,5003,5002,5003,5004,5001,5001,5002,5003};

/** \brief Carga una lista predeterminada a lista de bicicletas
 *
 * \param list[] Employee
 * \param len int
 * \param qty int
 * \param pId int*
 * \return int Lugares ocupados
 *
 */
int hcodeBicicletas(Bicicleta list[], int len, int qty, int* pId)
{
    int places=0;

    if(list!=NULL && len>0 && qty>=0 && qty<=len && pId!=NULL){
        for(int i=0;i<qty;i++){
            list[i].id=*pId;
            (*pId)++;
            strncpy(list[i].marca, marcas[i],sizeof(list[i].marca));
            list[i].idTipo=idTipos[i];
            list[i].idColor=idColores[i];
            list[i].rodado=rodados[i];
            list[i].isEmpty=0;
            places++;
        }
    }

    return places;
}
