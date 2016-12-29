#ifndef __CLOCKYS_H__
#define __CLOCKYS_H_

#include <stdint.h>

namespace clockys {
class Timer {
public:
    Timer();
    ~Timer();
    double elapse();
    double round();
    uint64_t ms_since_epoch(void);
private:
	uint64_t very_begin_;
	uint64_t last_round_;
};
} //@end namespace clockys

#endif
