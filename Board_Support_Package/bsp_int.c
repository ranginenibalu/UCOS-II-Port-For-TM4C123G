//INCLUDES
#define  BSP_INT_MODULE
#include  <cpu.h>
#include  <os.h>
#include  "bsp_int.h"
#include  "lib_def.h"
#include  "bsp_led.h"


// Vector Table
static CPU_FNCT_VOID BSP_IntVectTbl[BSP_INT_ID_MAX];


// Function Protype
static  void  BSP_IntHandlerDummy (void);


// Interrupt Disable function
void  BSP_IntDis (CPU_INT08U  int_id)
{
                                                         
			 if (int_id > BSP_INT_ID_MAX) {
						CPU_IntSrcDis(int_id + 16);
				}
}


// Disable all the interrupts (function).
void  BSP_IntDisAll (void)
{
    CPU_IntDis();
}


// Enables an interrupt.
void  BSP_IntEn (CPU_INT08U  int_id)
{
    if (int_id > BSP_INT_ID_MAX) {
        CPU_IntSrcEn(int_id + 16);
    }
}


// Assigning the ISR handlers for respective interrupts.
void  BSP_IntVectSet (CPU_INT08U     int_id,
                      CPU_FNCT_VOID  isr)
{
			CPU_SR_ALLOC();


		 if (int_id < BSP_INT_ID_MAX) {
						CPU_CRITICAL_ENTER();
					BSP_IntVectTbl[int_id]   = isr;                         
						CPU_CRITICAL_EXIT();
			}
}


// Initialize the interrupts.
void  BSP_IntInit (void)
{
    CPU_INT32U  int_id;


   for (int_id = 0; int_id < BSP_INT_ID_MAX; int_id++) {       /* Initialize each interrupt with Dummy Handler         */
			if (int_id == 30){
				BSP_IntVectSet((CPU_INT08U   )int_id,
                       (CPU_FNCT_VOID)BSP_IntHandlerGPIOF);
			}
			else if(int_id == 1){
				BSP_IntVectSet((CPU_INT08U   )int_id,
                       (CPU_FNCT_VOID)BSP_IntHandlerGPIOB);
			} 
		 else{
		 BSP_IntVectSet((CPU_INT08U   )int_id,
                       (CPU_FNCT_VOID)BSP_IntHandlerDummy);
		 }
    }
		
		BSP_SYS_REG_0_31_INT |= (BSP_BIT_INT_0 | BSP_BIT_INT_31);
		
		
}


// Interrupt Handlers
void  BSP_IntHandlerGPIOA     (void)  { BSP_IntHandler(BSP_INT_ID_GPIOA);                 }
void  BSP_IntHandlerGPIOB     (void)  { BSP_GPIOB_IntHandler();                 }
void  BSP_IntHandlerGPIOC     (void)  { BSP_IntHandler(BSP_INT_ID_GPIOC);                 }
void  BSP_IntHandlerGPIOD     (void)  { BSP_IntHandler(BSP_INT_ID_GPIOD);                 }
void  BSP_IntHandlerGPIOE     (void)  { BSP_IntHandler(BSP_INT_ID_GPIOE);                 }
void  BSP_IntHandlerUART0     (void)  { BSP_IntHandler(BSP_INT_ID_UART0);                 }
void  BSP_IntHandlerUART1     (void)  { BSP_IntHandler(BSP_INT_ID_UART1);                 }
void  BSP_IntHandlerSSI0      (void)  { BSP_IntHandler(BSP_INT_ID_SSI0);                  }
void  BSP_IntHandlerI2C0      (void)  { BSP_IntHandler(BSP_INT_ID_I2C0);                  }
void  BSP_IntHandlerPWM_FAULT (void)  { BSP_IntHandler(BSP_INT_ID_PWM_FAULT);             }
void  BSP_IntHandlerPWM_GEN0  (void)  { BSP_IntHandler(BSP_INT_ID_PWM_GEN0);              }
void  BSP_IntHandlerPWM_GEN1  (void)  { BSP_IntHandler(BSP_INT_ID_PWM_GEN1);              }
void  BSP_IntHandlerPWM_GEN2  (void)  { BSP_IntHandler(BSP_INT_ID_PWM_GEN2);              }
void  BSP_IntHandlerQEI0      (void)  { BSP_IntHandler(BSP_INT_ID_QEI0);                  }
void  BSP_IntHandlerADC0_0    (void)  { BSP_IntHandler(BSP_INT_ID_ADC0_0);                }
void  BSP_IntHandlerADC0_1    (void)  { BSP_IntHandler(BSP_INT_ID_ADC0_1);                }
void  BSP_IntHandlerADC0_2    (void)  { BSP_IntHandler(BSP_INT_ID_ADC0_2);                }
void  BSP_IntHandlerADC0_3    (void)  { BSP_IntHandler(BSP_INT_ID_ADC0_3);                }
void  BSP_IntHandlerWDTO_WDT1 (void)  { BSP_IntHandler(BSP_INT_ID_WDTO_WDT1);             }
void  BSP_IntHandlerTMR0A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR0A);                 }
void  BSP_IntHandlerTMR0B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR0B);                 }
void  BSP_IntHandlerTMR1A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR1A);                 }
void  BSP_IntHandlerTMR1B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR1B);                 }
void  BSP_IntHandlerTMR2A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR2A);                 }
void  BSP_IntHandlerTMR2B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR2B);                 }
void  BSP_IntHandlerACOMP0    (void)  { BSP_IntHandler(BSP_INT_ID_ACOMP0);                }
void  BSP_IntHandlerACOMP1    (void)  { BSP_IntHandler(BSP_INT_ID_ACOMP1);                }
void  BSP_IntHandlerACOMP2    (void)  { BSP_IntHandler(BSP_INT_ID_ACOMP2);                }
void  BSP_IntHandlerSYS_CTRL  (void)  { BSP_IntHandler(BSP_INT_ID_SYS_CTRL);              }
void  BSP_IntHandlerFLASH     (void)  { BSP_IntHandler(BSP_INT_ID_FLASH);                 }
void  BSP_IntHandlerGPIOF     (void)  { BSP_GPIOF_IntHandler();                 }
void  BSP_IntHandlerUART2     (void)  { BSP_IntHandler(BSP_INT_ID_UART2);                 }
void  BSP_IntHandlerSSI1      (void)  { BSP_IntHandler(BSP_INT_ID_SSI1);                  }
void  BSP_IntHandlerTMR3A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR3A);                 }
void  BSP_IntHandlerTMR3B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR3B);                 }
void  BSP_IntHandlerI2C1      (void)  { BSP_IntHandler(BSP_INT_ID_I2C1);                  }
void  BSP_IntHandlerCAN0      (void)  { BSP_IntHandler(BSP_INT_ID_CAN0);                  }
void  BSP_IntHandlerCAN1      (void)  { BSP_IntHandler(BSP_INT_ID_CAN1);                  }
void  BSP_IntHandlerHIB       (void)  { BSP_IntHandler(BSP_INT_ID_HIB);                   }
void  BSP_IntHandlerUSB_MAC   (void)  { BSP_IntHandler(BSP_INT_ID_USB_MAC);               }
void  BSP_IntHandlerPWM_GEN3  (void)  { BSP_IntHandler(BSP_INT_ID_PWM_GEN3);              }
void  BSP_IntHandlerUDMA0_SOFT(void)  { BSP_IntHandler(BSP_INT_ID_UDMA0_SOFT);            }
void  BSP_IntHandlerUDAM0_ERR (void)  { BSP_IntHandler(BSP_INT_ID_UDAM0_ERR);             }
void  BSP_IntHandlerADC1_0    (void)  { BSP_IntHandler(BSP_INT_ID_ADC1_0);                }
void  BSP_IntHandlerADC1_1    (void)  { BSP_IntHandler(BSP_INT_ID_ADC1_1);                }
void  BSP_IntHandlerADC1_2    (void)  { BSP_IntHandler(BSP_INT_ID_ADC1_2);                }
void  BSP_IntHandlerADC1_3    (void)  { BSP_IntHandler(BSP_INT_ID_ADC1_3);                }
void  BSP_IntHandlerSSI2      (void)  { BSP_IntHandler(BSP_INT_ID_SSI2);                  }
void  BSP_IntHandlerSSI3      (void)  { BSP_IntHandler(BSP_INT_ID_SSI3);                  }
void  BSP_IntHandlerUART3     (void)  { BSP_IntHandler(BSP_INT_ID_UART3);                 }
void  BSP_IntHandlerUART4     (void)  { BSP_IntHandler(BSP_INT_ID_UART4);                 }
void  BSP_IntHandlerUART5     (void)  { BSP_IntHandler(BSP_INT_ID_UART5);                 }
void  BSP_IntHandlerUART6     (void)  { BSP_IntHandler(BSP_INT_ID_UART6);                 }
void  BSP_IntHandlerUART7     (void)  { BSP_IntHandler(BSP_INT_ID_UART7);                 }
void  BSP_IntHandlerI2C2      (void)  { BSP_IntHandler(BSP_INT_ID_I2C2);                  }
void  BSP_IntHandlerI2C3      (void)  { BSP_IntHandler(BSP_INT_ID_I2C3);                  }
void  BSP_IntHandlerTMR4A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR4A);                 }
void  BSP_IntHandlerTMR4B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR4B);                 }
void  BSP_IntHandlerTMR5A     (void)  { BSP_IntHandler(BSP_INT_ID_TMR5A);                 }
void  BSP_IntHandlerTMR5B     (void)  { BSP_IntHandler(BSP_INT_ID_TMR5B);                 }



// Dummy Handler.
static void  BSP_IntHandlerDummy (void)
{
    while (DEF_TRUE) {
        ;
    }
}


//Interrupt Handler
void  BSP_IntHandler (CPU_INT16U  src_nbr)
{
    CPU_FNCT_VOID  isr;
    CPU_SR_ALLOC();
	
	
		// Tell the OS that we are starting an ISR            
    CPU_CRITICAL_ENTER();                                       
    OSIntEnter();
    CPU_CRITICAL_EXIT();

   if (src_nbr < BSP_INT_ID_MAX) {
       isr = BSP_IntVectTbl[src_nbr];
        if (isr != (CPU_FNCT_VOID)0) {
            isr();
        }
    }
		
		
		// Tell the OS that we are leaving the ISR            
    OSIntExit();                                                
		
}


// Interrupt Handler for GPIO F
void  BSP_GPIOF_IntHandler (void)
{
    CPU_SR_ALLOC();
    CPU_CRITICAL_ENTER();                                      
    OSIntEnter();
	
		BSP_LED_7_COLORS_SET (0);
	
	
    CPU_CRITICAL_EXIT();
	
    OSIntExit();                                               

}


// Interrupt Handler for GPIO B
void BSP_GPIOB_IntHandler(void)
{
				CPU_SR_ALLOC();

				CPU_CRITICAL_ENTER();                                      
				OSIntEnter();
				CPU_CRITICAL_EXIT();
				
				BSP_LED_7_COLORS_SET (0);
			 
				OSIntExit();                                              
				BSP_LED_7_COLORS_SET (0);
				BSP_LED_7_COLORS_SET (1);
				BSP_LED_7_COLORS_SET (2);
}


// interrupt clr function
void  BSP_IntClr (CPU_INT08U  int_id)
{

}

