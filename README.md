# levopen-battery

turbo levo open battery with:
- custom latch power circuit
- firmware on esp32 that take care of motor via canbus

## Prereq

on arch linux
```
yay -S platformio-core-udev platformio-core
```

## Compilation and Flashing

To compile and flash the firmware to an ESP32 (esp32doit-devkit-v1), you can use the provided Makefile commands:

```bash
# Compile the project
make compile

# Flash the firmware to the ESP32
make flash

# Compile and flash in one command
make compile-and-flash

# Clean build files
make clean

# Monitor serial output
make monitor
```

## Calibration

change BATTERY_K in bike.h with:
- measured mV on battery
- mean_pin printed on serial monitor
```
#define BATTERY_K 40600 / 195
```

