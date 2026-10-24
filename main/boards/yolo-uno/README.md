# YOLO UNO with INMP441 and MAX98357A

Target: ESP32-S3, 16 MB quad flash, 8 MB octal PSRAM. Uses the project's
16 MB partition layout. Firmware and OTA identity: `yolo-uno`.

| Signal | YOLO UNO | INMP441 | MAX98357A |
| --- | --- | --- | --- |
| Microphone power | 3V3 | VDD | |
| Amplifier power | 5V | | VIN |
| Ground | GND | GND and LR | GND |
| Shared BCLK | GPIO5 (D2) | SCK | BCLK |
| Shared WS | GPIO6 (D3) | WS | LRC |
| Microphone data | GPIO7 (D4) | SD | |
| Speaker data | GPIO8 (D5) | | DIN |

Connect the speaker only between amplifier OUT+ and OUT-. Keep INMP441 power
at 3.3 V. LR grounded selects the left microphone slot used by the codec.
Shared clocks require duplex I2S; both directions run at 24 kHz and the audio
service resamples microphone input to 16 kHz. No display or LED is configured.

Click BOOT to toggle chat; hold BOOT to enter Wi-Fi configuration mode.
On first boot without saved credentials, use the firmware's Wi-Fi setup portal.

In an activated ESP-IDF v6.1 environment:

```powershell
python scripts/build.py yolo-uno --name yolo-uno
idf.py -p COM17 flash
idf.py -p COM17 monitor
```

Recheck the serial port before flashing. Test microphone capture, speaker
playback, wake word, interruption, and Wi-Fi reconnect on physical hardware.
