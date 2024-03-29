#include "run.h"

// コンストラクタ
Run::Run(Motion *motion) : motion_(motion) {}
// デストラクタ
Run::~Run() = default;

// 走行
void Run::straight(float length, float acceleration, float max_velocity, float end_velocity) {
  MotionParameter param{};

  param.pattern = MotionPattern::Straight;
  param.acceleration = acceleration;
  param.min_velocity = VELOCITY_MIN;
  param.max_velocity = max_velocity;
  param.end_velocity = end_velocity;
  param.max_length = length;
  param.enable_side_wall_adjust = false;

  motion_->getParameterQueue().overwrite(&param);
  // 完了まで待つ
  motion_->wait();
}
void Run::turn(float degree, float angular_acceleration, float max_angular_velocity, MotionTurnDirection dir) {
  MotionParameter param{};

  param.pattern = MotionPattern::Turn;
  param.direction = dir;
  param.angular_acceleration = angular_acceleration;
  param.min_angular_velocity = ANGULAR_VELOCITY_MIN;
  param.max_angular_velocity = max_angular_velocity;
  param.max_angle = degree;

  motion_->getParameterQueue().overwrite(&param);
  // 完了まで待つ
  motion_->wait();
}
