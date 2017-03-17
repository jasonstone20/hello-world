#!/bin/bash

clear
echo
echo 
echo " This is the menu "
echo
echo
echo
echo "1. Recon people"
echo "2. Recon domains"
echo "3. Open a list in Firefox"
echo "4. Open a domain's robots.txt file in Firefox"
echo "5. Check IP address in ping speed"
echo
echo -n "Choice: "
read choice


echo $choice

case $choice in
	1)./example2.sh ;;
	2)./example3.sh ;;
	3)./example4.sh ;;
	4)./example5.sh ;;
 	5)./ipadd.sh ;;
  	*) echo "You have entered an invalid option" ;;
esac


