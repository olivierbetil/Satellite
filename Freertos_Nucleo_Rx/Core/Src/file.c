/**
 * @file file.c
 * @brief Création d'un objet "File" pour avoir un tableau en FIFO
 * @author Olivier BETIL
 * @version 1.0
 * @date 18/11/2022
 */

#include "file.h"
#include <stdint.h>

static uint8_t tableauPixel[32];
static uint8_t indiceSommet=-1;


/**
 * @brief Ajoute un entier au sommet de la file
 *
 * @param[in] nvPixel l'octet à ajouter à la file
 * @return void
 */
void ajoute(uint8_t nvPixel)
{
    if(indiceSommet != 31)
    {
        indiceSommet+=1;
        tableauPixel[indiceSommet]=nvPixel;
    }
}

/**
 * @brief Renvoie un element du tableau et décale les autres éléments afin de fonctionner en FIFO
 *
 * @return retPixel uint8_t Renvoie l'element du tableau le plus ancien
 */
uint8_t retire()
{
    uint8_t retPixel=tableauPixel[0];
    if(indiceSommet!=-1)
    {
        for(int i=0;i<indiceSommet;i++)
        {
            tableauPixel[i]=tableauPixel[i+1];
        }
        indiceSommet-=1;
    }
    return retPixel;
}

/**
 * @brief permet de savoir s'il y a une donnée à récuperer dans le tableau
 *
 * @return true si le tableau n'est pas vide; false si le tableau est vide
 */
uint8_t fileDataAvailable()
{
    if(indiceSommet!=-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
