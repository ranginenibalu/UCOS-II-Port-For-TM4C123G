// Includes
#include  <cpu.h>
#include  "bsp.h"
#include  "bsp_sys.h"
#include  "lib_def.h"
#define BSP_SW_GLOBALS 
#include "bsp_sw.h"

// Push Button Initialization
void BSP_SWITCH_Init(void)
{
	// to set the pin direction
	 BSP_GPIO_REG_DIR(BSP_GPIO_PORTF) &= ~(BSP_SWITCH1  | BSP_SWITCH2);
	
	// enable pull up resistor
	 BSP_GPIO_REG_GPIOPUR(BSP_GPIO_PORTF) |= (BSP_SWITCH1  | BSP_SWITCH2);
  
	// cfg pins as digital functions 
   BSP_GPIO_REG_DEN(BSP_GPIO_PORTF) |= (BSP_SWITCH1  | BSP_SWITCH2);
	
}


// Push Button output Read function
CPU_INT08U   	BSP_SWITCH_READ     (void){
	sw12 = (DEF_BIT_IS_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),BSP_SWITCH1));
	return sw12;
}
