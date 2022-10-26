/* The maximum sum subarray problem consists in finding the maximum sum 
of a contiguous subsequence in an array or list of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9)
// should return 6, from sub-array: {4, -1, 2, 1}

Easy case is when the list is made up of only positive numbers and 
the maximum sum is the sum of the whole array. 
If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array 
is also a valid sublist/subarray. */

#include <stddef.h>

int maxSequence(const int* array, size_t n) {

  if (n == 0)
    return 0;
  int max_s = array[0], poz_l = 0, poz_r = 0, sum = 0, minus_pos = -1;
  for (size_t i = 0; i < n; ++i) 
  {
    sum += array[i];
    if (sum > max_s) 
    {
      max_s = sum;
      poz_l = minus_pos + 1;
      poz_r = i;
    }
    if (sum < 0) 
    {
      sum = 0;
      minus_pos = i;
    }
   }
   return max_s >= 0 ? max_s : 0;
}
