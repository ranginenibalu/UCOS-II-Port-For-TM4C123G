// INCLUDES
#include "lib_def.h"
#include  <cpu.h>
#include  "bsp_uart.h"
#include "bsp.h"

// UART initialization
void    BSP_UART_Init    (void){
	
	BSP_SYS_REG_RCGC1 |= 0x01u;  //clk enable for uart module0
	
	BSP_SYS_REG_RCGC2 |= 0x23u;  //clk enable for GPIOA & GPIOF bits
	
	BSP_UART_REG_UARTCTL(BSP_UART_0) &= ~(1u<<0);  //uart0 disabled
	
	/** BAUD RATE SETTINGS*/
	// integer part
	BSP_UART_REG_UARTIBRD(BSP_UART_0) |= 8u;
	
	// fractional part
	BSP_UART_REG_UARTFBRD(BSP_UART_0) |= 44u;
	
	// line configs 
	BSP_UART_REG_UARTLCRH(BSP_UART_0) |= ((3u<<5)|(1u<<4));
	
	BSP_UART_REG_UARTCC(BSP_UART_0) |= 5u; 		//PIOS-clk as baud-clk src
	
	BSP_UART_REG_UARTCTL(BSP_UART_0) |= 1u;   //uart0 enabled

	// 0x01 for UART0
	BSP_GPIO_REG_GPIOPCTL1(BSP_UART_0) = (BSP_GPIO_REG_GPIOPCTL1(BSP_UART_0) & 0xffffff00) + 0x00000011;
	
	BSP_GPIO_REG_GPIOAFSEL1(BSP_UART_0) |= 0x3u;
	
	BSP_GPIO_REG_GPIODEN1(BSP_UART_0) |= 0x3u;
	
	BSP_GPIO_REG_GPIOAMSEL1(BSP_UART_0) |= 0x3u;
	
}


// Character send via UART
void    BSP_UART_Send      (const char  tx_data){
	
		
	
		// check for UART busy bit
		while(!(DEF_BIT_IS_CLR(BSP_UART_REG_UARTFR(BSP_UART_0),BSP_UART_TX_CLR) == DEF_YES)){}
	
		// acquire semaphore / wait
		OSSemPend(sharedDataSemUart,0,errorSemUart);
			
			
		BSP_UART_REG_UARTDR(BSP_UART_0) = tx_data;
		
		// Release semaphore
		OSSemPost(sharedDataSemUart);
	
}

// String Send via UART
void    BSP_UART_Send_string      (const char  *tx_data, CPU_INT08U length1){
	CPU_INT08U character=0;
	while(character < length1){
		BSP_UART_Send      (tx_data[character]);
		character++;
	}
}

