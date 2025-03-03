<div id="wiki-content" class="mt-4">
      <div data-view-component="true" class="Layout Layout--flowRow-until-md Layout--sidebarPosition-end Layout--sidebarPosition-flowRow-end">
  <div data-view-component="true" class="Layout-main">          <div id="wiki-body" class="gollum-markdown-content">
              <div class="markdown-body">
                <p>This is the first part of a two-part simple project based on STM32WLE5JC microcontrollers, where one STM32 microcontroller acts as the transmitter and the other as the receiver.</p>
<p>This project demonstrates how to simply read humidity and temperature data from an SHT30 sensor using STM32 and the I2C protocol. The read data is sent via LoRa to another STM32WLE5JC, which acts as the receiver. The project also shows how to use the sequencer and low power mode.</p>
<p>Most important files:</p>
<ol>
<li>Core/src/main.c - Receiving data from the SHT30, creating tasks to work with the sequencer.</li>
<li>SubGHz_Phy/App/subghz_phy_app.c - Sending data via LoRa.</li>
</ol>
<p>Hardware:</p>
<ol>
<li>Development board Wio-E5 mini: Wio-E5 mini. This board includes the STM32WLE5JC, UART/USB-C converter, power supply, and antenna.</li>
<li>SHT30 - Humidity and temperature sensor with I2C communication.</li>
<li>5V USB power supply</li>
      
![transmitter](https://github.com/user-attachments/assets/3e30adec-44c9-4394-b10a-96336e7cf6a7)

Fig.1 Hardware setup</li>
![SHT30](https://github.com/user-attachments/assets/1931267f-aefa-4bc4-a122-5dbe46e12148)

Fig.2 SHT30</p>


