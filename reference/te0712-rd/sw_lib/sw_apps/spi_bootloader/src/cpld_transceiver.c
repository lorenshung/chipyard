/*
-- Company: 		Trenz Electronic
-- Engineer: 		Mohsen Chamanbaz
 */

#include "cpld_transceiver.h"
#include "te_iic_platform.h"

unsigned char read_cpld(unsigned char chip_addr,unsigned char reg_addr)
{
	unsigned char _chip_addr = chip_addr;
	unsigned char _reg_addr = reg_addr;
	unsigned char _data;

	int Status;

	Status = iic_init();
	if (Status != XST_SUCCESS)
	{
		xil_printf("\r\nI2C INIT ERROR!\r\n");
		return Status;
	}

	Status = iic_read8(_chip_addr,_reg_addr,&_data);
	if (Status != XST_SUCCESS)
	{
		xil_printf("\r\nI2C READ ERROR!\r\n");
		return Status;
	}

	return _data;
}

int write_cpld(unsigned char chip_addr,unsigned char reg_addr,unsigned char data)
{
	unsigned char _chip_addr = chip_addr;
	unsigned char _reg_addr = reg_addr;
	unsigned char _data = data;
	int Status;

	Status = iic_init();
	if (Status != XST_SUCCESS)
	{
		xil_printf("\r\nI2C INIT ERROR!\r\n");
		return Status;
	}

	Status = iic_write8(_chip_addr,_reg_addr,_data);
	if (Status != XST_SUCCESS)
	{
		xil_printf("\r\nI2C WRITE ERROR!\r\n");
		return Status;
	}

	return XST_SUCCESS;
}
