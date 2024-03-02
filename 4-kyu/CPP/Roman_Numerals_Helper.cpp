/* Write two functions that convert a roman numeral to and from an integer value. 
Multiple roman numeral values will be tested for each function.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit 
and skipping any digit with a value of zero. In Roman numerals:
1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC
2008 is written as 2000=MM, 8=VIII; or MMVIII
1666 uses each Roman symbol in descending order: MDCLXVI.

Input range : 1 <= n < 4000

In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").

Examples
to roman:
2000 -> "MM"
1666 -> "MDCLXVI"
  86 -> "LXXXVI"
   1 -> "I"

from roman:
"MM"      -> 2000
"MDCLXVI" -> 1666
"LXXXVI"  ->   86
"I"       ->    1 */

#include <string>
#include <map>

class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      std::string result;
      for (auto it = intToRomanMap.rbegin(); it != intToRomanMap.rend(); ++it) {
          while (n >= it->first) {
              result += it->second;
              n -= it->first;
          }
      }
      return result;
    }
  
    int from_roman(std::string rn){
      int result = 0;
      int prevValue = 0;

    for (char c : rn) {
      int value = symbolValueMap[c];
      result += value;
      if (value > prevValue) {
          result -= 2 * prevValue;
      }
      prevValue = value;
    }

      return result;
    }
  
  private:
    std::unordered_map<char, int> symbolValueMap = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
  
    std::map<unsigned int, std::string> intToRomanMap = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
};