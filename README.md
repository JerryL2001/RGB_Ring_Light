# Introduction
A RGB ring light that can be controlled both through LAN and internet. To control it through internet, the wifi your board connected to should have internet connection

Demo video on: https://youtu.be/I4JFI7Y2HLA


# Materials Needed
### 1. A ring-shaped lamp (to get a nice looking case, the cheapest will do)

<div align=center>
<img width="300" src="https://user-images.githubusercontent.com/119554730/205442811-5f88b51e-070d-40cd-a5ee-b8e9a1b78715.jpg">
</div>

### 2. An ESP8266 development board

<div align=center>
<img width="300" src="https://user-images.githubusercontent.com/119554730/205442956-80c5409c-7379-4d29-abb5-be7ce9e91644.png">
</div>

### 3. A battery management board with battery indicator

<div align=center>
<img width="200" src="https://user-images.githubusercontent.com/119554730/205443039-cec23a4f-ad46-43b4-96a1-922259091977.jpg">
</div>

### 4. A lithium battery (the capacity of it can be decided according to the empty space of the lamp you buy)

<div align=center>
<img width="300" src="https://user-images.githubusercontent.com/119554730/205443145-4b2be562-5cf6-48f3-8122-399a5766d4bb.jpg">
</div>

### 5. A WS2812B light bar

<div align=center>
<img width="300" src="https://user-images.githubusercontent.com/119554730/205443196-45db947f-4eb8-46c8-939d-ce6dc01b171f.jpg">
</div>

### 6. A cable with a USB-A port (Cut off the interface and use a multimeter to identify the positive and negative wires)

<div align=center>
<img width="300" src="https://user-images.githubusercontent.com/119554730/205443305-d2ed4303-4d5d-4390-a992-de1d75e767e3.png">
</div>


# Connect these devices as shown below, install them into the case
<div align=center>
<img width="1127" src="https://user-images.githubusercontent.com/119554730/205442253-aa1e09db-e4ab-489a-83f4-86c6d5d0a63f.png">
</div>

# Software Part
### 1. Download Blinker app from: https://diandeng.tech/home to your mobile phone, open it

### 2. Follow the steps below to register and apply for a new device:

<img width="600" src="https://user-images.githubusercontent.com/119554730/205445740-f1ca9340-d8d8-4fd3-9866-fd5b4bbeef08.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205445870-48a778c1-3dc3-4945-96ee-72727694e5d4.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205446058-7323fb6c-3c5d-4794-ad08-1092a6a5a8e8.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205446088-6c74bd00-861e-49ef-83b1-398d5bc389b2.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447072-a0355ae6-b5fe-4a50-8958-06ef7a6f6e35.jpg"> 

##### ↓ Go back to the main interface

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447454-6ece1bec-7d6c-4926-9583-fe8c895f9b5c.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447471-a03c32ec-9b42-4053-a64d-48d62963745c.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447509-d197b53c-d0d2-47b7-8945-958cfd059e5a.jpg">

##### ↑ Red arrow points to add a button, blue arrow points to add a slider

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447648-8c0292e8-1170-4546-a0be-74f1ee817dfc.jpg">

<img width="600" src="https://user-images.githubusercontent.com/119554730/205447680-8a51df7e-a78f-403b-8ce3-5778b6bf5023.jpg">

##### ↑ Red arrow points to the name of the botton set in the program, sky blue arrow points to the name of the button shown on your mobile phone interface

<img width="600" src="https://user-images.githubusercontent.com/119554730/205448080-8cd74f03-b4be-4613-bd3e-00eaa7e87909.jpg">

##### ↑ Red arrow points to the name of the slider set in the program, blue arrow points to the name of the slider shown on your mobile phone interface, orange arrow points to the minimum value of the slider, green arrow points to the maximum value of the slider(change it to 255 in this project)

### 3. Add all the bottons and sliders needed on your mobile phone interface (Their names should match the ones set in the program)

### 4. Connect the ESP8266 development board to the computer ~ install the serial chip driver ~ open "RGB_Ring_Light.ino" with Arduino IDE ~ enter the key you got, your wifi name and password to the program ~ compile and upload the program to the development board

### 5. ENIOY YOUR RGB RING LIGHT!

<img width="500" src="https://user-images.githubusercontent.com/119554730/205491446-14de312a-8668-4b1d-81df-3d9f17343998.jpg">

