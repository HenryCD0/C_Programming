

#include "hw3.h"

double integrate1(Range rng)
{
  double Low_Bound = rng.lowerlimit;
  double Up_Bound = rng.upperlimit;
  double n_Int = rng.intervals;
  
  double Sum = func(Low_Bound);
  double Start = (Up_Bound - Low_Bound) / n_Int;

  for(int i = 0; i < n_Int - 1; i++) {
    Sum += func(Low_Bound + (i + 1) * (Up_Bound - Low_Bound) / n_Int);
  }
  /* Fill in for Part 1 */
  // calculate the numerical integration of the function func
  // based on the three attributes (`lowerlimit`, `upperlimit`, and `intervals`) of the type `Range`.
  // the return value of function `integrate1` should be the numerical integration (return type is double)  
  return(Start * Sum);
}

void integrate2(RangeAnswer * rngans)
{
  rngans -> answer = integrate1(rngans -> rng);
  /* Fill in for Part 2 */
  // run `integrate1` function
  // take the return value from `integrate1` function 
  // and assign it to attribute `answer` of the type `RangeAnswer`
 
}
