#pragma once

#include <ESP32CAN.h>
#include <CAN_config.h>

#define CANBUS_ENABLE 1
//#define CANBUS_GND_PIN 23 // 22 //16
#define CANBUS_TX_PIN 17 //23 //19 //4
#define CANBUS_RX_PIN 16 //19 // 23 //0
//#define CANBUS_POWER_PIN 17

#ifdef BOARD_DOIT
#define CANBUS_TX_PIN 17
#define CANBUS_RX_PIN 16
#endif


#define LOG_TAG "canbus"

typedef struct TX_FRAME
{
    int interval;
    uint32_t last;
    int buzzer;
    CAN_frame_t message;
} TX_FRAME;

typedef struct PLEVELS
{
    int mean;
    int max;
    int code;
    int buzzer;
} PLEVELS;

typedef struct SETTINGS
{
    bool running;
    bool motor_is_alive;
    int initial_assistance;
} SETTINGS;

void canbus_setup();