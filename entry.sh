#!/bin/bash
#I was working on a simial script but got stuck.
#I found this script and tweaked in after playing with it to get it to do want I needed it to
#The original was written by http://stackoverflow.com/users/1030675/choroba in a repsonse to the
#same problem I was having : http://stackoverflow.com/questions/15807845/list-files-and-show-them-in-a-menu-with-bash

prompt="Please select a file:"
#orignal working line SUCCESS!! -added -executable t find command still shows hidden files
#add '-type f' option in find to hide hidden files ####SUCCESS!!!!!### if works!
options=( $(find  -maxdepth 1 -executable -type f -print0 | xargs -0) )
#experimental line
#num=0
#num=$(($num+1))
#REPLY=$(($num+$REPLY)
#echo $num
#exit
#echo $(($REPLY+1))
#echo $(($opt+1))

#options=`ls` #works, no numbers execpt first and last line shows all files

#options=`ls -Fla | grep \*$ |awk '{print $9}' | cut -d "*" -f1 ; `  #shows onle execudable files

PS3="$prompt "
select opt in "${options[@]}" "Quit" ; do 
    if (( REPLY == 1 + ${#options[@]} )) ; then
       exit

    elif (( REPLY > 0 && REPLY <= ${#options[@]} )) ; then
        #test line !!!!!!!!!!!Runs the file SUCCESS!!!!!!!!!!
	./$opt #!!!!!!!!!!!Runs the file SUCCESS!!!!!!!!!!
	#orininal working line
	#echo  "You picked $opt which is file $REPLY"
        break

    else
        echo "Invalid option. Try another one."
    fi
done    

#ls -ld $opt







# A script I found that recursivly lists files on a disk
# find ./ -type f -name "*" -not -name "*.o" -exec sh -c '
#    case "$(head -n 1 "$1")" in
#      ?ELF*) exit 0;;
#      MZ*) exit 0;;
#      #!*/ocamlrun*)exit0;;
#    esac
# exit 1
# ' sh {} \; -print
