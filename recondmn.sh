#!/bin/bash 

clear
echo
echo

#User inputs domain
echo -n "Enter a domain: "
read domain
echo

#Check for no answer from user, if no response, exit script
if [ -z $domain];then
	echo "You did not enter domain"
	exit
fi


#Displaying domain
echo $domain
#Search for info on domain and interact with user
echo "Thank you for the input!"
echo "You must be very good with computers!! :-)"
echo "Starting recon on "$domain
read -p "Press <enter> to continue."

# The & symbol keeps things running Google DNS reporst for sites to use
#iceweasel #$domain
#So Firefox opens the second tab without and error, add sleep command after each new tab
sleep 10
#read -p "Press <enter> to display more info"
#iceweasel --new-tab #domain
#other good websites for searching:
#iceweasel --new-tab dns
#sleep 10
#iceweasel --new-tab dnscolors.com
#sleep 10
#iceweasel --new-tab dns.info.com
#sleep 10
#iceweasel --new-tab dnssy.com
#sleep 10


