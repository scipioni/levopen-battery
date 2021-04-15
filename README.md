# levopen-battery
turbo levo battery open


A UUID is a 128-bit value that are written in groups 0f 8-4-4-4-12

The official Bluetooth base UUID is: 0000xxxx-0000-1000-8000-00805F9B34FB and the 16-bit value replaces the x's.

```

Service 00001800-0000-1000-8000-00805f9b34fb
Characteristics:
    00002a00-0000-1000-8000-00805f9b34fb: Readable, Writable
        value: 53 50 45 43 49 41 4C 49 5A 45 44
    00002a01-0000-1000-8000-00805f9b34fb: Readable
        value: 00 00
    00002a04-0000-1000-8000-00805f9b34fb: Readable
        value: 18 00 20 00 00 00 90 01

Service 00001801-0000-1000-8000-00805f9b34fb
Characteristics:


Service 0000180a-0000-1000-8000-00805f9b34fb
Characteristics:
|--00002a29-0000-1000-8000-00805f9b34fb: Readable
 characteristic 00002a29-0000-1000-8000-00805f9b34fb | value: 53 50 45 43 49 41 4C 49 5A 45 44
|--00002a28-0000-1000-8000-00805f9b34fb: Readable
 characteristic 00002a28-0000-1000-8000-00805f9b34fb | value: 56 31 2E 37 2E 30

Service 00001816-0000-1000-8000-00805f9b34fb
Characteristics:
|--00002a5b-0000-1000-8000-00805f9b34fb: Notify
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>
 (ogni 200ms) characteristic 00002a5b-0000-1000-8000-00805f9b34fb changed | value: 03 0C 00 00 00 0B 00 0C 00 63 00
|--00002a5c-0000-1000-8000-00805f9b34fb: Readable
 characteristic 00002a5c-0000-1000-8000-00805f9b34fb | value: 03 00
|--00002a55-0000-1000-8000-00805f9b34fb: Writable, Indicate
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>

Service 00000001-0000-4b49-4e4f-525441474947
Characteristics:
    00000011-0000-4b49-4e4f-525441474947: Readable
        value: 01 08 00 00 00 00 FF FF FF FF FF FF FF FF FF FF FF FF FF FF
    00000021-0000-4b49-4e4f-525441474947: Writable

Service 00000002-0000-4b49-4e4f-525441474947
Characteristics:
|--00000012-0000-4b49-4e4f-525441474947: Writable

Service 00000003-0000-4b49-4e4f-525441474947
Characteristics:
|--00000013-0000-4b49-4e4f-525441474947: Readable, Notify
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>

```