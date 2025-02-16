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

              </div>

              <div id="wiki-footer" class="mt-5 Link--muted wiki-footer">
                <a class="d-block p-3 Link--muted text-center border border-dashed rounded-2" href="/MichalBien/LoraSimpleTransmitter/wiki/_new?wiki%5Bname%5D=_Footer">
                  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-plus mr-1">
    <path d="M7.75 2a.75.75 0 0 1 .75.75V7h4.25a.75.75 0 0 1 0 1.5H8.5v4.25a.75.75 0 0 1-1.5 0V8.5H2.75a.75.75 0 0 1 0-1.5H7V2.75A.75.75 0 0 1 7.75 2Z"></path>
</svg> Add a custom footer
</a>              </div>
          </div>
</div>
  <div style="min-width: 0" data-view-component="true" class="Layout-sidebar">          <div class="wiki-rightbar">
            <nav id="wiki-pages-box" class="mb-4 wiki-pages-box js-wiki-pages-box" aria-labelledby="wiki-pages-box-heading">
              
<div class="Box Box--condensed color-shadow-small">
  <div class="Box-header px-2 py-1 js-wiki-toggle-collapse" style="cursor: pointer">
    <h3 class="Box-title d-flex flex-items-center" id="wiki-pages-box-heading">
      <button id="icon-button-122e1418-b6e2-4cf7-840f-ed34bea9037c" aria-labelledby="tooltip-05cec74d-3d40-4776-b84d-ae5a0048dd66" type="button" data-view-component="true" class="Button Button--iconOnly Button--invisible Button--small js-wiki-sidebar-pages-toggle-chevron js-wiki-sidebar-pages-toggle-chevron-open">  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-triangle-down Button-visual">
    <path d="m4.427 7.427 3.396 3.396a.25.25 0 0 0 .354 0l3.396-3.396A.25.25 0 0 0 11.396 7H4.604a.25.25 0 0 0-.177.427Z"></path>
</svg>
</button><tool-tip id="tooltip-05cec74d-3d40-4776-b84d-ae5a0048dd66" for="icon-button-122e1418-b6e2-4cf7-840f-ed34bea9037c" popover="manual" data-direction="s" data-type="label" data-view-component="true" class="sr-only position-absolute" aria-hidden="true" role="tooltip">Toggle table of contents</tool-tip>

      <span>Pages <span title="1" data-view-component="true" class="Counter Counter--primary">1</span></span>
    </h3>
  </div>
  <div class=" js-wiki-sidebar-toggle-display">
    <div class="filter-bar">
      <input type="text" id="wiki-pages-filter" class="form-control input-sm input-block js-filterable-field" placeholder="Find a page…" aria-label="Find a page…" autocomplete="off">
    </div>

    <ul class="m-0 p-0 list-style-none" data-filterable-for="wiki-pages-filter" data-filterable-type="substring" data-pjax="">
        <li class="Box-row px-2 py-2">
          <details class="details-reset" open="">
  <summary>
    <div class="d-flex flex-items-start">
      <div class="p-2 mt-n1 mb-n1 ml-n1 btn btn-octicon js-wiki-sidebar-toc-toggle-chevron-button v-hidden">
        <span hidden="hidden" data-view-component="true">
  <svg style="box-sizing: content-box; color: var(--color-icon-primary);" width="16" height="16" viewBox="0 0 16 16" fill="none" aria-hidden="true" data-view-component="true" class="js-wiki-sidebar-toc-spinner mr-0 v-align-text-bottom anim-rotate">
    <circle cx="8" cy="8" r="7" stroke="currentColor" stroke-opacity="0.25" stroke-width="2" vector-effect="non-scaling-stroke" fill="none"></circle>
    <path d="M15 8a7.002 7.002 0 00-7-7" stroke="currentColor" stroke-width="2" stroke-linecap="round" vector-effect="non-scaling-stroke"></path>
</svg>    <span class="sr-only">Loading</span>
</span>
        <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-triangle-down js-wiki-sidebar-toc-toggle-chevron js-wiki-sidebar-toc-toggle-chevron-open mr-0">
    <path d="m4.427 7.427 3.396 3.396a.25.25 0 0 0 .354 0l3.396-3.396A.25.25 0 0 0 11.396 7H4.604a.25.25 0 0 0-.177.427Z"></path>
</svg>
      </div>
      <span data-view-component="true" class="Truncate">
    <a href="/MichalBien/LoraSimpleTransmitter/wiki" data-view-component="true" class="Truncate-text text-bold py-1">Home</a>
</span>    </div>
  </summary>

    
</details>

        </li>
    </ul>
  </div>
</div>

            </nav>

              <div class="mb-4">
                <a class="d-block p-3 Link--muted text-center border border-dashed rounded-2" href="/MichalBien/LoraSimpleTransmitter/wiki/_new?wiki%5Bname%5D=_Sidebar">
                  <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-plus mr-1">
    <path d="M7.75 2a.75.75 0 0 1 .75.75V7h4.25a.75.75 0 0 1 0 1.5H8.5v4.25a.75.75 0 0 1-1.5 0V8.5H2.75a.75.75 0 0 1 0-1.5H7V2.75A.75.75 0 0 1 7.75 2Z"></path>
</svg> Add a custom sidebar
</a>              </div>

            <h5 class="mt-0 mb-2">Clone this wiki locally</h5>
            <div class="width-full input-group">
              <input id="wiki-clone-url" type="text" data-autoselect="" class="form-control input-sm text-small color-fg-muted input-monospace" aria-label="Clone URL for this wiki" value="https://github.com/MichalBien/LoraSimpleTransmitter.wiki.git" readonly="">
              <span class="input-group-button">
                <span data-view-component="true">
  <clipboard-copy for="wiki-clone-url" aria-label="Copy to clipboard" type="button" data-view-component="true" class="rounded-left-0 border-left-0 Button--secondary Button--small Button" tabindex="0" role="button">
      <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-copy">
    <path d="M0 6.75C0 5.784.784 5 1.75 5h1.5a.75.75 0 0 1 0 1.5h-1.5a.25.25 0 0 0-.25.25v7.5c0 .138.112.25.25.25h7.5a.25.25 0 0 0 .25-.25v-1.5a.75.75 0 0 1 1.5 0v1.5A1.75 1.75 0 0 1 9.25 16h-7.5A1.75 1.75 0 0 1 0 14.25Z"></path><path d="M5 1.75C5 .784 5.784 0 6.75 0h7.5C15.216 0 16 .784 16 1.75v7.5A1.75 1.75 0 0 1 14.25 11h-7.5A1.75 1.75 0 0 1 5 9.25Zm1.75-.25a.25.25 0 0 0-.25.25v7.5c0 .138.112.25.25.25h7.5a.25.25 0 0 0 .25-.25v-7.5a.25.25 0 0 0-.25-.25Z"></path>
</svg>
      <svg style="display: none;" aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-check color-fg-success">
    <path d="M13.78 4.22a.75.75 0 0 1 0 1.06l-7.25 7.25a.75.75 0 0 1-1.06 0L2.22 9.28a.751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018L6 10.94l6.72-6.72a.75.75 0 0 1 1.06 0Z"></path>
</svg>
</clipboard-copy>  <div aria-live="polite" aria-atomic="true" class="sr-only" data-clipboard-copy-feedback=""></div>
</span>

              </span>
            </div>
          </div>
</div>
  
</div>    </div>
