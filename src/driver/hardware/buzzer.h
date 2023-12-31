#pragma once

// C++
#include <cstdint>
#include <memory>

// ESP-IDF
#include <freertos/FreeRTOS.h>
#include <hal/gpio_types.h>

// Project
#include "base.h"

namespace driver::hardware {
class Buzzer final : public DriverBase {
 public:
  enum class Mode {
    None [[maybe_unused]],               // 無音
    InitializeFailed [[maybe_unused]],   // 初期化失敗
    InitializeSuccess [[maybe_unused]],  // 初期化成功
    Searching [[maybe_unused]],          // 迷路探索中(ループ再生)
    SearchWarning [[maybe_unused]],      // 迷路探索中警告
    SearchFailed [[maybe_unused]],       // 迷路探索失敗
    SearchSuccess [[maybe_unused]],      // 迷路探索成功
    FastFailed [[maybe_unused]],         // 最短走行失敗
    FastSuccess [[maybe_unused]],        // 最短走行成功
    StartRunning [[maybe_unused]],       // 走行開始
    EndRunning [[maybe_unused]],         // 走行終了
    LowBattery [[maybe_unused]],         // バッテリー切れ
    Select [[maybe_unused]],             // モード選択
    Ok [[maybe_unused]],                 // 確定
    Cancel [[maybe_unused]],             // キャンセル
  };

 public:
  explicit Buzzer(gpio_num_t buzzer_num);
  ~Buzzer();

  bool update() override;
  void set(Mode mode, bool loop);

 private:
  class BuzzerImpl;
  std::unique_ptr<BuzzerImpl> impl_;
};
}  // namespace driver::hardware
