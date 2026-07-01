#include "display.h"
#include "esphome/core/log.h"

#include <LovyanGFX.hpp>

namespace esphome {
namespace guition_display {

static const char *TAG = "guition_display";

// ----------------------------
// LovyanGFX I80 CONFIG
// ----------------------------
class LGFX : public lgfx::LGFX_Device {
 public:
  LGFX() {

    static lgfx::Panel_ST7789 panel;
    static lgfx::Bus_Parallel8 bus;

    auto cfg = bus.config();

    cfg.pin_wr = 4;
    cfg.pin_rd = 2;
    cfg.pin_rs = 16;

    cfg.pin_d0 = 15;
    cfg.pin_d1 = 13;
    cfg.pin_d2 = 12;
    cfg.pin_d3 = 14;
    cfg.pin_d4 = 27;
    cfg.pin_d5 = 25;
    cfg.pin_d6 = 33;
    cfg.pin_d7 = 32;

    cfg.freq_write = 20000000;

    bus.config(cfg);
    panel.setBus(&bus);

    auto pcfg = panel.config();

    pcfg.pin_cs = -1;
    pcfg.pin_rst = 5;

    pcfg.panel_width = 240;
    pcfg.panel_height = 320;

    panel.config(pcfg);
    setPanel(&panel);
  }
};

// global display instance
static LGFX tft;

// ----------------------------

void GuitionDisplay::setup() {
  ESP_LOGI(TAG, "Initializing GUITION I80 display");

  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("ESPHome GUITION READY", 10, 10);
}

void GuitionDisplay::update() {
  this->do_update_();
}

// ESPHome calls this to draw
void GuitionDisplay::draw_display(display::DisplayBuffer *display) {
  // copy ESPHome buffer to real LCD if needed
  // (we start simple first)

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("UPDATE", 10, 40);
}

}  // namespace guition_display
}  // namespace esphome
