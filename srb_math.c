#include "srb_math.h"

// min
int min(int val1, int val2) {
	return (val1 < val2) ? val1 : val2;
}

// max
int max(int val1, int val2) {
	return (val1 > val2) ? val1 : val2;
}

// abs
int abs(int val) {
  return (val < 0) ? -val : val;
}

// constrain
int constrain(int val, int low, int high) {
  if(val > high) {
	return high;
  }
  if (val < low) {
	return low;
  }
  return val;
}

// map
// from Arduino.cc
long map(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
