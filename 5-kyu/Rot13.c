/* ROT13 is a simple letter substitution cipher that replaces a letter 
with the letter 13 letters after it in the alphabet. 
ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. 
If there are numbers or special characters included in the string, 
they should be returned as they are. Only letters from the latin/english alphabet should be shifted, 
like in the original Rot13 "implementation". */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *rot13(const char *src)
{
  int len = strlen(src);
  char *arr = (char *)malloc(len + 1);
  for (int i = 0; i < len; i++)
  {
    if (isupper(src[i]))
      arr[i] = (src[i] - 52) % 26 + 65;      
    else if (islower(src[i]))
      arr[i] = (src[i] - 84) % 26 + 97;
    else
      arr[i] = src[i];
  }
  arr[len] = '\0';
  return arr;
}
