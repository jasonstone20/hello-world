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

wget -q $domian/robots.txt
cat robots.txt | grep "Disallow" | awk '{print $2}' > tmp
#Another option using cut command
#cat robots.txt | grep "Disallow" | cut -d " " -f2 > tmp

cat tmp
firefox &

sleep 4

#Read a list and open each line in a new tab
for i in $(cat tmp); do
	firefox --new-tab http://$domain$i &
	sleep 4
done



