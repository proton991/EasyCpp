#ifndef EASYCPP_SIMPLE_TIMER_HPP
#define EASYCPP_SIMPLE_TIMER_HPP

#include <chrono>
class SimpleTimer {


public:
  SimpleTimer() {
    m_last_time = std::chrono::high_resolution_clock::now();
  }
  [[nodiscard]] float TimeStep() {
    const auto currentTime = std::chrono::high_resolution_clock::now();

    auto time_duration = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - m_last_time).count();

    m_last_time = currentTime;

    return time_duration;
  }
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_last_time;

};

#endif  //EASYCPP_SIMPLE_TIMER_HPP
