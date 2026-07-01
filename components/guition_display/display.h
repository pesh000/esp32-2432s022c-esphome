#pragma once

#include "esphome/core/component.h"
#include <LovyanGFX.hpp>

namespace esphome {
namespace guition_display {

class GuitionDisplay : public PollingComponent {
 public:
  void setup() override;
  void update() override;

 protected:
  LGFX tft;
};

}  // namespace guition_display
}  // namespace esphome
