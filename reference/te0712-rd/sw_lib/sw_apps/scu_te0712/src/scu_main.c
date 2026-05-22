#include <stdio.h>


#include "xil_types.h"
#include "xparameters.h"


#include "xio.h"
// #include "microblaze_sleep.h"

// #include "xiomodule_l.h"

u32 GPO1_shadow;

// int si5338_init();

#include "te_iic_platform.h"

#ifdef TE_STANDALONE
// #include "te_si534x.h"
#include "te_si5338.h"
#include "te_uart.h"

#include "sleep.h"

u8 iic_write(u8 value);

/*
 *
 *
 *
 *
 */
#define GPO1 XPAR_IOMODULE_SINGLE_BASEADDR+XGO_OUT_OFFSET
//#define GPI1 XPAR_IOMODULE_SINGLE_BASEADDR+XGI_IN_OFFSET

int iic_check_presence(unsigned char chip_addr);//, unsigned char reg_addr, unsigned char *data);

int main()
{
	int Status_init = 0; 
  int Status_si_init = 0;
	//u8 rd_val;
	u32 gpi;
	u8 buffer[4];
	int programmed_flag = 0;

	GPO1_shadow = 0x00000003;

	//read 32 bit input
	gpi = XIo_In32(GPIO_IN_REG);

	buffer[0] = (gpi >> 24) & 0xFF; // extract Pll program bit and revision e.g. 12 - programm '1' and rev '2' -> 0001 0010


    // PLL should only be programmed if rev 01 or rev 02 is present


    if(buffer[0] > 15 ){ // programm bit is set, so programm PLL

    	    	Status_init = iic_init();

    	    	Status_si_init = si5338_init(0x70);
            
            Status_init = Status_init + Status_si_init; 
            
				programmed_flag = 1;


    }

    // From REV03 and higher, U14 with address 61h is connected to the I2C Bus


    // PLL will be not programmed if the pll-programm bit in the SC IP is set to zero in the SC IP Parameters.


    // put out the revision, out to the axi 32 reg IP
    buffer[0] = buffer[0] - 16;

    buffer[0] = buffer[0] * 0x10;

    int c;
    for (c = 1; c <= 10; c++){

    	XIo_Out32(GPO1, 0x00000003);
    	XIo_Out32(GPO1, 0x00000003);
    	XIo_Out32(GPO1, 0x10000003);
    	XIo_Out32(GPO1, 0x20000003);
    	XIo_Out32(GPO1, 0x30000003);
    	XIo_Out32(GPO1, 0x40000003);

    }


    sleep(3);

  if(programmed_flag == 0) {

 		XIo_Out32(GPO1, 0x80000003+buffer[0]);

	}else { // pll was programmed so set the bit 
  
      if(Status_init > 0){ // error ocurred during i2c init
        
           		XIo_Out32(GPO1, 0x81100003+buffer[0]);
        
      }else {
            //programmed! + revision indicator
              XIo_Out32(GPO1, 0x81000003+buffer[0]);
        
      }


	}
   

    return 0;
}


int iic_check_presence(unsigned char chip_addr)//, unsigned char reg_addr), unsigned char *data)
{
	int Status = 0;

	iic_start();
	Status = iic_write(chip_addr << 1);		// Chip addr & Write
	if(Status != 0)							// No ACK from chip
	{
		p_printf(("IIC Write: no ACK from Slave\r\n"));
		return 1;
	}
	/* Status = iic_write(reg_addr);			// Register address
	if(Status != 0)							// No ACK from chip
	{
		p_printf(("IIC Write: no ACK from Slave\r\n"));
		return 1;
	}
	iic_start();							// Repeated start
	Status = iic_write((chip_addr << 1) | 0x01);	// Chip addr & Read
	if(Status != 0)							// No ACK from chip
	{
		return 1;
	}
	*data = iic_read(1);						// NACK */
	iic_stop();
	return 0;
}



#endif /* TE_STANDALONE */
