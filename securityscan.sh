#! /bin/bash

#Set Varibles
break="|============================================|"
wave="|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"
line="|--------------------------------------------|"
straight="______________________________________________"




#Welcome Screen
clear
echo
echo $break ; echo $wave ; echo $line
echo
echo "Welcome to Security Scan!"
echo
echo $line ; echo $wave ; echo $break
echo

# Add date and time to error log (scerrlog.txt)

date >>scerrlog.txt
#Menu

echo
echo
echo $straight
echo
echo "Welcome to Security Scan!"
echo "Please choose an option!"
echo $straight
#select arvle in "Anti-Virus" "RootKit" "System" "All" "Exit"; do
#   case $arvle in
#        	Anti-Virus ) echo "Anti-Virus by ClamAV" ; sudo freshclam 2>>scerrlog.txt 2>/dev/null ; sudo clamscan  ;;
#        	RootKit ) echo "RootKit by chkrootkit" ; sudo chkrootkit 2>>scerrlog.txt 2>/dev/null;;
#		System ) git clone https://github.com/CISOfy/lynis 2>>scerrlog.txt 2>/dev/null ; sudo lynis audit systems 2>>scerrlog.txt 2>/dev/null ;;
#		All ) break ;;	
#		Exit ) exit ;;    
#	esac
#done

while true; do
    echo "Please select one"
    echo $straight
    echo		    
    read -p "(A)nti-Virus (R)ootkit (S)ystem (C)omplete Scan (E)xit (a/r/s/c/e)" yn
    echo $straight
    case $yn in
        [Aa]* )  echo "Anti-Virus by ClamAV" ; sudo freshclam 2>>scerrlog.txt 2>/dev/null ; sudo clamscan  ;;  
        [Rr]* )  echo "RootKit by chkrootkit" ; sudo chkrootkit 2>>scerrlog.txt 2>/dev/null ;;
        [Ss]* ) git clone https://github.com/CISOfy/lynis 2>>scerrlog.txt 2>/dev/null ; sudo lynis audit system 2>>scerrlog.txt 2>/dev/null ;;
	[Cc]* ) break ;;
	[Ee]* ) exit ;;
	* ) echo "Please enter (a/r/s/c/e)" ;
    esac
done

#Complete Scan
echo "Starting SecurityScan"
echo 
echo $break
read -p "Press <enter> to start virus scan"
echo "Updating ClamAV"
echo 
echo $break

# Add date and time to error log (scerrlog.txt)

date >> scerrlog.txt

# Update ClamAV

echo
echo $break
echo
sudo freshclam 2>scerrlog.txt 2>/dev/null
echo 
echo $break
echo

# Run ClamAV scan

echo 
echo $break
echo
echo "Running ClamAV Scan"
#sudo clamscan -r --bell  / 2>>scerrlog.txt 2>/dev/null  
#faster scan
#sudo clamscan / 
#fastest scan
sudo clamscan
echo 
echo $break
read -p "Press <enter> to check for rootkits"
echo $break
echo
# Check for RootKits

echo 
echo $break
echo
echo "Checking for RootKits"
sudo chkrootkit 2>scerrlog.txt 2>/dev/null
echo 
echo $break

# System Scan

echo 
echo $break
echo
read -p " Press <enter> to run Lynis Vulnerability Scan"
echo "Scanning System, checking for update...."
echo 
echo $break

# Dowload latest version


echo 
echo $break
echo
echo "Downloading lastest version...."
git clone https://github.com/CISOfy/lynis 2>scerrlog.txt 2>/dev/null
echo 
echo $break

# Run Lynis

echo 
echo $break
echo
sudo lynis audit system 2>scerrlog.txt 2>/dev/null
echo 
echo $break

# Display error log

read -p "Diplaying error log from <scerrlog.txt>. Press <enter> to coninue, then <q> to exit viewer"
cat scerrlog.txt | less

#reset Bash

#echo 
#echo $break
#echo
#echo "Awesome! Thank you for keeping up on your computer security!"
#echo " Not everyone does it and it is very import! You are awesome!"
#read -p "Press <enter> to exit!"
#echo 
#echo $break
#clear
#reset
#bash 
#exit 0

