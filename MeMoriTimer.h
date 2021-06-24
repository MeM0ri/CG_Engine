#pragma once
#include <chrono>

class MeMoriTimer
{
public:
	MeMoriTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};