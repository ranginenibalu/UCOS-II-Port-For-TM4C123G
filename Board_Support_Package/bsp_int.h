#ifndef  BSP_INT_PRESENT
#define  BSP_INT_PRESENT

// addr
#define BSP_BASE_ADDR_INT 0xE000E000
#define	 BSP_SYS_REG_0_31_INT	 (*(CPU_REG32 *)(BSP_BASE_ADDR_INT + 0x0100u))

// constants
#define BSP_BIT_INT_0		0x02u
#define BSP_BIT_INT_31	0x40000000u

// Macros for Interrrupt priority                                                        
#define  BSP_INT_PRIO_LEVEL_MASK             DEF_BIT_MASK(7, 0)
#define  BSP_INT_PRIO_LEVEL_00               0u
#define  BSP_INT_PRIO_LEVEL_01               1u
#define  BSP_INT_PRIO_LEVEL_02               2u
#define  BSP_INT_PRIO_LEVEL_03               3u

#ifdef   BSP_INT_MODULE
#define  BSP_INT_EXT
#else
#define  BSP_INT_EXT  extern
#endif





// External Interrupt numbers

#define  BSP_INT_ID_GPIOA                            0u         /*  16, INTISR[  0]  GPIO Port A.                       */
#define  BSP_INT_ID_GPIOB                            1u         /*  17, INTISR[  1]  GPIO Port B.                       */
#define  BSP_INT_ID_GPIOC                            2u         /*  18, INTISR[  2]  GPIO Port C.                       */
#define  BSP_INT_ID_GPIOD                            3u         /*  19, INTISR[  3]  GPIO Port D.                       */
#define  BSP_INT_ID_GPIOE                            4u         /*  20, INTISR[  4]  GPIO Port E.                       */
#define  BSP_INT_ID_UART0                            5u         /*  21, INTISR[  5]  UART0.                             */
#define  BSP_INT_ID_UART1                            6u         /*  22, INTISR[  6]  UART1.                             */
#define  BSP_INT_ID_SSI0                             7u         /*  23, INTISR[  7]  SSI0.                              */
#define  BSP_INT_ID_I2C0                             8u         /*  24, INTISR[  8]  I2C0.                              */
#define  BSP_INT_ID_PWM_FAULT                        9u         /*  25, INTISR[  9]  PWM Fault.                         */
#define  BSP_INT_ID_PWM_GEN0                        10u         /*  26, INTISR[ 10]  PWM Generator 0.                   */
#define  BSP_INT_ID_PWM_GEN1                        11u         /*  27, INTISR[ 11]  PWM Generator 1.                   */
#define  BSP_INT_ID_PWM_GEN2                        12u         /*  28, INTISR[ 12]  PWM Generator 2.                   */
#define  BSP_INT_ID_QEI0                            13u         /*  29, INTISR[ 13]  QEI0.                              */
#define  BSP_INT_ID_ADC0_0                          14u         /*  30, INTISR[ 14]  ADC0 Sequence 0.                   */
#define  BSP_INT_ID_ADC0_1                          15u         /*  31, INTISR[ 15]  ADC0 Sequence 1.                   */
#define  BSP_INT_ID_ADC0_2                          16u         /*  32, INTISR[ 16]  ADC0 Sequence 2.                   */
#define  BSP_INT_ID_ADC0_3                          17u         /*  33, INTISR[ 17]  ADC0 Sequence 3.                   */
#define  BSP_INT_ID_WDTO_WDT1                       18u         /*  34, INTISR[ 18]  Watchdog Timers 0 and 1.           */
#define  BSP_INT_ID_TMR0A                           19u         /*  35, INTISR[ 19]  16/32-Bit Timer 0A.                */
#define  BSP_INT_ID_TMR0B                           20u         /*  36, INTISR[ 20]  16/32-Bit Timer 0B.                */
#define  BSP_INT_ID_TMR1A                           21u         /*  37, INTISR[ 21]  16/32-Bit Timer 1A.                */
#define  BSP_INT_ID_TMR1B                           22u         /*  38, INTISR[ 22]  16/32-Bit Timer 1B.                */
#define  BSP_INT_ID_TMR2A                           23u         /*  39, INTISR[ 23]  16/32-Bit Timer 2A.                */
#define  BSP_INT_ID_TMR2B                           24u         /*  40, INTISR[ 24]  16/32-Bit Timer 2B.                */
#define  BSP_INT_ID_ACOMP0                          25u         /*  41, INTISR[ 25]  Analog Comparator 0.               */
#define  BSP_INT_ID_ACOMP1                          26u         /*  42, INTISR[ 26]  Analog Comparator 1.               */
#define  BSP_INT_ID_ACOMP2                          27u         /*  43, INTISR[ 27]  Analog Comparator 2.               */
#define  BSP_INT_ID_SYS_CTRL                        28u         /*  44, INTISR[ 28]  System Control.                    */
#define  BSP_INT_ID_FLASH                           29u         /*  45, INTISR[ 29]  Flash Memory Control.              */
#define  BSP_INT_ID_GPIOF                           30u         /*  46, INTISR[ 30]  GPIO Port F.                       */
#define  BSP_INT_ID_UART2                           33u         /*  49, INTISR[ 33]  UART2.                             */
#define  BSP_INT_ID_SSI1                            34u         /*  50, INTISR[ 34]  SSI1.                              */
#define  BSP_INT_ID_TMR3A                           35u         /*  51, INTISR[ 35]  16/32-Bit Timer 3A.                */
#define  BSP_INT_ID_TMR3B                           36u         /*  52, INTISR[ 36]  16/32-Bit Timer 3B.                */
#define  BSP_INT_ID_I2C1                            37u         /*  53, INTISR[ 37]  I2C1.                              */
#define  BSP_INT_ID_CAN0                            39u         /*  54, INTISR[ 38]  CAN0.                              */
#define  BSP_INT_ID_CAN1                            40u         /*  55, INTISR[ 39]  CAN1.                              */
#define  BSP_INT_ID_HIB                             43u         /*  57, INTISR[ 41]  HIB(Power Island).                 */
#define  BSP_INT_ID_USB_MAC                         44u         /*  58, INTISR[ 42]  USB MAC.                           */
#define  BSP_INT_ID_PWM_GEN3                        45u         /*  59, INTISR[ 43]  PWM Generator 3.                   */
#define  BSP_INT_ID_UDMA0_SOFT                      46u         /*  60, INTISR[ 44]  uDMA 0 Software.                   */
#define  BSP_INT_ID_UDAM0_ERR                       47u         /*  61, INTISR[ 45]  uDMA 0 Error.                      */
#define  BSP_INT_ID_ADC1_0                          48u         /*  62, INTISR[ 46]  ADC1 Sequence 0.                   */
#define  BSP_INT_ID_ADC1_1                          49u         /*  63, INTISR[ 47]  ADC1 Sequence 1.                   */
#define  BSP_INT_ID_ADC1_2                          50u         /*  64, INTISR[ 48]  ADC1 Sequence 2.                   */
#define  BSP_INT_ID_ADC1_3                          51u         /*  65, INTISR[ 49]  ADC1 Sequence 3.                   */
#define  BSP_INT_ID_SSI2                            57u         /*  70, INTISR[ 54]  SSI2.                              */
#define  BSP_INT_ID_SSI3                            58u         /*  71, INTISR[ 55]  SSI3.                              */
#define  BSP_INT_ID_UART3                           59u         /*  72, INTISR[ 56]  UART3.                             */
#define  BSP_INT_ID_UART4                           60u         /*  73, INTISR[ 57]  UART4.                             */
#define  BSP_INT_ID_UART5                           61u         /*  74, INTISR[ 58]  UART5.                             */
#define  BSP_INT_ID_UART6                           62u         /*  75, INTISR[ 59]  UART6.                             */
#define  BSP_INT_ID_UART7                           63u         /*  76, INTISR[ 60]  UART7.                             */
#define  BSP_INT_ID_I2C2                            68u         /*  77, INTISR[ 61]  I2C 2.                             */
#define  BSP_INT_ID_I2C3                            69u         /*  78, INTISR[ 62]  I2C 3.                             */
#define  BSP_INT_ID_TMR4A                           70u         /*  79, INTISR[ 63]  Timer 4A.                          */
#define  BSP_INT_ID_TMR4B                           71u         /*  80, INTISR[ 64]  Timer 4B.                          */
#define  BSP_INT_ID_TMR5A                           92u         /*  81, INTISR[ 65]  Timer 5A.                          */
#define  BSP_INT_ID_TMR5B                           93u         /*  82, INTISR[ 66]  Timer 5B.                          */

#define  BSP_INT_ID_MAX                            139



// Function Prototypes
void  BSP_IntClr              (CPU_INT08U     int_id);
void  BSP_IntDis              (CPU_INT08U     int_id);
void  BSP_IntDisAll           (void);
void  BSP_IntEn               (CPU_INT08U     int_id);
void  BSP_IntInit             (void);
void  BSP_IntVectSet          (CPU_INT08U     int_id,
                               CPU_FNCT_VOID  isr_fnct);
void  BSP_IntHandler          (CPU_INT16U     src_nbr);
void  BSP_GPIOF_IntHandler          (void);
void BSP_GPIOB_IntHandler(void);

void  BSP_IntHandlerGPIOA     (void);
void  BSP_IntHandlerGPIOB     (void);
void  BSP_IntHandlerGPIOC     (void);
void  BSP_IntHandlerGPIOD     (void);
void  BSP_IntHandlerGPIOE     (void);
void  BSP_IntHandlerUART0     (void);
void  BSP_IntHandlerUART1     (void);
void  BSP_IntHandlerSSI0      (void);
void  BSP_IntHandlerI2C0      (void);
void  BSP_IntHandlerPWM_FAULT (void);
void  BSP_IntHandlerPWM_GEN0  (void);
void  BSP_IntHandlerPWM_GEN1  (void);
void  BSP_IntHandlerPWM_GEN2  (void);
void  BSP_IntHandlerQEI0      (void);
void  BSP_IntHandlerADC0_0    (void);
void  BSP_IntHandlerADC0_1    (void);
void  BSP_IntHandlerADC0_2    (void);
void  BSP_IntHandlerADC0_3    (void);
void  BSP_IntHandlerWDTO_WDT1 (void);
void  BSP_IntHandlerTMR0A     (void);
void  BSP_IntHandlerTMR0B     (void);
void  BSP_IntHandlerTMR1A     (void);
void  BSP_IntHandlerTMR1B     (void);
void  BSP_IntHandlerTMR2A     (void);
void  BSP_IntHandlerTMR2B     (void);
void  BSP_IntHandlerACOMP0    (void);
void  BSP_IntHandlerACOMP1    (void);
void  BSP_IntHandlerACOMP2    (void);
void  BSP_IntHandlerSYS_CTRL  (void);
void  BSP_IntHandlerFLASH     (void);
void  BSP_IntHandlerGPIOF     (void);
//void  BSP_IntHandlerGPIOG     (void);
//void  BSP_IntHandlerGPIOH     (void);
void  BSP_IntHandlerUART2     (void);
void  BSP_IntHandlerSSI1      (void);
void  BSP_IntHandlerTMR3A     (void);
void  BSP_IntHandlerTMR3B     (void);
void  BSP_IntHandlerI2C1      (void);
void  BSP_IntHandlerCAN0      (void);
void  BSP_IntHandlerCAN1      (void);
void  BSP_IntHandlerHIB       (void);
void  BSP_IntHandlerUSB_MAC   (void);
void  BSP_IntHandlerPWM_GEN3  (void);
void  BSP_IntHandlerUDMA0_SOFT(void);
void  BSP_IntHandlerUDAM0_ERR (void);
void  BSP_IntHandlerADC1_0    (void);
void  BSP_IntHandlerADC1_1    (void);
void  BSP_IntHandlerADC1_2    (void);
void  BSP_IntHandlerADC1_3    (void);
void  BSP_IntHandlerSSI2      (void);
void  BSP_IntHandlerSSI3      (void);
void  BSP_IntHandlerUART3     (void);
void  BSP_IntHandlerUART4     (void);
void  BSP_IntHandlerUART5     (void);
void  BSP_IntHandlerUART6     (void);
void  BSP_IntHandlerUART7     (void);
void  BSP_IntHandlerI2C2      (void);
void  BSP_IntHandlerI2C3      (void);
void  BSP_IntHandlerTMR4A     (void);
void  BSP_IntHandlerTMR4B     (void);
void  BSP_IntHandlerTMR5A     (void);
void  BSP_IntHandlerTMR5B     (void);

#endif         

