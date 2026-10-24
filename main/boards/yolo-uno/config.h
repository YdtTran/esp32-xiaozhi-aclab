#ifndef YOLO_UNO_CONFIG_H
#define YOLO_UNO_CONFIG_H

#include <driver/gpio.h>

// Duplex I2S shares one clock, so capture and playback use the same rate.
#define AUDIO_INPUT_SAMPLE_RATE 24000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_WS GPIO_NUM_6
#define AUDIO_I2S_GPIO_DIN GPIO_NUM_7
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_8
#define BOOT_BUTTON_GPIO GPIO_NUM_0

#endif
