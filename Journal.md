# Day 1 3h
This was a late night when i heard that my friend was doing a ysws speed run so of course i had to participate. At first there was a big brainstorming session when i came to the conclusion i would make an M.2 LED matrix. This was what i wanted to make but i had to make it as cheap as possible, so at first i looked at the PCB, the biggest size i could get that would be under the 50x50 price point of 
jlcpcb was the 2242, everything above that was too long, but i wanted it as big as possible. Then i dove a bit into M.2 socket types and found out i needed to get a M type socked because its the most common on PC and its used widely. Then i finally had chosen what size M.2 i wanted but still needed to look for the IC's necessary to get this thing to work, i wanted to have it be able to communicate with 
the PC to be able to switch grapics or GIFs. This will be done over PCIE because on an M socket there is only PCIE and SATA, and SATA is only storage so i would need to go for PCIE.
<img width="593" height="1134" alt="image" src="https://github.com/user-attachments/assets/dba2ba92-70b9-4d76-a659-d12496eee2c9" />
After having choosen that i went looking on LCSC for an PCIE to USB or UART converter to be able to talk to the RP2354. After a bit of a search i settled on this CH382L chip that has dual UART outputs of which i would only need one.
<img width="929" height="416" alt="image" src="https://github.com/user-attachments/assets/c8d90eb7-8172-42cd-87b8-59773aa75717" />
Then i choose the RP2354A microcontroller because of its price, size, and my knowledge of it.
<img width="929" height="416" alt="image" src="https://github.com/user-attachments/assets/b76e4059-5428-4443-89be-3a7098d944d1" />
Then i knew which IC's i would want but was still unsure of what size of LED matrix i would want, but i would decide that when i have the rest build so i could see how much space i would have left.

# Day 2 8h
