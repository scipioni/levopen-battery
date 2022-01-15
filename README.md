# levopen-battery

turbo levo open battery with:
- custom latch power circuit
- firmware on esp32 that take care of motor via canbus



change BATTERY_K in bike.h with:
- measured mV on battery
- mean_pin printed on serial monitor
```
#define BATTERY_K 40600 / 195
```

