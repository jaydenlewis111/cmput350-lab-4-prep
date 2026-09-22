#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdint>

class Timer {
public:
	using Nanos = std::chrono::nanoseconds;
	using Micros = std::chrono::microseconds;
	using Millis = std::chrono::milliseconds;
	using Seconds = std::chrono::seconds;
	using Minutes = std::chrono::minutes;
	using Hours = std::chrono::hours;

	Timer() : start_(Clock::now()) {}

	void restart() {
		start_ = Clock::now();
	}

	template <typename T>
	uint64_t click() {
		const auto elapsed = std::chrono::duration_cast<T>(Clock::now() - start_);
		restart();
		return static_cast<uint64_t>(elapsed.count());
	}

	template <typename T>
	uint64_t glance() const {
		const auto elapsed = std::chrono::duration_cast<T>(Clock::now() - start_);
		return static_cast<uint64_t>(elapsed.count());
	}

private:
	using Clock = std::chrono::steady_clock;
	Clock::time_point start_;
};

#endif  // TIMER_H
