#include "stm32f4xx_hal.h"
#include "joystick.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

//combiner les deux mouvements en une seule fonction avec un type des enum
uint8_t movementx()
{
	uint32_t ADC_value=0;
	uint8_t valeurReturn=0;
	HAL_ADC_Start(&hadc1); // start A/D conversion
	if(HAL_ADC_PollForConversion(&hadc1, 5) == HAL_OK) //check if conversion is completed
	{
		ADC_value  = HAL_ADC_GetValue(&hadc1); // read digital value and save it inside uint32_t variable
	}
	if(ADC_value>1500)
	{
		valeurReturn=1;
	}
	else if(ADC_value<1500)
	{
		valeurReturn=-1;
	}
	HAL_ADC_Stop(&hadc1); // stop conversion
	return valeurReturn;
}