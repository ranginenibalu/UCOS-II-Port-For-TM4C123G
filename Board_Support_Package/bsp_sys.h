// Include
#include  <cpu.h>

//Macros
#define  BSP_CFG_PLL_N                      1u
#define  BSP_CFG_PLL_Q                      0u
#define  BSP_CFG_PLL_MINT                  0x32u
#define  BSP_CFG_PLL_MFRAC                  0u



// Registers
#define  BSP_SYS_BASE_ADDR                            0x400FE000u
#define	 BSP_SYS_REG_RCC													(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0060u))
#define	 BSP_SYS_REG_GPIOHBCTL										(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x006cu))
#define  BSP_SYS_REG_RCC2													(*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0070u))
#define  BSP_SYS_REG_MOSCCTL                      (*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x007Cu))
#define  BSP_SYS_REG_PLLFREQ0                     (*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0160u))
#define  BSP_SYS_REG_PLLFREQ1                     (*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0164u))
#define  BSP_SYS_REG_PLLSTAT                      (*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0168u))
#define  BSP_SYS_REG_RCGCGPIO                     (*(CPU_REG32 *)(BSP_SYS_BASE_ADDR + 0x0608u))


// Bit definition Macros
#define  BSP_MOSCCTL_NOXTAL                            DEF_BIT_02
#define  BSP_MOSCCTL_MOSCIM                            DEF_BIT_01
#define  BSP_MOSCCTL_CVAL                              DEF_BIT_00


#define BSP_RCC_MOSCDIS																 DEF_BIT_00
#define BSP_RCC_PWRDN																	 DEF_BIT_13
#define BSP_RCC_BYPASS																 DEF_BIT_11
#define BSP_RCC_OSCSRC_MOSC 													 DEF_BIT_MASK(3u,4u)
#define BSP_RCC_XTAL_SET															 DEF_BIT_MASK(21u,6u)
#define BSP_RCC_XTAL_CLR															 DEF_BIT_MASK(10u,6u)	
#define BSP_RCC_SYSDIV_SET														 DEF_BIT_MASK(4u,23u)
#define BSP_RCC_SYSDIV_CLR														 DEF_BIT_MASK(3u,23u)
#define BSP_RCC_USESYSDIV															 DEF_BIT_22
#define BSP_RCC_SYSDIV_MASK														 DEF_BIT_MASK(0xFu,23u)


#define BSP_RCC2_DIV400																 DEF_BIT_30

#define  BSP_RSCLKCFG_MEMTIMU                          DEF_BIT_31
#define  BSP_RSCLKCFG_NEWFREQ                          DEF_BIT_30
#define  BSP_RSCLKCFG_ACG                              DEF_BIT_29
#define  BSP_RSCLKCFG_USEPLL                           DEF_BIT_28
#define  BSP_RSCLKCFG_PLLSRC_PIOSC                     DEF_BIT_NONE
#define  BSP_RSCLKCFG_PLLSRC_MOSC                      DEF_BIT_MASK(3u, 24u)
#define  BSP_RSCLKCFG_OSCSRC_PIOSC                     DEF_BIT_NONE
#define  BSP_RSCLKCFG_OSCSRC_LFIOSC                    DEF_BIT_MASK(2u, 20u)
#define  BSP_RSCLKCFG_OSCSRC_MOSC                      DEF_BIT_MASK(3u, 20u)
#define  BSP_RSCLKCFG_OSCSRC_RTCOSC                    DEF_BIT_MASK(4u, 20u)
#define  BSP_RSCLKCFG_OSYSDIV_MASK                     DEF_BIT_FIELD(10u, 10u)
#define  BSP_RSCLKCFG_PSYSDIV_MASK                     DEF_BIT_FIELD(10u,  0u)

#define  BSP_MEMTIM0_EBCE                              DEF_BIT_21
#define  BSP_MEMTIM0_FBCE                              DEF_BIT_05
#define  BSP_MEMTIM0_xBCHT_SYS_CLK_HIGH                0u
#define  BSP_MEMTIM0_xBCHT_1                           1u
#define  BSP_MEMTIM0_xBCHT_1_5                         2u
#define  BSP_MEMTIM0_xBCHT_2                           3u
#define  BSP_MEMTIM0_xBCHT_2_5                         4u
#define  BSP_MEMTIM0_xBCHT_3                           5u
#define  BSP_MEMTIM0_xBCHT_3_5                         6u
#define  BSP_MEMTIM0_xBCHT_4                           7u
#define  BSP_MEMTIM0_xBCHT_4_5                         8u
#define  BSP_MEMTIM0_EBCHT_MASK                        DEF_BIT_FIELD(4u, 22u)
#define  BSP_MEMTIM0_FBCHT_MASK                        DEF_BIT_FIELD(4u, 6u)
#define  BSP_MEMTIM0_WS_0                              0u
#define  BSP_MEMTIM0_WS_1                              1u
#define  BSP_MEMTIM0_WS_2                              2u
#define  BSP_MEMTIM0_WS_3                              3u
#define  BSP_MEMTIM0_WS_4                              4u
#define  BSP_MEMTIM0_WS_5                              5u
#define  BSP_MEMTIM0_WS_6                              6u
#define  BSP_MEMTIM0_WS_7                              7u
#define  BSP_MEMTIM0_EWS_MASK                          DEF_BIT_FIELD(4u, 16u)
#define  BSP_MEMTIM0_FWS_MASK                          DEF_BIT_FIELD(4u, 0u)

#define  BSP_PLLFREQ0_PLLPWR                           DEF_BIT_23
#define  BSP_PLLFREQ0_MFRAC_MASK                       DEF_BIT_FIELD(10u, 10u)
#define  BSP_PLLFREQ0_MINT_MASK                        DEF_BIT_FIELD(10u,  0u)

#define  BSP_PLLFREQ1_Q_MASK                           DEF_BIT_FIELD(5u, 8u)
#define  BSP_PLLFREQ1_N_MASK                           DEF_BIT_FIELD(5u, 0u)

#define  BSP_PLLSTAT_LOCK                              DEF_BIT_00

#define  BSP_GPIOHBCTL_PORT_F													 DEF_BIT_05
#define  BSP_GPIOHBCTL_PORT_B													 DEF_BIT_02

#define  BSP_RCGCGPIO_PORT_F                           DEF_BIT_05
#define  BSP_RCGCGPIO_PORT_E                           DEF_BIT_04
#define  BSP_RCGCGPIO_PORT_D                           DEF_BIT_03
#define  BSP_RCGCGPIO_PORT_C                           DEF_BIT_02
#define  BSP_RCGCGPIO_PORT_B                           DEF_BIT_01
#define  BSP_RCGCGPIO_PORT_A                           DEF_BIT_00

// Function Prototype
void        BSP_SysInit      (void);
CPU_INT32U  BSP_SysClkFreqGet(void);
