/* Your task in order to complete this Kata is to write a function 
which formats a duration, given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. 
If it is zero, it just returns "now". 
Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

* For seconds = 62, your function should return 
    "1 minute and 2 seconds"
* For seconds = 3662, your function should return
    "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules
The resulting expression is made of components like 4 seconds, 1 year, etc. 
In general, a positive integer and one of the valid units of time, separated by a space. 
The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). 
Except the last component, which is separated by " and ", 
just like it would be written in English.

A more significant units of time will occur before than a least significant one. 
Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. 
So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. 
Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". 
It means that the function should not return 61 seconds, but 1 minute and 1 second instead. 
Formally, the duration specified by of a component must not be greater than 
any valid more significant unit of time. */

#include <stdlib.h>

#define MIN 60
#define HOUR (MIN * 60)
#define DAY (HOUR * 24)
#define YEAR (DAY * 365)

#define sep1 (count == 0 ? "" : (n != 0 ? ", " : " and "))
#define s (data != 1 ? "s" : "")

char *formatDuration (int n) 
{
  char *arr = calloc(200, sizeof(char));
  int data, count = 0;
  if (n == 0)
  {
    asprintf(&arr, "now");
    return arr;
  }
  if (n >= YEAR)
  {
    data = n / YEAR;
    n %= YEAR;
    asprintf(&arr, "%d year%s", data, s);
    count++;
  }
  if (n >= DAY)
  {
    data = n / DAY;
    n %= DAY;
    asprintf(&arr, "%s%s%d day%s", arr, sep1, data, s);
    count++;
  }
  if (n >= HOUR)
  {
    data = n / HOUR;
    n %= HOUR;
    asprintf(&arr, "%s%s%d hour%s", arr, sep1, data, s);
    count++;
  }
  if (n >= MIN)
  {
    data = n / MIN;
    n %= MIN;
    asprintf(&arr, "%s%s%d minute%s", arr, sep1, data, s);
    count++;
  }
  if (n >= 1)
  {
    data = n;
    n -= data;
    asprintf(&arr, "%s%s%d second%s", arr, sep1, data, s);
  }   
  return arr;
}
