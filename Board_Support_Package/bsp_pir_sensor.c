
// includes
#include "lib_def.h"
#include  <cpu.h>
#include  "bsp.h"
#include  "bsp_sys.h"
#include  "bsp_pir_sensor.h"

// PIR sensor initialization function
void  BSP_PIR_Init (void)
{	
		// GPIO clock enable
    DEF_BIT_SET(BSP_SYS_REG_RCGCGPIO, BSP_RCGCGPIO_PORT_B);
	
		// GPIO select
		BSP_GPIO_REG_GPIOAFSEL_PIR(BSP_PIR_PORTB) &= ~(BSP_PIR_PORTB_AFSEL);
		
    // Direction for port b                                                     
    BSP_GPIO_REG_DIR_PIR(BSP_PIR_PORTB) &= ~(BSP_PIR_PORTB_5_DIR);

		// enable digital function for the pin B5
    BSP_GPIO_REG_DEN_PIR(BSP_PIR_PORTB) |= (BSP_PIR_PORTB_5_DEN);


}

// PIR output function
CPU_INT08U BSP_pir_out(void){
	// get the input from the PIR sensor
	return (DEF_BIT_IS_SET(BSP_GPIO_REG_DATA_PIR(BSP_PIR_PORTB),BSP_PIR_PORTB_5_DATA));
}

