/* n this example you have to validate if a user input string is alphanumeric. 
The given string is not nil/null/NULL/None, so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces / underscore */

#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool alphanumeric(const char* strin) {
  for (int i = 0; strin[i]; i++)
  {
    if (!isalnum(strin[i]))
      return false;
  }
  if (strlen(strin) == 0)
    return false;
  return true;
}
