#include "application.h"
#include "button.h"
#include "codecs/no_audio_codec.h"
#include "config.h"
#include "wifi_board.h"

class YoloUnoBoard : public WifiBoard {
private:
    Button boot_button_{BOOT_BUTTON_GPIO};

public:
    YoloUnoBoard() {
        boot_button_.OnClick([]() {
            Application::GetInstance().Schedule(
                []() { Application::GetInstance().ToggleChatState(); });
        });
        boot_button_.OnLongPress(
            [this]() { Application::GetInstance().Schedule([this]() { EnterWifiConfigMode(); }); });
    }

    AudioCodec* GetAudioCodec() override {
        static NoAudioCodecDuplex audio_codec(AUDIO_INPUT_SAMPLE_RATE, AUDIO_OUTPUT_SAMPLE_RATE,
                                              AUDIO_I2S_GPIO_BCLK, AUDIO_I2S_GPIO_WS,
                                              AUDIO_I2S_GPIO_DOUT, AUDIO_I2S_GPIO_DIN);
        return &audio_codec;
    }
};

DECLARE_BOARD(YoloUnoBoard);
