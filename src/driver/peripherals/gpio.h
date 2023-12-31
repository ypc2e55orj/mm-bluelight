#pragma once

// C++
#include <memory>

// ESP-IDF
#include <hal/gpio_types.h>

namespace driver::peripherals {
class Gpio {
 private:
  class GpioImpl;
  std::unique_ptr<GpioImpl> impl_;

 public:
  explicit Gpio(gpio_num_t num, gpio_mode_t mode, bool enable_pullup,
                bool enable_pulldown);
  ~Gpio();

  bool set(bool level);
  bool get();
};
}  // namespace driver::peripherals
