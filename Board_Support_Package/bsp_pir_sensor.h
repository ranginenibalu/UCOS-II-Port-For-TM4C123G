
// check whether pir.h is defined or not
#ifndef  BSP_PIR_H_
#define  BSP_PIR_H_


// constants
#define BSP_PIR_PORTB_5_DIR   DEF_BIT_05
#define BSP_PIR_PORTB_5_DEN		DEF_BIT_05
#define BSP_PIR_PORTB_5_DATA	DEF_BIT_05
#define BSP_PIR_PORTB					1u
#define BSP_PIR_PORTB_AFSEL		DEF_BIT_01

// registers
#define  BSP_GPIO_BASE_ADDR_PIR                            0x40004000u
#define  BSP_GPIO_REG_DATA_PIR(port_nbr)              (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_PIR +  (0x1000 * (port_nbr)) + 0x03FCu))
#define  BSP_GPIO_REG_DIR_PIR(port_nbr)               (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_PIR + 0x1000 * (port_nbr) + 0x0400u))
#define  BSP_GPIO_REG_GPIOPUR_PIR(port_nbr)						(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_PIR + 0x1000 * (port_nbr) + 0x0510u))
#define  BSP_GPIO_REG_DEN_PIR(port_nbr)               (*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_PIR + 0x1000 * (port_nbr) + 0x051Cu))
#define  BSP_GPIO_REG_GPIOAFSEL_PIR(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_PIR + 0x1000 * (port_nbr) + 0x0420u))


// function prototypes
void BSP_PIR_Init(void);
CPU_INT08U BSP_pir_out(void);
#endif
