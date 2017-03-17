#!/bin/bash 

clear
echo
echo

#User inputs first name
echo -n "First name: "
read fname
echo

#Check for no answer from user, if no response, exit script
if [ -z $fname ];then
	echo "You did not enter a name."
	exit
fi

#User inputs last name
echo -n "Last name: "
read lname
echo
#Check for no answer from user, if no response, exit script
if [ -z $lname ];then
	echo "You did not enter a name."
	exit
fi

#Displaying using input first and last name
echo $fname $lname

#Search for info on names and interact with user
echo "Thank you for the input!"
echo "You must be very good with computers!! :-)"
echo "Starting recon on "$fname $lname
read -p "Press <enter> to continue."

# The & symbol keeps things running
iceweasel http://www.411.com/name/$fname-$lname/ 2>/dev/null & 

#So Firefox opens the second tab without and error, add sleep command after each new tab
sleep 10
#read -p "Press <enter> to display more info"
iceweasel --new-tab http://www.peekyou.com/$fname'_'$lname/ 2>/dev/null &
#other good websites for searching:
#iceweasel --new-tab http://www.cvagadet.com/person/$fname/$lname/ &
#sleep 10
#iceweasel --new-tab http://pipl.com/search/?q=$fname+$lname/ &
#sleep 10
#iceweasel --new-tab http://spokeo.com/search?q=$fname+$lname/ &
#sleep 10
#iceweasel --new-tab http://www.zabasearch.com/people/$fname+$lname/ &
#sleep 10








