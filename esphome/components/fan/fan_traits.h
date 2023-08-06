#pragma once

namespace esphome {
namespace fan {

class FanTraits {
 public:
  FanTraits() = default;
  FanTraits(bool oscillation, bool speed, bool direction, int speed_count)
      : oscillation_(oscillation), speed_(speed), direction_(direction), speed_count_(speed_count) {}

  /// Return if this fan supports oscillation.
  bool supports_oscillation() const { return this->oscillation_; }
  /// Set whether this fan supports oscillation.
  void set_oscillation(bool oscillation) { this->oscillation_ = oscillation; }
  /// Return if this fan supports speed modes.
  bool supports_speed() const { return this->speed_; }
  /// Set whether this fan supports speed levels.
  void set_speed(bool speed) { this->speed_ = speed; }
  /// Return how many speed levels the fan has
  int supported_speed_count() const { return this->speed_count_; }
  /// Set how many speed levels this fan has.
  void set_supported_speed_count(int speed_count) { this->speed_count_ = speed_count; }
  /// Return if this fan supports changing direction
  bool supports_direction() const { return this->direction_; }
  /// Set whether this fan supports changing direction
  void set_direction(bool direction) { this->direction_ = direction; }

  void add_supported_custom_preset(const std::string &preset) { supported_custom_presets_.insert(preset); }
  void set_supported_custom_presets(std::set<std::string> supported_custom_presets) {
    supported_custom_presets_ = std::move(supported_custom_presets);
  }
  const std::set<std::string> &get_supported_custom_presets() const { return supported_custom_presets_; }
  bool supports_custom_preset(const std::string &custom_preset) const {
    return supported_custom_presets_.count(custom_preset);
  }

 protected:
  bool oscillation_{false};
  bool speed_{false};
  bool direction_{false};
  int speed_count_{};

  std::set<std::string> supported_custom_presets_;
};

}  // namespace fan
}  // namespace esphome
