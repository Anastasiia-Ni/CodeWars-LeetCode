/* Given the string representations of two integers, return 
the string representation of the sum of those integers.

For example:

sumStrings('1','2') // => '3'
A string representation of an integer will contain no characters 
besides the ten numerals "0" to "9". */

#include <string.h>
#include <stdlib.h>

char *strsum(const char *a, const char *b)
{
   char digA, digB;

   size_t len_a = strlen(a);
   size_t len_b = strlen(b);
   size_t size = (len_a > len_b) ? len_a + 2 : len_b + 2;
  
   char* number = (char*) malloc(size * sizeof(char));
   number[size - 1] = 0;
  
   char* an = a + len_a - 1;
   char* bn = b + len_b - 1;
   char* cn = number + size - 2;
   char one = 0;
 
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
