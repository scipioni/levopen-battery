#pragma once

#define CONFIG_BT_NIMBLE_PINNED_TO_CORE

#include <NimBLEDevice.h>
#include "led.h"

static NimBLEServer *pServer;

void ble_setup();