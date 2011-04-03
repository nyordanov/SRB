#include "srb.h"

#ifndef SRB_MATH_H_
#define SRB_MATH_H_

int min(int val1, int val2);
int max(int val1, int val2);
int abs(int val);
int constrain(int val, int low, int high);
long map(long x, long in_min, long in_max, long out_min, long out_max);

#endif
