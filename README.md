# arduino-hid-keyboard

Uses the second microcontroller on an Arduino UNO to emulate a USB keyboard.

## How to use

1. Flash keyboard.hex on the second microcontroller (16u2) of the Arduino UNO using a ISP programmer.
2. Flash main.elf to the Arduino UNO using an ISP programmer (you can no longer use USB to program)
3. Plug the Arduino in using USB, after a few seconds, it should type "Hello World!"

To reset the second microcontroller, flash optiboot_atmega328.hex
