#ifndef TIMER_H
#define TIMER_H
#include <windows.h>
class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
	LARGE_INTEGER freq;
	double PCFreq; 
__int64 CounterStart; 

public:
	Timer();
	void startTimer();
	void stopTimer();
	double getMilli();
	double getSeconds();
	double getMicro();

};
#endif