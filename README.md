# wk-4-displays
<img width="680" height="441" alt="Screenshot 2026-11-02 003744" src="https://github.com/user-attachments/assets/27982412-de91-42a9-b3fb-b1ba0757be65" />

For the schematics and footprint, you will need:
| Component | KiCad Symbol | Footprint |
| :--- | :--- | :--- |
| **Microcontroller** | `Seeed_Studio_XIAO_Series:Seeed_XIAO_ESP32-C3` | `XIAO-ESP32-C3-SMD` |
| **LED Matrix Module Socket** | `Connector:Conn_01x05_Socket` | `Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical` |
| **Push Buttons (x3)** | `Switch:SW_Push` | `Button_Switch_THT:SW_PUSH_6mm` |
| **Rotary Encoder** | `Device:RotaryEncoder_Switch_MP` | `Rotary_Encoder:Rotary_Encoder_Alps_EC11E-Switch_Vertical_H20mm` |

I downloaded the footprints for my board here: https://github.com/Seeed-Studio/OPL_Kicad_Library/blob/master/Seeed%20Studio%20XIAO%20Series%20Library/XIAO-ESP32-C3-SMD.kicad_mod

## The Schematics:
<img width="820" height="442" alt="Screenshot 2026-11-02 004450" src="https://github.com/user-attachments/assets/5ab68327-eff1-4581-be24-446b299f9b02" />
- **A**: Add Symbol (Schematic Editor)
- **L**: Add Net Label (Schematic Editor)
- **E**: Edit Properties (Hover over any symbol or footprint and press E)

  1. Set up the XIAO ESP32-C3
   - Placed the XIAO ESP32-C3 microcontroller symbol on the canvas and assigned the official Seeed footprint (`XIAO-ESP32-C3-SMD`).
<img width="373" height="290" alt="image" src="https://github.com/user-attachments/assets/02947ba6-9e69-475c-81d1-eb6c544c366d" />

2. Added the LED Matrix Connector
   - Added a 5-pin female header socket (`Conn_01x05_Socket`) to connect the display module.
   - Connected hardware SPI pins (D7, D8, D10) plus power and ground using net labels to keep things clean.
<img width="194" height="117" alt="image" src="https://github.com/user-attachments/assets/55cbda99-c131-41fa-841a-f2d218931751" />

3. Wired up the 10 µF Decoupling Capacitor
   - Placed a 10 µF capacitor across 5V and GND right near the matrix header to smooth out any power spikes from the LEDs.
<img width="58" height="109" alt="image" src="https://github.com/user-attachments/assets/c827cd6d-a623-482b-8a81-0c1a17009c51" />

<img width="103" height="189" alt="image" src="https://github.com/user-attachments/assets/1cb7e91b-0056-4fb4-bdae-1d5782710931" />

4. Hooked up the 3 Push Buttons
   - Placed three push button symbols (`SW_Push`) with 6mm THT footprints.
   - Wired one side of each button to GND and the other side to individual GPIO pins (using `INPUT_PULLUP` in code so no extra resistors were needed).
<img width="180" height="59" alt="image" src="https://github.com/user-attachments/assets/593a6424-6620-421c-a8f9-c50785b76aa7" />

5. Added the EC11 Rotary Encoder
   - Placed an EC11 encoder with switch symbol (`RotaryEncoder_Switch_MP`).
   - Wired pins A and B to digital GPIOs for rotation tracking, grounded common pin C and the mounting pins, and wired the built-in push switch (S1/S2) between a GPIO pin and GND.
<img width="99" height="84" alt="image" src="https://github.com/user-attachments/assets/b8e53b59-0ea6-4b60-8c37-617597aeb598" />

6. Cleaned up with Net Labels
   - Used net labels across the whole sheet to keep the schematic tidy and easy to read without drawing long, crisscrossing wires.


## The PCB
Tip: You can use the "F" key to route your wiring using the shortest path
Trace your edge cuts, and you can even add some designs by using the image converter tool! 
<img width="548" height="409" alt="Screenshot 2026-11-02 003212" src="https://github.com/user-attachments/assets/5ca74072-e6e0-42a6-8624-00ab807487db" />


You might need to play around with the size of your image!
1. Go to the image converter tool
   ![image](https://github.com/user-attachments/assets/c0f40734-e1b5-4b7b-830d-a91f1fe3f9b0)

2. Configure your image settings
   ![image](https://github.com/user-attachments/assets/8b2c1dc0-30be-4554-8a79-e62e00159adc)

3. Edit the size if needs be
   ![image](https://github.com/user-attachments/assets/336dabb7-c072-47ac-ab48-8056bdcdb738)

4. Select "Footprint" as the output format (using the F.Cu layer), export to clipboard and paste in your PCB 
   ![image](https://github.com/user-attachments/assets/121f8e22-5580-49a1-9a60-0527d0629c61)

5. Paste on your PCB editor
   ![image](https://github.com/user-attachments/assets/8d87b822-8c47-4d6e-aa42-ed457b8faea5)
