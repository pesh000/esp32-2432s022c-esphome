#include "display.h"
#include "esphome/core/log.h"

namespace esphome {
namespace guition_display {

static const char *TAG = "guition_display";

void GuitionDisplay::setup() {
  ESP_LOGI(TAG, "Starting GUITION I80 display");

  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("ESPHome GUITION OK", 10, 10);
}

void GuitionDisplay::update() {
  // later: Home Assistant data here
}

}  // namespace guition_display
}  // namespace esphome
