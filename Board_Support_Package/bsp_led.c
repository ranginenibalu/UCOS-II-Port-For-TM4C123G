// Includes
#include "lib_def.h"
#include  <cpu.h>
#include  "bsp.h"
#include  "bsp_led.h"
#include  "bsp_sys.h"
#include  "bsp_uart.h"
#include  "lib_str.h"


// LED initialization
void  BSP_LED_Init (void)
{
                                                                /* Enable GPIO clock                                    */
    DEF_BIT_SET(BSP_SYS_REG_RCGCGPIO, (BSP_RCGCGPIO_PORT_F));
	
		DEF_BIT_SET(BSP_SYS_REG_GPIOHBCTL, BSP_GPIOHBCTL_PORT_F); // ahb bus
	
                                                                /* Set PQ7(GREEN) and PQ4(BLUE) pins as output          */
    BSP_GPIO_REG_DIR(BSP_GPIO_PORTF) = (BSP_LED_TRICOLOR_GREEN |
                                        BSP_LED_TRICOLOR_BLUE | BSP_LED_TRICOLOR_RED);

                                                                /* En PQ7(GREEN) and PQ4(BLUE) pins digital functions   */
    BSP_GPIO_REG_DEN(BSP_GPIO_PORTF) = (BSP_LED_TRICOLOR_GREEN |
                                        BSP_LED_TRICOLOR_BLUE | BSP_LED_TRICOLOR_RED);

    //BSP_LED_Off(0);                                             /* Turn OFF LEDs.                                       */

}


// LED 7 Turn on Function
void  BSP_LED_7_COLORS_SET (CPU_INT08U  led)
{
    switch (led) {
        case 0:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_RED);
				

				break;
				
				
				case 1:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_BLUE);
      		
				break;
				
				case 2:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_GREEN);
            				
				break;
				
				case 3:
            DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_BLUE));
								
				break;


        case 4:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_GREEN));
									
				break;
				
				case 5:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_GREEN| BSP_LED_TRICOLOR_BLUE));
        
				break;
				
				case 6:
             DEF_BIT_SET(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_BLUE|BSP_LED_TRICOLOR_GREEN));
			
						break;

       default:
             break;
    }
}

// LED 7 Turn off Function
void  BSP_LED_7_COLORS_CLR (CPU_INT08U  led)
{
    switch (led) {
        case 0:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_RED);
             break;


        case 1:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_BLUE);
             break;
				
				case 2:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         BSP_LED_TRICOLOR_GREEN);
             break;
				
				case 3:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_BLUE));
             break;


        case 4:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_GREEN));
             break;
				
				case 5:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_GREEN| BSP_LED_TRICOLOR_BLUE));
             break;
				
				case 6:
             DEF_BIT_CLR(BSP_GPIO_REG_DATA(BSP_GPIO_PORTF),
                         (BSP_LED_TRICOLOR_RED | BSP_LED_TRICOLOR_BLUE|BSP_LED_TRICOLOR_GREEN));
             break;

       default:
             break;
    }
}


// UART LED color print
void BSP_LED_UART_print (CPU_INT08U led)
{
    switch (led) {
        case 0:
            
						BSP_UART_Send_string      ("Red\n\r",Str_Len("Red\n\r"));

				break;
				
				
				case 1:
     
						BSP_UART_Send_string      ("Blue\n\r",Str_Len("Blue\n\r"));			
				break;
				
				case 2:

            BSP_UART_Send_string      ("Green\n\r",Str_Len("Green\n\r"));				
				break;
				
				case 3:
            
						BSP_UART_Send_string      ("Pink\n\r",Str_Len("Pink\n\r"));					
				break;


        case 4:
             
						BSP_UART_Send_string      ("Yellow\n\r",Str_Len("Yellow\n\r"));					
				break;
				
				case 5:
            
            BSP_UART_Send_string      ("Sky Blue\n\r",Str_Len("Sky Blue\n\r"));	
				break;
				
				case 6:
            
						BSP_UART_Send_string      ("White\n\r",Str_Len("White\n\r"));	
						break;

       default:
             break;
    }
}
