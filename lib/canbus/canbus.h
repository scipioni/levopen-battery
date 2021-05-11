#pragma once

#include <ESP32CAN.h>
#include <CAN_config.h>

#define CANBUS_GND_PIN 22
#define CANBUS_TX_PIN 19
#define CANBUS_RX_PIN 23
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