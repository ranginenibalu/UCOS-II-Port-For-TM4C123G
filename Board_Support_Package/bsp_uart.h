// check whether it is defined
#ifndef  BSP_UART_H_
#define  BSP_UART_H_


// macros
#define  BSP_UART_PORTA0              DEF_BIT_00
#define  BSP_UART_PORTA1              DEF_BIT_01
#define  BSP_UART_MOD0								DEF_BIT_00
#define  BSP_UART_PORTA								DEF_BIT_00
#define  BSP_UART_TX_CLR							DEF_BIT_03

// uart 0 - 7 macros
#define  BSP_UART_0                                        0u
#define  BSP_UART_1                                        1u
#define  BSP_UART_2                                        2u
#define  BSP_UART_3                                        3u
#define  BSP_UART_4                                        4u
#define  BSP_UART_5                                        5u
#define  BSP_UART_6                                        6u
#define  BSP_UART_7                                        7u


// GPIO registers
#define  BSP_GPIO_BASE_ADDR_1                            0x40004000u
#define  BSP_GPIO_REG_GPIOAFSEL1(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_1 + 0x1000 * (port_nbr) + 0x0420u))
#define  BSP_GPIO_REG_GPIOPCTL1(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_1 + 0x1000 * (port_nbr) + 0x052Cu))
#define  BSP_GPIO_REG_GPIOPUR1(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_1 + 0x1000 * (port_nbr) + 0x0510u))
#define  BSP_GPIO_REG_GPIODEN1(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_1 + 0x1000 * (port_nbr) + 0x051cu))
#define  BSP_GPIO_REG_GPIOAMSEL1(port_nbr)					(*(CPU_REG32 *)(BSP_GPIO_BASE_ADDR_1 + 0x1000 * (port_nbr) + 0x0528u))

// system control registers
#define  BSP_SYS_BASE_ADDR_1                            0x400FE000u
#define  BSP_SYS_REG_RCGCUART											(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR_1 + 0x0618u))
#define  BSP_SYS_REG_RCGC1											(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR_1 + 0x0104u))
#define  BSP_SYS_REG_RCGC2											(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR_1 + 0x0108u))


// UART config Registers
#define BSP_UART_BASE_ADDR 														0x4000C000u
#define  BSP_UART_REG_UARTDR(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0000u))
#define  BSP_UART_REG_UARTIBRD(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0024u))
#define  BSP_UART_REG_UARTCTL(port_nbr)						(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0030u))
#define  BSP_UART_REG_UARTFBRD(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0028u))
#define  BSP_UART_REG_UARTLCRH(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x002Cu))
#define  BSP_UART_REG_UARTCC(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0FC8u))
#define  BSP_UART_REG_UARTFR(port_nbr)					(*(CPU_REG32 *)(BSP_UART_BASE_ADDR + 0x1000 * (port_nbr) + 0x0018u))


// FUNCTION PROTOTYPES
void    BSP_UART_Init    (void);
void    BSP_UART_Send      (const char  tx_data);
void    BSP_UART_Send_string      (const char  *tx_data, CPU_INT08U length1);

#endif
