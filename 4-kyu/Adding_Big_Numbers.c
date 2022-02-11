/* We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. 
The input numbers are strings and the function must return a string.

Example

add("123", "321"); -> "444"
add("11", "99");   -> "110"
Notes

The input numbers are big.
The input is a string of only digits
The numbers are positives */

#include <string.h>
#include <stdlib.h>

char *add(const char *a, const char *b) {
  size_t len_a = strlen(a);
  size_t len_b = strlen(b);
  size_t size = (len_a > len_b) ? len_a + 2 : len_b + 2;
  
  char *number = calloc(size, sizeof(char));
  
  char *an = a + len_a - 1;
  char *bn = b + len_b - 1;
  char *cn = number + size - 2;
  char one = 0;  
  char digA, digB;
 
  for (; (a <= an) || (b <= bn); --an, --bn, --cn)
  {
     digA = (a <= an) ? (*an - '0') : 0;
     digB = (b <= bn) ? (*bn - '0') : 0;
     *cn = ((digA + digB + one) % 10) + '0';
     one = (digA + digB + one) / 10;
  }
  
  if (one)
     *cn = '1';
  else
     memmove(number, number + 1, size - 1); 
  
  while (number[0] == '0' && strlen(number) > 1)
     memmove(number, number + 1, size - 1);
  
  return number;
}
