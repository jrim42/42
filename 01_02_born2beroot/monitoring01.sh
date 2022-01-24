#!/bin/bash

arc=$(uname -a)
cpu_p=$(nproc --all)
cpu_v=$(cat /proc/cpuinfo | grep -a processor | wc -l)
ram_use=$(free -m | grep -a Mem | awk '{print $3}')
ram_tot=$(free -m | grep -a Mem | awk '{print $2}')
ram_per=$(free | grep -a Mem | awk '{printf "%.2f%%", ($3)/($2)*100}')
dsk_use=$(df -ma | grep -a /dev/mapper/ | awk '{use+=$3}END{print use}')
dsk_tot=$(df -Ha | grep -a /dev/mapper/ | awk '{tot+=$2}END{print tot}')
dsk_per=$(df -ma | grep -a /dev/mapper/ | awk '{use+=$3 ; tot+=$2}END{printf "%d%%", use/tot*100}')
cpu_l=$(mpstat | grep -a all | awk '{printf "%.2f%%", 100-$13}')
boot=$(who -b | grep -a system | awk '{printf "%s %s", $3, $4}')
lvm_u=$(if [ "$(lsblk | grep -a lvm | wc -l)" -eq 0 ] ; then printf "no" ; else printf "yes" ; fi)
con_tcp=$(ss | grep -a tcp | wc -l | tr -d '\n')
usr_log=$(users | wc -w)
ip_add=$(hostname -I)
mac_add=$(ip link | grep -a link/ether | awk '{print $2}')
cmd=$(cat /var/log/auth.log | grep -a sudo: | grep -a COMMAND | wc -l)

wall   "    #Architecture: $arc
    #CPU physical: $cpu_p
    #vCPU: $cpu_v
    #Memory Usage: $ram_use/${ram_tot}MB ($ram_per)
    #Disk Usage: $dsk_use/${dsk_tot}Gb ($dsk_per)
    #CPU load: $cpu_l
    #Last boot: $boot
    #LVM use: $lvm_u
    #Connexions TCP: $con_tcp ESTABLISHED
    #User log: $usr_log
    #Network: IP $ip_add ($mac_add)
    #Sudo: $cmd cmd"