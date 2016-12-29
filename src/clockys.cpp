#include "clockys/clockys.h"
#include <chrono>
#include <iostream>

#if USE_GLOG
	#include <glog/logging.h>
	#define PRINT_OUT LOG(INFO)
#else
	#define PRINT_OUT std::cout
#endif

using namespace std::chrono;

namespace clockys {
Timer::Timer()
{
	very_begin_ = ms_since_epoch();
	last_round_ = very_begin_;
}

Timer::~Timer()
{
	PRINT_OUT << double((ms_since_epoch() - very_begin_))*0.001 << " sec elapsed.";
}

double Timer::elapse()
{
	return (ms_since_epoch() - very_begin_)*0.001;
}

double Timer::round()
{
	uint64_t now = ms_since_epoch();
	uint64_t t_round = now - last_round_;
	last_round_ = now;
	return t_round*0.001;
}

uint64_t Timer::ms_since_epoch()
{
	return (system_clock::now().time_since_epoch()).count() * system_clock::period::num * 1000 / system_clock::period::den;
}

} //@end of namespace closkys

