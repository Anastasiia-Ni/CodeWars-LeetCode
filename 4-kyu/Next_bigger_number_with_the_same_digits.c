/* Create a function that takes a positive integer and 
returns the next bigger number that can be formed 
by rearranging its digits. For example:

12 ==> 21
513 ==> 531
2017 ==> 2071

nextBigger(num: 12)   // returns 21
nextBigger(num: 513)  // returns 531
nextBigger(num: 2017) // returns 2071

If the digits can't be rearranged to form a bigger number, r
eturn -1 (or nil in Swift):

9 ==> -1
111 ==> -1
531 ==> -1

nextBigger(num: 9)   // returns nil
nextBigger(num: 111) // returns nil
nextBigger(num: 531) // returns nil */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_sort(char *buf, int k)
{
  for(; buf[k]; k++)
  {
    int min = k;
    for (int j = k + 1; buf[j]; j++ )
    {
      if (buf[j] < buf[min])
        min = j;
    }
    int tmp = buf[k];
    buf[k] = buf[min];
    buf[min] = tmp;
  }
}

long long next_bigger_number(long long n) {

  char *buf;
  asprintf(&buf, "%lld", n);
  int len = strlen(buf);
  long long res;
  for (int i = len - 1; i > 0; i--)
  {
    if (buf[i] > buf[i - 1])
    {
      int small = i;
      for (int j = i + 1; buf[j]; j++)
      {
        if (buf[j] > buf[i - 1] && buf[j] < buf[small])
          small = j;
      }
      
      int tmp = buf[small];
      buf[small] = buf[i - 1];
      buf[i - 1] = tmp;
      my_sort(buf, i);
      res = atol(buf);
      return res;
    }
  }
  return -1;
}
