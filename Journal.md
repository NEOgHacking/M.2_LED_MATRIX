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

So i started by laying out a general schematic

<img width="1522" height="801" alt="Screenshot From 2026-08-19 01-04-58" src="https://github.com/user-attachments/assets/7a6866d4-f4a0-49f9-908c-7a9b0ff7899e" />

Then i started on creating my own CH382L footprint because there didn't exist one yet, this was a long time to get all the pins correct and the right name. For this i devoured the whole datasheet from the inside out and learned the chip far enough that i got a good understanding of its workings.

<img width="547" height="959" alt="Screenshot From 2026-08-19 01-14-08" src="https://github.com/user-attachments/assets/fd349d3e-b0b3-44fa-a178-111498bdfb5d" />

<img width="1028" height="694" alt="Screenshot From 2026-08-19 01-17-24" src="https://github.com/user-attachments/assets/3cc1d0cc-2b0e-445e-953e-438cbc45d23e" />

<img width="1131" height="500" alt="Screenshot From 2026-08-19 01-21-50" src="https://github.com/user-attachments/assets/7a73d7b6-b9eb-4d20-8b5b-bd3b23cd1664" />

<img width="752" height="1153" alt="Screenshot From 2026-08-19 01-35-25" src="https://github.com/user-attachments/assets/e36106b0-5cae-4bfb-a815-01e711c2cb9e" />

Then when this was done i started on the decoupling of the IC as per the datasheet. But with almost all IC's its just 100nf per pin and 1-2.2 uf bulk cap so this was pretty easy.

<img width="1403" height="634" alt="Screenshot From 2026-08-19 01-45-32" src="https://github.com/user-attachments/assets/448b7665-04db-4e89-b3db-0b485f7ac520" />

Then i schematic of the M.2 card, this was kinda difficult because there can be 2 protocols over the same pins and you need to select which one you want and need to select the right pins for that protocol and then also decide what to do with the other strange pins the M.2 standard has. But i made a bus so it would be easier to transfer the right stuff to the IC.

<img width="523" height="1123" alt="Screenshot From 2026-08-19 02-14-15" src="https://github.com/user-attachments/assets/0f8ff2e9-83ca-4835-97d4-24f8280d0047" />

After this i made the whole schematic of the PCIE to UART converter with all the connections and stuff that was needed

<img width="2005" height="1197" alt="Screenshot From 2026-08-19 17-02-21" src="https://github.com/user-attachments/assets/1f3f27e0-ea05-490e-b2b2-9625f512607e" />

After this i started on the RP2354 schematic, at this time it has become almost automatic with how many times i have done this. I used the internal flash because it was cheaper and easier to implement apart from that i went with the A version for space reasons.

<img width="1824" height="1144" alt="Screenshot From 2026-08-19 17-02-06" src="https://github.com/user-attachments/assets/2028b2b7-4e70-45e4-986c-b786e4217995" />

Now it was time to get stared on the layout, at first i assigned all the components correctly with the right sizes for the right components so that i could go to the layout stage.

<img width="2517" height="1369" alt="image" src="https://github.com/user-attachments/assets/42677aa1-4287-4999-bc66-d96349bdb3fc" />

At first i started on the PCIE to UART converter and did all the decoupling and added the crystal and all the rest that was necessary for the ic.

<img width="1700" height="1140" alt="Screenshot From 2026-08-19 17-45-56" src="https://github.com/user-attachments/assets/b96452b1-3e12-49a8-a59b-0896b46dcc2d" />

# Day 3 8h

So woke up bright and early today at 11am to get started with the layout, the one and only dreaded layout. I was kinda locked in really really hard today so also forgot to take as much screenshots as i did the previous times. So i will try to explain and show as good as possible what i did.
At first this day i started with the RP layout, as per the not findable guidelines that RP has.

<img width="833" height="991" alt="image" src="https://github.com/user-attachments/assets/44a2b647-8dcd-488a-bd84-7f7cdb73749f" />

After that i did the high speed PCIE routing for the PCIE to UART converter. This was done using the impedance calculator of JLC to ensure the right impedance for the high speed traces.
I used the inner layer, because on the top and bottom there where components scattered around so it would have been difficult to get them out of the way for the high speed traces so i went for an inner layer.

<img width="710" height="1029" alt="image" src="https://github.com/user-attachments/assets/82eb4d97-0a9b-4f09-8632-8a752d0915a0" />

Then i started on the layout for the LDO's that are used in the PCB because i needed to have as much space as possible for the LED matrix i am gonna add.

<img width="2096" height="760" alt="image" src="https://github.com/user-attachments/assets/109e2156-7a11-4dfb-ac48-325f329d49e3" />

To be honest it has been the most shitty and most complex PCB i have ever made in terms of power traces for power delivery because of the compactness of this PCB

<img width="2096" height="760" alt="image" src="https://github.com/user-attachments/assets/71e925e7-a47c-46bb-8e85-951c5f73e44a" />

After the power stuff was done it was time to get the LED matrix made, i did some test fits and after i did all those test fits i decided on a 11x10 matrix. I made the matrix in the schematic and decided on Green 0603 LEDs for the matrix.

<img width="921" height="432" alt="image" src="https://github.com/user-attachments/assets/e7aa51b5-a141-44d4-8b4c-78110ba408ed" />
<img width="950" height="1123" alt="image" src="https://github.com/user-attachments/assets/857b9b54-cdd7-4069-a137-e91355df74d3" />

After these where made, i slowly made the pinout of the rp based on how i could route stuff.

<img width="890" height="1125" alt="image" src="https://github.com/user-attachments/assets/3d5c346f-304b-418e-9c37-d69c23d94606" />

<img width="890" height="1125" alt="image" src="https://github.com/user-attachments/assets/61e87711-a2dd-480c-967f-f0b56f44dff4" />

This is how the main schematic page turned out.

<img width="1700" height="1018" alt="image" src="https://github.com/user-attachments/assets/180c23fa-e188-4782-98ab-a82193a7b29b" />

And here is how the PCB turned out after all the routing.

<img width="693" height="1195" alt="image" src="https://github.com/user-attachments/assets/a8ffd474-7dec-4f6f-914e-a53bb7d23b43" />

<img width="693" height="1195" alt="image" src="https://github.com/user-attachments/assets/15b8d4c8-3866-477b-aba4-d075bd4b84a2" />

Then i put it in blender and made this render.

![render](Blender/Images/render.png)
