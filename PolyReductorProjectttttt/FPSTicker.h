/*
Class of FPS clocker.
*/

#ifndef FPS_TICKER_H
#define FPS_TICKER_H

#include <chrono>

class FPSTicker
{
public:
	void start()
	{
		prevoriusTime = std::chrono::high_resolution_clock::now();
		actualFps = 100;
		delta = 0;
		returnDelta = 0;
	}//measure first time to calculate FPS and deltatime
	float getDt()
	{
		return delta;
	}//get delta time between prevorius and actual timestamp's
	float getFPSValue()
	{
		using namespace std::chrono;
		auto actualTime = std::chrono::high_resolution_clock::now();
		delta = duration_cast<duration<double>>(actualTime - prevoriusTime).count();
		counter++;
		if (delta > 0.1)
		{
			actualFps = counter / delta;
			//prevoriusTime = actualTime;
			counter = 0;
		}
		return actualFps;
	}//get FPS. it's refreshed for 0.1s
private:
	std::chrono::high_resolution_clock::time_point prevoriusTime;// = std::chrono::high_resolution_clock::now();
	float actualFps;
	int counter;
	float delta;//actual delta time for calculate FPS
	float returnDelta;//real delta time
};

#endif // !FPS_TICKER_H
