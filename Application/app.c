// Includes
#include  "app_cfg.h"
#include  <cpu_core.h>
#include  <os.h>
#include  "bsp.h"
#include  "bsp_led.h"
#include  "bsp_sys.h"
#include 	"bsp_sw.h"
#include  "bsp_uart.h"
#include  "bsp_pir_sensor.h"
#include  "lib_str.h"

// Task stack allocations
static OS_STK       AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];
static OS_STK				AppTaskLedStk[APP_CFG_TASK_START_STK_SIZE];
static OS_STK				AppTaskSwStk[APP_CFG_TASK_START_STK_SIZE];
static OS_STK				AppTaskPirStk[APP_CFG_TASK_START_STK_SIZE];
static OS_STK				AppTaskLed2Stk[APP_CFG_TASK_START_STK_SIZE];

// function prototypes
static void AppTaskLed(void *p_arg);
static void AppTaskStart(void *p_arg);
static void AppTaskSwitch(void *p_arg);
static void AppTaskPir(void *p_arg);
static void AppTaskLed2(void *p_arg);


// Main function called from startup code
int  main (void)
{

		// Disable all interrupts
    CPU_IntDis();                                               
		
		// uCOS II kernel initialization
    OSInit();                                                   
	
		// Create the configuration task
	OSTaskCreate((void (*)(void *))AppTaskStart,
								 (void           *)0,
								 (OS_STK         *) &AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE - 1],
								 (INT8U           )APP_CFG_TASK_START_PRIO); 

		// Start the multitasking 
    OSStart();                
		
    while (1) {
        ;
    }
}


// Configuration Task function
static  void  AppTaskStart (void *p_arg)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;
		
		// Call bsp initialization function
		BSP_Init();                                                 
	
		// Determine SysTick reference freq.                    
    cpu_clk_freq = BSP_SysClkFreqGet();                        

		// Determine nbr SysTick increments                     
    cnts         = cpu_clk_freq / (CPU_INT32U)OS_TICKS_PER_SEC;
		OS_CPU_SysTickInit(cnts);
		
		// Initialize the uC/CPU services                       
    CPU_Init();                                                 
		
		// Memory initialization
    Mem_Init();
	
		// Create LED task
		OSTaskCreate((void (*)(void *))AppTaskLed,
										 (void           *)0,
										 (OS_STK         *) &AppTaskLedStk[APP_CFG_TASK_START_STK_SIZE - 1],
										 (INT8U           )APP_LED_TASK_START_PRIO); 
										 
		// Create Push Button Task
		OSTaskCreate((void (*)(void *))AppTaskSwitch,
										 (void           *)0,
										 (OS_STK         *) &AppTaskSwStk[APP_CFG_TASK_START_STK_SIZE - 1],
										 (INT8U           )APP_SW_TASK_START_PRIO); 

		// Create PIR sensor Task
		OSTaskCreate((void (*)(void *))AppTaskPir,
										 (void           *)0,
										 (OS_STK         *) &AppTaskPirStk[APP_CFG_TASK_START_STK_SIZE - 1],
										 (INT8U           ) APP_PIR_TASK_START_PRIO); 

		// Create LED 2 Task
		OSTaskCreate((void (*)(void *))AppTaskLed2,
										 (void           *)0,
										 (OS_STK         *) &AppTaskLed2Stk[APP_CFG_TASK_START_STK_SIZE - 1],
										 (INT8U           )APP_LED2_TASK_START_PRIO); 
	
	// Delete the configuration task
	OSTaskDel(APP_CFG_TASK_START_PRIO);
    
}



// PIR task function
static void AppTaskLed(void *p_arg){
			CPU_INT08U led7;
	
			while(1){
				
					// acquire / wait semaphore
					OSSemPend(sharedDataSem,0,errorSem);
					
					// Toggle six different LEDs
					for (led7=1;led7<7;++led7){
									BSP_LED_7_COLORS_SET(led7);
									BSP_LED_UART_print(led7);
									OSTimeDly(50);
									BSP_LED_7_COLORS_CLR(led7);
					}
					
					// Release semaphore
					OSSemPost(sharedDataSem);
			}
}


// PIR sensor Task function
static void AppTaskPir(void *p_arg){
			CPU_INT08U temp;
			
			while(1){
						
							// PIR sensor output value
							temp = BSP_pir_out();
					
							// check whether output is true
							if(temp == DEF_YES){
							
										global_pir_val=temp;
										
										// Send output to mailbox
										OSMboxPost(MailBox1,&global_pir_val);
										
										// UART string print
										BSP_UART_Send_string("PIR Task : Movement detected and PIR Output value sent to Mailbox\n\r", Str_Len("PIR Task : Movement detected and PIR Output value sent to Mailbox\n\r"));
										
										// wait for 4 seconds
										OSTimeDly(200);
							}
							
							else{
										// wait for 0.4 secons 20
										OSTimeDly(20);
							}
				
			}
}


static void AppTaskLed2(void *p_arg){
			CPU_INT08U temp,temp1,temp2,temp3;
	
			while(1){	
				
						// Receive Mail from Mailbox
						OSMboxPend(MailBox1,0,errorMailbox1);
				
						// Check the message received is true
						if (global_pir_val == DEF_YES){
									
									// Clear all the LEDs
									BSP_LED_7_COLORS_CLR(0);
									BSP_LED_7_COLORS_CLR(1);
									BSP_LED_7_COLORS_CLR(2);
									
									// UART string print
									BSP_UART_Send_string("LED 2 Task : PIR Output value Received From Mailbox\n\r", Str_Len("LED 2 Task : PIR Output value Received From Mailbox\n\r"));
							
									for (temp3 = 0 ; temp3<4;++temp3){
										
												// Set the Red LED
												BSP_LED_7_COLORS_SET(0);
										
												// Time Delay and task doesn't enter wait state
												for(temp=0;temp<50;++temp){	
															for(temp1=0;temp1<50;++temp1){
																		for(temp2=0;temp2<50;++temp2){}
															}
												}	
												
												// Clear the Red LED
												BSP_LED_7_COLORS_CLR(0);
												
												// Time Delay and task doesn't enter wait state
												for(temp=0;temp<50;++temp){	
															for(temp1=0;temp1<50;++temp1){
																	for(temp2=0;temp2<50;++temp2){}
															}
												}
									}
										
									// Global variable is cleared
									global_pir_val=0;
					}
			}
}


// Push Button Task Function
static  void  AppTaskSwitch(void *p_arg){
	
			while(1){
						if((	BSP_SWITCH_READ() == DEF_YES)){
									// acquire semaphore / wait
									OSSemPend(sharedDataSem,0,errorSem);
							
									// clear all the LEDS
									BSP_LED_7_COLORS_CLR(0);
									BSP_LED_7_COLORS_CLR(1);
									BSP_LED_7_COLORS_CLR(2);
									
									// Send a string to PC terminal
									BSP_UART_Send_string      ("Button Task : Switch Is Pressed\n\r", Str_Len("Button Task : Switch Is Pressed\n\r"));
									
									// wait for 6 seconds
									OSTimeDly(300);
							
									// Release the semaphore
									OSSemPost(sharedDataSem);
						}
						else{
									// wait for 0.1 seconds
									OSTimeDly(5);
						}
			}
}

