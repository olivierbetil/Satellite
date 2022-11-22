#include "file.h"
#include <stdint.h>

static uint8_t tableauPixel[32];
static uint8_t indiceSommet=-1;

void ajoute(uint8_t nvPixel)
{
    if(indiceSommet != 31)
    {
        indiceSommet+=1;
        tableauPixel[indiceSommet]=nvPixel;
    }
}

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

uint8_t fileDataAvailable()
{
	uint8_t retint=0;
    if(indiceSommet!=-1)
    {
    	retint=1;
        return retint;
    }
    else
    {
        return retint;
    }
}