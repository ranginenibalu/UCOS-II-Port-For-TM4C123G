/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         BOARD SUPPORT PACKAGE
*
*                                      Texas Instruments TM4C129x
*                                                on the
*
*                                             DK-TM4C129X
*                                           Development Kit
*
* Filename      : bsp_cfg.h
* Version       : V1.00
* Programmer(s) : JJL
*                 FF
*********************************************************************************************************
*/

#ifndef  BSP_CFG_H_
#define  BSP_CFG_H_

/*
*********************************************************************************************************
*                                            MODULES ENABLE
*********************************************************************************************************
*/

#define  BSP_CFG_CAN_EN                     0    /* Enable (1) or Disable (0) uC/CAN                   */
#define  BSP_CFG_CAN_OPEN_EN                0    /* Enable (1) or Disable (0) uC/CANopen               */
#define  BSP_CFG_FS_EN                      0    /* Enable (1) or Disable (0) uC/FS                    */
#define  BSP_CFG_GUI_EN                     0    /* Enable (1) or Disable (0) uC/GUI                   */
#define  BSP_CFG_MBM_EN                     0    /* Enable (1) or Disable (0) uC/Modbus-Master         */
#define  BSP_CFG_MBS_EN                     0    /* Enable (1) or Disable (0) uC/Modbus-Slave          */
#define  BSP_CFG_NET_EN                     0    /* Enable (1) or Disable (0) uC/TCP-IP                */
#define  BSP_CFG_OS2_EN                     0    /* Enable (1) or Disable (0) uC/OS-II                 */
#define  BSP_CFG_OS3_EN                     0    /* Enable (1) or Disable (0) uC/OS-III                */
#define  BSP_CFG_USBD_EN                    0    /* Enable (1) or Disable (0) uC/USB-D                 */
#define  BSP_CFG_USBH_EN                    0    /* Enable (1) or Disable (0) uC/USB-H                 */


/*
*********************************************************************************************************
*                                          CLOCK MANAGEMENT
*********************************************************************************************************
*/

#define  BSP_CFG_SYS_EXT_CLK_FREQ    16000000uL
#define  BSP_CFG_SYS_INT_CLK_FREQ    16000000uL


/*
*********************************************************************************************************
*                                        BOARD SPECIFIC BSPs
*********************************************************************************************************
*/

#define  BSP_CFG_SER_EN                     0    /* Enable (1) or Disable (0) Serial port BSP          */

#define  BSP_CFG_LED_EN                     0    /* Enable (1) or Disable (0) LEDs                     */
#endif
