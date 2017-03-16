#!/bin/bash

#Entry Script...read and list 
#menu of executable files 
#in current directory

#read files on disk 
ls -Fla | grep \*$ |awk '{print $9}' | cut -d "*" -f1 > filelist.txt

#cat filelist.txt
#Read a list 
num=0
mun=1
plus=1
#list files





#for i in $(cat filelist.txt); do
#	num=$(($num+$mun))
#	array=($num $i)  
	#echo ${array[*]}
#done

function scan2 () {
     
    	for i in $(cat filelist.txt); do
		num=$(($num+$mun))
		array=($num $i)  
		echo ${array[*]}
	done
    local nl=$array
    echo "${nl}${nl}" # 2 in the string + 1 by ech
    		
}

# append a character to the total output.
# and strip it with %% parameter expansion.
VAR=$(scan2; echo "x"); VAR="${VAR%%x}"

echo -n "${VAR}---" 
read go


#echo "$(($num+$mun)) $i"
#echo $VAR
#echo $go

#case $go in
#	1) echo 1 ;;
#	2) echo 2 ;;
#	3) echo 3 ;;
#	4) echo 4 ;;
 #	5) echo 5 ;;
 # 	#*) echo "You have entered an invalid option" ;;
#esac






#for i in $(cat filelist.txt); do
#	num=$(($num+$mun))
#	array=($num $i)  
#	echo ${array[*]}
	
#done









#files=`cat filelist.txt`
#Try using array to list files
#decare array
#declare -a arr="$files"
## now loop through the above array
#for i in "${arr[@]}"
#do
	   
#	echo "$(($num+$mun)) $i"
	
	   
# or do whatever with individual element of the array
#done



#I found this script on the web that lists and number all the files on a directory
#then ask you to select a file and then echos the file number and filename


#!/bin/bash
#prompt="Please select a file:"
#options=( $(find -maxdepth 1 -print0 | xargs -0) )

#PS3="$prompt "
#select opt in "${options[@]}" "Quit" ; do 
#    if (( REPLY == 1 + ${#options[@]} )) ; then
#        exit

#    elif (( REPLY > 0 && REPLY <= ${#options[@]} )) ; then
#        echo  "You picked $opt which is file $REPLY"
#        break

#    else
#        echo "Invalid option. Try another one."
#    fi
#done    

#ls -ld $opt

