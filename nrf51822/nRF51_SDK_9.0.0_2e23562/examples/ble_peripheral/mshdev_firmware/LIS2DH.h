//*Mikhail Sharonov, aka obelix662000@yahoo.com, Copyright (c) 2016. All Rights Reserved.
//*
//*

#ifndef _LIS2DH_H_
#define _LIS2DH_H_
#include "spi_master2.h"
#include "MISFIT.h"

//Registers
#define LIS2DH_STATUS_REG_AUX 	0x07
#define LIS2DH_OUT_TEMP_L 		0x0C
#define LIS2DH_OUT_TEMP_H 		0x0D
#define LIS2DH_INT_COUNTER_REG 	0x0E
#define LIS2DH_WHO_AM_I 		0x0F
#define LIS2DH_TEMP_CFG_REG 	0x1F
#define LIS2DH_CTRL_REG1 		0x20
#define LIS2DH_CTRL_REG2 		0x21
#define LIS2DH_CTRL_REG3 		0x22
#define LIS2DH_CTRL_REG4 		0x23
#define LIS2DH_CTRL_REG5 		0x24
#define LIS2DH_CTRL_REG6 		0x25
#define LIS2DH_REFERENCE 		0x26
#define LIS2DH_STATUS_REG2 		0x27
#define LIS2DH_OUT_X_L 			0x28
#define LIS2DH_OUT_X_H 			0x29
#define LIS2DH_OUT_Y_L 			0x2A
#define LIS2DH_OUT_Y_H 			0x2B
#define LIS2DH_OUT_Z_L 			0x2C
#define LIS2DH_OUT_Z_H 			0x2D
#define LIS2DH_FIFO_CTRL_REG 	0x2E
#define LIS2DH_FIFO_SRC_REG 	0x2F
#define LIS2DH_INT1_CFG 		0x30
#define LIS2DH_INT1_SOURCE 		0x31
#define LIS2DH_INT1_THS 		0x32
#define LIS2DH_INT1_DURATION 	0x33
#define LIS2DH_INT2_CFG 			0x34
#define LIS2DH_INT2_SOURCE 		0x35
#define LIS2DH_INT2_THS 		0x36
#define LIS2DH_INT2_DURATION 	0x37
#define LIS2DH_CLICK_CFG 		0x38
#define LIS2DH_CLICK_SRC 		0x39
#define LIS2DH_CLICK_THS 		0x3A
#define LIS2DH_TIME_LIMIT 		0x3B
#define LIS2DH_TIME_LATENCY 	0x3C
#define LIS2DH_TIME_WINDOW 		0x3D
#define LIS2DH_ACT_THS 			0x3E
#define LIS2DH_ACT_DUR 			0x3F

//Register Masks

//STATUS_AUX_REG masks
#define LIS2DH_TOR_MASK 		0x40
#define LIS2DH_TDA_MASK 		0x04

//INT_COUNTER masks
//what goes here?

//WHO_AM_I masks
#define LIS2DH_I_AM_MASK 		0x33

// TEMP_CFG_REG masks
#define LIS2DH_TEMP_EN_MASK 	0xC0

// CTRL_REG1 masks
#define LIS2DH_ODR_MASK 		0xF0
#define LIS2DH_LPEN_MASK 		0x08
#define LIS2DH_Z_EN_MASK 		0x04
#define LIS2DH_Y_EN_MASK 		0x02
#define LIS2DH_X_EN_MASK		0x01
#define LIS2DH_XYZ_EN_MASK		0x07

// CTRL_REG2 masks
#define LIS2DH_HPM_MASK 		0xC0
#define LIS2DH_HPCF_MASK 		0x30
#define LIS2DH_FDS_MASK 		0x08
#define LIS2DH_HPCLICK_MASK 	0x04
#define LIS2DH_HPIS2_MASK 		0x02
#define LIS2DH_HPIS1_MASK 		0x01

// CTRL_REG3 masks
#define LIS2DH_I1_CLICK 		0x80
#define LIS2DH_I1_AOI1 			0x40
#define LIS2DH_I1_AOI2 			0x20
#define LIS2DH_I1_DRDY1			0x10
#define LIS2DH_I1_DRDY2			0x08
#define LIS2DH_I1_WTM 			0x04
#define LIS2DH_I1_OVERRUN 	0x02

// CTRL_REG4 masks
#define LIS2DH_BDU_MASK 		0x80
#define LIS2DH_BLE_MASK 		0x40
#define LIS2DH_FS_MASK 			0x30
#define LIS2DH_HR_MASK 			0x08
#define LIS2DH_ST_MASK 			0x06
#define LIS2DH_SIM_MASK 		0x01

// CTRL_REG5 masks
#define LIS2DH_BOOT_MASK 		0x80
#define LIS2DH_FIFO_EN_MASK 	0x40
#define LIS2DH_LIR_INT1_MASK 	0x08
#define LIS2DH_D4D_INT1_MASK 	0x04
#define LIS2DH_LIR_INT2_MASK	0x02
#define LIS2DH_D4D_INT2_MASK	0x01

// CTRL_REG6 masks
#define LIS2DH_I2C_CCK_EN_MASK	0x80
#define LIS2DH_I2C_INT1_MASK 	0x40
#define LIS2DH_I2C_INT2_MASK 	0x20
#define LIS2DH_BOOT_I2_MASK 	0x10
#define LIS2DH_P2_ACT_MASK 		0x08
#define LIS2DH_H_LACTIVE_MASK 	0x02

// REF masks
// none

// STATUS_REG masks
#define LIS2DH_ZYXOR_MASK 		0x80
#define LIS2DH_ZOR_MASK 		0x40
#define LIS2DH_YOR_MASK 		0x20
#define LIS2DH_XOR_MASK 		0x10
#define LIS2DH_ZYXDA_MASK 		0x08
#define LIS2DH_ZDA_MASK 		0x04
#define LIS2DH_YDA_MASK 		0x02
#define LIS2DH_XDA_MASK 		0x01

// FIFO_CTRL_REG masks
#define LIS2DH_FM_MASK 			0xC0
#define LIS2DH_TR_MASK 			0x20
#define LIS2DH_FTH_MASK 		0x1F

// FIFO_SRC_REG masks
#define LIS2DH_WTM_MASK 		0x80
#define LIS2DH_OVRN_FIFO_MASK 	0x40
#define LIS2DH_EMPTY_MASK 		0x20
#define LIS2DH_FSS_MASK 		0x1F

// INT1/2_CFG masks
#define LIS2DH_AOI_MASK 		0x80
#define LIS2DH_6D_MASK 			0x40
#define LIS2DH_ZHIE_MASK 		0x20
#define LIS2DH_ZLIE_MASK 		0x10
#define LIS2DH_YHIE_MASK 		0x08
#define LIS2DH_YLIE_MASK 		0x04
#define LIS2DH_XHIE_MASK 		0x02
#define LIS2DH_XLIE_MASK 		0x01

// INT1/2_SRC masks
#define LIS2DH_INT_IA_MASK 		0x40
#define LIS2DH_ZH_MASK 			0x20
#define LIS2DH_ZL_MASK 			0x10
#define LIS2DH_YH_MASK 			0x08
#define LIS2DH_YL_MASK 			0x04
#define LIS2DH_XH_MASK 			0x02
#define LIS2DH_XL_MASK 			0x01

// INT1/2_THS masks
#define LIS2DH_THS_MASK 		0x4F

// INT1/2_DURATION masks
#define LIS2DH_D_MASK 			0x4F

// CLICK_CFG masks
#define LIS2DH_ZD_MASK 			0x20
#define LIS2DH_ZS_MASK 			0x10
#define LIS2DH_YD_MASK 			0x08
#define LIS2DH_YS_MASK 			0x04
#define LIS2DH_XD_MASK 			0x02
#define LIS2DH_XS_MASK 			0x01

// CLICK_SRC masks
#define LIS2DH_CLK_IA_MASK 		0x40
#define LIS2DH_DCLICK_MASK 		0x20
#define LIS2DH_SCLICK_MASK 		0x10
#define LIS2DH_SIGN_MASK 		0x08
#define LIS2DH_Z_CLICK_MASK 	0x04
#define LIS2DH_Y_CLICK_MASK 	0x02
#define LIS2DH_X_CLICK_MASK 	0x01

// CLICK_THS masks
#define LIS2DH_CLK_THS_MASK 	0x7F

// TIME_LIMIT masks
#define LIS2DH_TLI_MASK 		0x7F

// ACT_THS masks
#define LIS2DH_ACTH_MASK 		0x7F



#define LIS2DH_DEFAULT_ADDRESS 	0x18

    void LIS2DH_init(void);

		int16_t LIS2DH_getAxisX(void);
		int16_t LIS2DH_getAxisY(void);
		int16_t LIS2DH_getAxisZ(void);
		void LIS2DH_writeRegister(const uint8_t register_addr, const uint8_t value);
		uint8_t LIS2DH_readRegister(const uint8_t register_addr);
		



#endif /* _LIS2DH_H_ */
