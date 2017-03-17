#!/bin/bash 

clear
echo
echo

#User inputs domain
echo -n "Enter domain name:> "
read domain
echo

#Check for no answer from user, if no response, exit script
if [ -z domain ];then
	echo "You did not enter a domain."
	exit
fi


#Displaying using input first and last name
echo $domian

#Search for info on names and interact with user
echo "Thank you for the input!"
echo "You must be very good with computers!! :-)"
echo "Starting recon on "$domain
read -p "Press <enter> to continue."

# The & symbol keeps things running
iceweasel http://www.dns-info/$domain/ 2>/dev/null & 

#So Firefox opens the second tab without and error, add sleep command after each new tab
sleep 10
#read -p "Press <enter> to display more info"
#iceweasel --new-tab http://www.peekyou.com/$fname'_'$lname/ 2>/dev/null &
#other good websites for searching:
#http://www.cvagadet.com/person/$fname/$lname/ &
#http://pipl.com/search/?q=$fname+$lname/ &
#http://spokeo.com/search?q=$fname+$lname/ &
#http://www.zabasearch.com/people/$fname+$lname/ &









