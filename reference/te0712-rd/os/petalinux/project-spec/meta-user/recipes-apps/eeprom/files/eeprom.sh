#!/bin/sh

normal="\e[39m"
    #lightred="\e[91m"
    #lightgreen="\e[92m"
    #green="\e[32m"
    #yellow="\e[33m"
    #cyan="\e[36m"
    #red="\e[31m"
    #magenta="\e[95m"
		
		#echo -ne $yellow

maclo=`devmem 0x40000000`
maclo=`printf "%0*X" 8 $maclo`


#echo $maclo

machi=`devmem 0x40000008 16`
machi=`printf "%0*X" 4 $machi`

#echo $machi

macaddr=$machi$maclo

echo EEPROM MACADDRESS: $macaddr


ifconfig eth0 down

ifconfig eth0 hw ether $macaddr

ifconfig eth0 up

echo MAC ADDRESS IS BEING SET!!


read mac_system </sys/class/net/eth0/address
mac=$(echo $mac_system | sed 's/://g')

echo MAC ADDRESS FROM EEPROM $macaddr
echo MAC ADDRESS FROM ETH0 $mac

if [ "${macaddr,,}" = "${mac,,}" ];
then
    #echo -ne $lightgreen
    echo "PASSED, EEPROM MAC WAS SET!"
    #echo -ne $normal
else
    #echo -ne $lightred
    echo "FAILED, EEPROM MAC IS NOT EQUAL TO SYSTEM MAC! RERUN SCRIPT /etc/init.d/eeprom"
    #echo -ne $normal
fi

#lese raminhalt aus in skripte
mv /usr/bin/ramtoskript /tmp/

/tmp/ramtoskript

echo -ne $normal