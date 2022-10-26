/*  Define a function that takes in two non-negative integers 
a and b and returns the last decimal digit of a^b.

Note that a and b may be very large!

Examples

last_digit("4", "1")            //returns 4
last_digit("4", "2")            // returns 6
last_digit("9", "7")            // returns 9
last_digit("10","10000000000")  // returns 0 */

#include <string.h>

int last_digit(const char *a, const char *b)
{
  int len_a = strlen(a);
  int len_b = strlen(b);  
  int dig = a[len_a - 1] -'0';
  int pow_s = b[len_b - 1] - '0';
  int pow_d;
  (len_b == 1) ? (pow_d = pow_s) : (pow_d = (b[len_b - 2] - '0') * 10 + pow_s);
  if (len_b == 1)
  {
    if (b[0] == '0')
      return 1;
  }
  if (dig == 0 || dig == 1 || dig == 5 || dig == 6)
    return dig;
  else if (dig == 4 || dig == 9)
  {
    if (pow_s % 2 == 1)
      return dig;
    else
      return dig == 4 ? 6 : 1;
  }
  if (pow_d % 4 == 0)
  {
    if (dig % 2 == 0)
      return 6;
    else
      return 1;
  }
  else if (pow_d % 4 == 1)
    return dig;
  else if (pow_d % 4 == 2)
    return (dig * dig) % 10;
  else if (pow_d % 4 == 3)
    return (dig * dig * dig) % 10;
  return 0;
}