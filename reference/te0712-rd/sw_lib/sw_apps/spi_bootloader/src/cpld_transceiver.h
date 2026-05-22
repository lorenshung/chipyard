/*
-- Company: 		Trenz Electronic
-- Engineer: 		Mohsen Chamanbaz
 */
#ifndef CPLD_TRANSCEIVER_H
#define CPLD_TRANSCEIVER_H

unsigned char read_cpld(unsigned char chip_addr,unsigned char reg_addr);
int write_cpld(unsigned char chip_addr,unsigned char reg_addr,unsigned char data);

#endif
