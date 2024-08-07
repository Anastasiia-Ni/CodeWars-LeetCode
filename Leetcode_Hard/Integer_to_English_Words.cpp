/* Convert a non-negative integer num to its English words representation.

Example 1:
Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 
Constraints:
0 <= num <= 2**31 - 1 */


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    const std::vector<std::string> numbers = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
    const vector<string> tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    const vector<string> order_words = {
        "",
        "Thousand",
        "Million",
        "Billion" };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string res = writeNumber(num, 0, false);
        return trim(res);
    }

    string writeNumber(int num, int order, bool is_add) {
        if (num == 0) {
            return "";
        }

        int tmp = num % 1000;
        string res = "";
        if (tmp < 20) {
            res += numbers.at(tmp);
        }
        else if (tmp < 100) {
            res += tens.at(tmp / 10) + " " + numbers.at(tmp % 10);
        }
        else {
            res += numbers.at(tmp / 100) + " Hundred " + writeNumber(tmp % 100, order, true);
        }
        if (tmp != 0 && !is_add)
            res += " " + order_words.at(order) + " ";
        return writeNumber(num / 1000, ++order, false) + res;
    }

    string trim(const string &res) {
        string str = "";
        bool is_s = true;

        for (const char &c : res) {
            if (isspace(c)) {
                if (!is_s) {
                    str += c;
                    is_s = true;
                }
            }
            else {
                str += c;
                is_s = false;
            }
        }
        while (str.back() == ' ') {
            str.pop_back();
        }
        return str;
    }
};
