
#include <stdio.h>
#include <stdbool.h>
#include "hw4.h"

// must enclose the function by #ifdef TEST_INTEGRATE and #endif
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  double Low_Bound = intrg->lowerlimit;
  double Up_Bound = intrg->upperlimit;
  double n_Int = intrg->intervals;
  
  double Sum = intrg->func(Low_Bound);
  double Start = (Up_Bound - Low_Bound) / n_Int;

  for(int i = 0; i < n_Int - 1; i++) {
    Sum += intrg->func(Low_Bound + (i + 1) * (Up_Bound - Low_Bound) / n_Int);
  }
  
  intrg->answer = (Sum * Start);

  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE and #endif
#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  Integration intrg;
  // open the input file name for reading
  FILE *in = fopen(infilename, "r");
  if(in == NULL) return(false);

  // if fopen fails, return false

  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
    
  if(fscanf(in, "%lf", &intrg.lowerlimit) != 1) {
    fclose(in);
    return (false);
  }

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  if(fscanf(in, "%lf", &intrg.upperlimit) != 1) {
     fclose(in);
     return (false);
  }

  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  if(fscanf(in, "%d", &intrg.intervals) != 1) {
    fclose(in);
    return (false);
  }

  // close the input file
  
  fclose(in);

  // open the output file for writing
  // if fopen fails, return false
  FILE *out = fopen(outfilename, "w");
  if(out == NULL) return(false);

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  funcptr funcs[5] = {func1, func2, func3, func4, func5};

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
  for(int i = 0; i < 5; i++) {
    intrg.func = funcs[i];
    integrate(&intrg);
    int value = fprintf(out, "%lf\n", intrg.answer);
  

  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false
    if(value < 1) {
      fclose(out);
      return (false);
    }

  // after going through all functions in funcs
  // close the output file

  }

  fclose(out);

  // if the function reaches here, return true
  return (true);

}
#endif // RUN_INTEGRATE
