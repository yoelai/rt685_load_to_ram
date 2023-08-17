/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
typedef enum
{
    eLED_HEARTBEAT,    ///< Pin cab be used to indicate error.
    eFLEXSPI0A1_SCLK,  ///< QSPI_Clk
    eFLEXSPI0A1_SS0_N, ///< QSPI_CS#
    eFLEXSPI0A1_DATA0, ///< QSPI_io0
    eFLEXSPI0A1_DATA1, ///< QSPI_io1
    eFLEXSPI0A1_DATA2, ///< QSPI_io2
    eFLEXSPI0A1_DATA3, ///< QSPI_io3
    eNUM_IO_PINS       ///< Number of IO pins
} BoardOnChipIoPins_t_1;


static const IoPinConfiguration_t s_OnChipIo[eNUM_IO_PINS] = {
    [eLED_HEARTBEAT] =
        {
            .definition = _IOPIN_DEF_SET_PORT(eIOPIN_PORT_A_0) |
                          _IOPIN_DEF_SET_PIN(26) |
                          _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration =   _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_DIG_OUTPUT) |
                                        _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions =  _IOPIN_DIG_OUT_OPT_SET_SLEWRATE(eSLOW) |
                                        _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                        _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW) |
                                        _IOPIN_DIG_OUT_OPT_SET_INITSTATE(eLOW),

            .idleDigitalOptions =   _IOPIN_DIG_OUT_OPT_SET_SLEWRATE(eSLOW) |
                                    _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                    _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },

    [eFLEXSPI0A1_SCLK] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(18U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                       _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                 _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },
    [eFLEXSPI0A1_SS0_N] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(19U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                       _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                  _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },
    [eFLEXSPI0A1_DATA0] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(20U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                       _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                  _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },
    [eFLEXSPI0A1_DATA1] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(21U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                       _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                  _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },
    [eFLEXSPI0A1_DATA2] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(22U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                       _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions = _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                  _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },
    [eFLEXSPI0A1_DATA3] =
        {
            .definition =   _IOPIN_DEF_SET_PORT(eIOPIN_PORT_B_1) |
                            _IOPIN_DEF_SET_PIN(23U) |
                            _IOPIN_DEF_SET_INIT_STATE(eIOPIN_CFGSTATE_OPERATING),

            .operatingConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_USE_FUNCTION) |
                                      _IOPIN_CFG_SET_PIN_FUNC(eIOPIN_FUNC_1) |
                                      _IOPIN_CFG_SET_PIN_PULL(eIOPIN_PULLCFG_NONE),

            .idleConfiguration = _IOPIN_CFG_SET_PIN_MODE(eIOPIN_MODE_HIZ),

            .operatingDigitalOptions =  _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                        _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eHIGH),

            .idleDigitalOptions =   _IOPIN_DIG_OUT_OPT_SET_OPEN_DRAIN(eDISABLE) |
                                    _IOPIN_DIG_OUT_OPT_SET_DRIVE_STRENGTH(eLOW),
        },

};

*/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
void ToggleLed(uint32_t aNumToggles, uint32_t aDelay_uS)
{
    for (uint32_t i = 0u; i < aNumToggles; ++i)
    {
        // Use Heartbeat pin due to Led_Error pin not present in 679-AVI
        //HalIOPinSetDigOutput(&s_OnChipIo[eLED_HEARTBEAT], eLOW);
        //GPIO->DIR[currentPinDefinitions.port]
        GPIO->B[0][26] = (uint8_t)(0);
        
        //HalMcuSpinWait_uS(aDelay_uS);
        SDK_DelayAtLeastUs(aDelay_uS, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        GPIO->B[0][26] = (uint8_t)(1);
        SDK_DelayAtLeastUs(aDelay_uS, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }
}

int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    PRINTF("hello world.\r\n");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
      //ToggleLed(10, 500000);
    }
}
