#!/bin/bash

#Recoger los datos de arquitectura del sistema
arch=$(uname -a) 

#Mostrar el nº de nucleos fisicos 
phy_cpu=$(grep "physical id" /proc/cpuinfo | wc -l)

#Mostrar el nº de nucleos virtuales
vir_cpu=$(grep "processor" /proc/cpuinfo | wc -l)

#Mostrar la memoria RAM expresada en Megabytes
#Memoria RAM usada
usedRAM=$(free --mega | awk '$1 == "Mem:" {print $3}')
#Memoria RAM total
totalRAM=$(free --mega | awk '$1 == "Mem:" {print $2}')

#Mostrar la memoria RAM usada a modo de porcentaje
used_percentt_RAM=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}')

#Mostrar la memoria del disco ocupada
#usamos df (disk free) y aplicamos una suma de la columna 3 con awk tras un filtrado previo
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'
#Mostramos la memoria total de disgo, en Gb
df -m | grep "/dev/" | grep -v "/boot" | awk '{total_space += $2} END {printf("%.0fGb\n"),total_space/1024}'
#Mostramos como porcentaje la memoria usada de la total, combinando las dos formulas anteriores
df - | grep "/dev/"  grep -v "/boot" | awk '{memory_use += $3}{total_space +=$2} END {printf("(%d%%)\n"),memory_use/total_use}'
