#include "clockys/clockys.h"
#include <glog/logging.h>
#include <cmath>

int main(int argc, char **argv)
{
	google::InitGoogleLogging(argv[0]);
	FLAGS_alsologtostderr = 1;
	LOG(INFO) << "hello clockys.";
	clockys::Timer t;
	float b = 10.0;
	for (int i = 0; i < 100000; i++) {
		float sqrt_b = sqrt(b);
		sqrt_b = sqrt_b + 1.0;
	}
	return 0;
}

