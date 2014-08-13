#ifndef  BSP_SWITCH_H_
#define  BSP_SWITCH_H_

#ifdef   BSP_SW_GLOBALS
#define  BSP_SW_GLOBAL_EXT
#else
#define  BSP_SW_GLOBAL_EXT  extern
#endif

// GLOBAL VARIABLE
BSP_SW_GLOBAL_EXT CPU_INT08U sw12;



// macros
#define  BSP_SWITCH1               					DEF_BIT_04
#define  BSP_SWITCH2             						DEF_BIT_00
#define  BSP_SWITCH_PULLUP									DEF_BIT_04



// FUNCTION PROTOTYPES
void    			BSP_SWITCH_Init    (void);
CPU_INT08U   	BSP_SWITCH_READ     (void);



#endif
