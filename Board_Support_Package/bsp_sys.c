// Includes
#include  "bsp_cfg.h"
#include  "lib_def.h"
#include  "bsp_sys.h"
	
void  BSP_SysInit (void)
{
    /* Enable xtal crystal oscillator                       */
    DEF_BIT_CLR(BSP_SYS_REG_MOSCCTL, (BSP_MOSCCTL_NOXTAL));

		// PLL configuration. RCC PLLFREQ0 PLLFREQ1 registers should be edited.
		// RCC register configuration follows
		// select main clock oscillator rcc register.
		DEF_BIT_SET(BSP_SYS_REG_RCC, BSP_RCC_BYPASS); // this bit is to be configured before configuring pwrdn bit
		DEF_BIT_CLR(BSP_SYS_REG_RCC,(BSP_RCC_PWRDN));
		
		DEF_BIT_SET(BSP_SYS_REG_RCC2,BSP_RCC2_DIV400); // to use 400MHz
		
		DEF_BIT_SET(BSP_SYS_REG_RCC,BSP_RCC_SYSDIV_SET);
		DEF_BIT_CLR(BSP_SYS_REG_RCC,BSP_RCC_SYSDIV_CLR);
		
		DEF_BIT_SET(BSP_SYS_REG_RCC,BSP_RCC_USESYSDIV);
		
		DEF_BIT_SET(BSP_SYS_REG_RCC,BSP_RCC_XTAL_SET); // 16 MHz external oscillator
		DEF_BIT_CLR(BSP_SYS_REG_RCC,BSP_RCC_XTAL_CLR);
    /* MDIV = MINT + (MFRAC / 1024)                         */
    /* MDIV = 50   + (0 / 1024) = 50                        */
    BSP_SYS_REG_PLLFREQ0 = ((BSP_CFG_PLL_MFRAC << 10u)  |
                            (BSP_CFG_PLL_MINT  <<  0u));
		/* Fvco freq = (fmosc * MDIV) / ((Q + 1) * (N + 1))     */
    /*           = (16MHz * 96) / (0 + 1) * (1 + 1))        */
		/*           = 400MHz                                   */
    BSP_SYS_REG_PLLFREQ1 = ((BSP_CFG_PLL_Q << 8u)  |
                            (BSP_CFG_PLL_N << 0u));

    
		// enable the main oscillator
		DEF_BIT_CLR(BSP_SYS_REG_RCC,BSP_RCC_MOSCDIS); 
		
		// selecting the main oscillator clock
		DEF_BIT_CLR(BSP_SYS_REG_RCC,BSP_RCC_OSCSRC_MOSC); 

		/* Wait for PLL to power and lock.                      */
    while (DEF_BIT_IS_CLR(BSP_SYS_REG_PLLSTAT, BSP_PLLSTAT_LOCK) == DEF_YES) {
        ;
    }

}


// System Clock Frequency
CPU_INT32U  BSP_SysClkFreqGet (void)
{
    CPU_INT32U  pll_mdiv;
    CPU_INT16U  pll_mint;
    CPU_INT16U  pll_mfrac;
    CPU_INT16U  pll_q;
    CPU_INT16U  pll_n;
    CPU_INT32U  sys_div;
    CPU_INT32U  sys_freq;
    CPU_INT32U  pll_src;

    if ((DEF_BIT_IS_SET(BSP_SYS_REG_RCC, BSP_RCC_USESYSDIV)) == DEF_YES) {
        pll_mfrac = (BSP_SYS_REG_PLLFREQ0 >> 10u) & 0x07FFu;
        pll_mint  = (BSP_SYS_REG_PLLFREQ0       ) & 0x07FFu;
        pll_mdiv  = (pll_mint + (pll_mfrac / 1024u));

        pll_q = (BSP_SYS_REG_PLLFREQ1 >> 8) & 0x1Fu;
        pll_n = (BSP_SYS_REG_PLLFREQ1     ) & 0x1Fu;

        pll_src = (BSP_SYS_REG_RCC >> 4u) & 0x3u;

        switch (pll_src) {
            case 0:
                 pll_src = BSP_CFG_SYS_INT_CLK_FREQ;
                 break;


            case 3:
                 pll_src = BSP_CFG_SYS_EXT_CLK_FREQ;
                 break;


            default:
                 break;
        }

        sys_freq = ((pll_src * pll_mdiv) / ((pll_q + 1u) * (pll_n + 1u)));

        sys_div = ((BSP_SYS_REG_RCC & BSP_RCC_SYSDIV_MASK)>>23);

        sys_freq = sys_freq / sys_div;

    } else {
        sys_freq = 0;
    }

    return (sys_freq);
}
