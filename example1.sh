#!/bin/bash

clear


#Global varibles

user=$(whoami)
break="================================================="


echo
echo
echo
echo "Hello Jason%!"
echo 
echo $break
echo
echo "Good morning, "$user
echo
echo $break
echo $break
#Ping a site
ping -c3 google.com
echo
echo "Ping complete."
#Making a pause
read -p "Press <enter> to continue."

#run ifconfig
sudo ifconfig


#Hide output to user using 2>/dev/null 

rm temp8 2>/dev/null


