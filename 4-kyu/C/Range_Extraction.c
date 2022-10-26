/* A format for expressing an ordered list of integers is to use 
a comma separated list of either

individual integers
or a range of integers denoted by the starting integer separated 
from the end integer in the range by a dash, '-'. 
The range includes all integers in the interval including both endpoints. 
It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"
Complete the solution so that it takes a list of integers in increasing order 
and returns a correctly formatted string in the range format.

Example:

range_extraction({-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
// returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20" */

#include <stdlib.h>
#include <stdio.h>

#define sep (j != n - 1 ? "," : "")

char *range_extraction(const int *args, size_t n)
{
  char *arr = calloc(n * 4, sizeof(char));
  for (size_t i = 0, j = 0; i < n; j++, i = j) 
  {
    while ((j < n - 1) && (args[j + 1] == args[j] + 1))
      j++;
    if (i != j && i + 1 != j)
      asprintf(&arr, "%s%d-%d%s", arr, args[i], args[j], sep);
    else if  (i + 1 == j)
      asprintf(&arr, "%s%d,%d%s", arr, args[i], args[j], sep);
    else
      asprintf(&arr, "%s%d%s", arr, args[i], sep);
  }
  return arr;
}