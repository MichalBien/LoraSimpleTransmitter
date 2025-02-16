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
<li>5V USB power supply
<img src="https://private-user-images.githubusercontent.com/125496642/413630321-21e3cb07-9a80-4b24-bd4c-916127773fb9.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mzk3Mjc4MzIsIm5iZiI6MTczOTcyNzUzMiwicGF0aCI6Ii8xMjU0OTY2NDIvNDEzNjMwMzIxLTIxZTNjYjA3LTlhODAtNGIyNC1iZDRjLTkxNjEyNzc3M2ZiOS5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMjE2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDIxNlQxNzM4NTJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xNGIwMGZhOGJjYjcyMmZiNWM5ZWYzYTgwODVkNjdiZjE4NzM4ODhjODBhMTc1Y2E2ZDdhNjFhY2U3NDE3MzBkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.klvlqksq8B-1tXueuEp_jsNfF51oLqiLqVGUSZVmTS0" alt="transmitter" content-type-secured-asset="image/jpeg">
Fig.1 Hardware setup</li>
</ol>
<p><img src="https://private-user-images.githubusercontent.com/125496642/413630347-0e5bddcf-184f-4f3b-87e1-433c5ac58b93.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mzk3Mjc4MzIsIm5iZiI6MTczOTcyNzUzMiwicGF0aCI6Ii8xMjU0OTY2NDIvNDEzNjMwMzQ3LTBlNWJkZGNmLTE4NGYtNGYzYi04N2UxLTQzM2M1YWM1OGI5My5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMjE2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDIxNlQxNzM4NTJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xNjhiNGEzNWNkZmMyYzkyOGNhYWVkMThkNDVlYTFlOTAyMTE5NmU4ZmIxZjMyNDM5N2I0ZjQ5NDUxMDUyYzJmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.E4NTYSJdZ63dWqo4UWvsy7GhPwHLoh3Ctlsf6WnYqOY" alt="SHT30" content-type-secured-asset="image/jpeg">
Fig.2 SHT30</p>

  
