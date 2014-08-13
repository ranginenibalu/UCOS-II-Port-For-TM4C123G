
// check whether BSP_H is design
#ifndef  BSP_H_
#define  BSP_H_

#include "os.h"


// macros
#define  BSP_GPIO_PORTA                                        0u
#define  BSP_GPIO_PORTB                                        1u
#define  BSP_GPIO_PORTC                                        2u
#define  BSP_GPIO_PORTD                                        3u
#define  BSP_GPIO_PORTE                                        4u
#define  BSP_GPIO_PORTF                                        5u


// Register Address
#define  BSP_GPIO_BASE_ADDR                            0x40058000u
#define  BSP_GPIO_REG_DATA(port_nbr)              (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR +  (0x1000 * (port_nbr)) + 0x03FCu))
#define  BSP_GPIO_REG_DIR(port_nbr)               (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR + 0x1000 * (port_nbr) + 0x0400u))
#define  BSP_GPIO_REG_GPIOPUR(port_nbr)						(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR + 0x1000 * (port_nbr) + 0x0510u))
#define  BSP_GPIO_REG_DEN(port_nbr)               (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR + 0x1000 * (port_nbr) + 0x051Cu))

// Avoid multiple global variable declaration
#ifdef   BSP_BSP_GLOBALS
#define  BSP_BSP_GLOBAL_EXT
#else
#define  BSP_BSP_GLOBAL_EXT  extern
#endif


// Global Variables
BSP_BSP_GLOBAL_EXT OS_EVENT *sharedDataSem;
BSP_BSP_GLOBAL_EXT INT8U *errorSem;
BSP_BSP_GLOBAL_EXT OS_EVENT *MailBox1;
BSP_BSP_GLOBAL_EXT INT8U *errorMailbox1;
BSP_BSP_GLOBAL_EXT INT8U global_pir_val;
BSP_BSP_GLOBAL_EXT OS_EVENT *sharedDataSemUart;
BSP_BSP_GLOBAL_EXT INT8U *errorSemUart;

// Function Prototype
void  BSP_Init (void);

#endif
