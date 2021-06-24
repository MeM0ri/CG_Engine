#include "MeMoriTimer.h"

using namespace std::chrono;

MeMoriTimer::MeMoriTimer()
{
	last = steady_clock::now();
}

float MeMoriTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float MeMoriTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}