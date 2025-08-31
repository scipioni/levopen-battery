all:
	pio run -e esp32doit-devkit-v1

compile:
	pio run -e esp32doit-devkit-v1

flash:
	pio run -e esp32doit-devkit-v1 -t upload

compile-and-flash:
	pio run -e esp32doit-devkit-v1 -t upload

monitor:
	pio device monitor -b 115200

clean:
	pio run -e esp32doit-devkit-v1 -t clean
