#include "file.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"

static uint8_t tableauPixel[32][32];
static uint8_t indiceSommet=-1;
extern UART_HandleTypeDef huart2;

void ajoute(uint8_t *nvPixel)
{
    if(indiceSommet != 31)
    {
        indiceSommet+=1;
        for(int i=0;i<32;i++)
        {
        	tableauPixel[indiceSommet][i]=nvPixel[i];
        }
    }
}

void retire(uint8_t *data)
{
    uint8_t temp[32];
    for(int i=0;i<32;i++)
    {
    	temp[i]=tableauPixel[0][i];
    }
    if(indiceSommet!=-1)
    {
        for(int i=0;i<indiceSommet;i++)
        {
        	for(int j=0;j<32;j++)
        	{
            tableauPixel[i][j]=tableauPixel[i+1][j];
        	}
        }
        indiceSommet-=1;
    }
    //HAL_UART_Transmit(&huart2, temp, 32, 100);
    for(int i=0;i<32;i++)
    {
    data[i]=temp[i];
    }
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
