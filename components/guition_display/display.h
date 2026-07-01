#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"

namespace esphome {
namespace guition_display {

class GuitionDisplay : public PollingComponent, public display::DisplayBuffer {
 public:
  void setup() override;
  void update() override;

 protected:
  void draw_display(display::DisplayBuffer *display) override;
};

}  // namespace guition_display
}  // namespace esphome
