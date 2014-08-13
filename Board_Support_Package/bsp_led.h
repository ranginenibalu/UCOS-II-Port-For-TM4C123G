#ifndef  BSP_LED_H_
#define  BSP_LED_H_

//Macros
#define  BSP_LED_TRICOLOR_RED               DEF_BIT_01
#define  BSP_LED_TRICOLOR_BLUE              DEF_BIT_02
#define  BSP_LED_TRICOLOR_GREEN							DEF_BIT_03


// Function Prototypes
void    BSP_LED_Init    (void);
void    BSP_LED_On      (CPU_INT08U  led);
void    BSP_LED_Off     (CPU_INT08U  led);
void    BSP_LED_Toggle  (CPU_INT08U  led);
void  BSP_LED_7_COLORS_SET (CPU_INT08U  led);
void  BSP_LED_7_COLORS_CLR (CPU_INT08U  led);
void BSP_LED_UART_print (CPU_INT08U led);


#endif
