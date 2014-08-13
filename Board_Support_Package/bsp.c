
// Includes
#define BSP_BSP_GLOBALS
#include  "bsp.h"
#include  "bsp_sys.h"
#include  "bsp_led.h"
#include  "bsp_int.h"
#include  "bsp_sw.h"
#include  "bsp_uart.h"
#include  "bsp_pir_sensor.h"
#include  "os.h"

// BSP initialization

void  BSP_Init (void)
{
		// Interrupt initialization
    BSP_IntInit();
		
		// Initailize system services, clocks, etc.
    BSP_SysInit();             

		// RGB LED initialization
    BSP_LED_Init();
	
		// Push Button initialization
		BSP_SWITCH_Init();
	
		// PIR sensor initialization
		BSP_PIR_Init();
	
		// UART initialization
		BSP_UART_Init();
	
		// Semaphore Create
		sharedDataSem = OSSemCreate(1);
		
		// semaphore Create
		sharedDataSemUart = OSSemCreate(1);
		
		// Mailbox Create
		MailBox1 = OSMboxCreate(&global_pir_val);
	
}

