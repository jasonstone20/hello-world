#!/bin/bash

#Clear the screen
clear

#varibles
name=Jason
ip=`sudo ifconfig | grep "broadcast" | awk '{print $6}'`
face=`sudo ifconfig | grep 'wlan0:' | awk '{print $1}' | cut -d ':' -f1`
user=$(whoami)

#Welcome Text
echo "Hello World" 
echo
echo
echo
echo ================================



#User info
echo "Hello" $name  
echo "User ID =" $user
echo "Your interface is" $face

#IP address
echo "Your IP addresses are" $ip 
echo ================================
echo
echo

#Ping Domain
read -p "Please Enter Domain: " domain
#Check for cr as response
	if [ -z $domain ]; then
#print error and exit
		echo
		echo	
		echo ######################
		#Color Text Red
		echo -e  "\e[1;31m###ERROR-EXITING####\e[0m"
		echo ######################
		exit
	fi
echo ===========================

echo Pinging Domain

echo ===========================




ping -c10 $domain > tmp 

#Results
fast=`grep 'bytes' tmp | awk '{print $8}' | cut -d '=' -f2 | grep '.' | sort | head -1`
slow=`grep 'bytes' tmp | awk '{print $8}' | cut -d '=' -f2 | grep '.' | sort | tail -1`

echo "The fast time is " $fast
echo "The slow time is " $slow



