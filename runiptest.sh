#!/bin/bash
xterm -title "1" -hold -e "bmon" &
  
xterm -title "2" -hold -e "nload" &

xterm -title "3" -hold -e "iftop" &

xterm -title "4" -hold -e "iptraf" &

xterm -title "5" -hold -e "htop"

