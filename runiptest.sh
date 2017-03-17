#!/bin/bash
xterm -title "1-bmon" -hold -e "bmon" &
  
xterm -title "2-nload" -hold -e "nload" &

xterm -title "3-iftop" -hold -e "sudo iftop" &

xterm -title "4-iptraf" -hold -e "sudo iptraf-ng" &

xterm -title "5-htop" -hold -e "htop"

