/* For each given a number N, the integer S is called integer square root of N if S x S <= N and (S+1) x (S+1) > N.
In other words, S = Math.floor(Math.sqrt(N))
Your task is to calculate the integer square root of a given Number.
Note: Input is given in string format. That is, the Number may be very very large ;-)

Example
For: Number = "4", result = "2".
For: Number = "17", result = "4".
For: Number = "101", result = "10".
For: Number = "23232328323215435345345345343458098856756556809400840980980980980809092343243243243243098799634", result = "152421548093487868711992623730429930751178496967".

Input/Output
[input] string Number
number in decimal form. 0 < Number < 10^100

[output] a string
integer squareroot of Number. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compareStrings(const string& s1, const string& s2) {
    if (s1.length() > s2.length()) return 1;
    if (s1.length() < s2.length()) return -1;
    return s1.compare(s2);
}

string multiplyStrings(const string& s1, const string& s2) {
    size_t n = s1.size();
    size_t m = s2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr;
    
    for (size_t i = 0; i < result.size(); ++i) {
        if (!(resultStr.empty() && result[i] == 0)) {
            resultStr.push_back(result[i] + '0');
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}

string addStrings(const string& s1, const string& s2) {
    int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += s1[i--] - '0';
        if (j >= 0) sum += s2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string divideByTwo(const string& num) {
    string result;
    int carry = 0;

    for (size_t i = 0; i < num.size(); ++i) {
        int current = carry * 10 + (num[i] - '0');
        result.push_back(current / 2 + '0');
        carry = current % 2;
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    
    return result;
}

string addOne(const string& num) {
    string result = num;
    int carry = 1;
    
    for (int i = result.size() - 1; i >= 0; --i) {
        int sum = (result[i] - '0') + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
        if (carry == 0) break;
    }
  
    if (carry) {
        result.insert(result.begin(), '1');
    }
    return result;
}

string subtractOne(const string& num) {
    string result = num;

    for (int i = result.size() - 1; i >= 0; --i) {
        if (result[i] == '0') {
            result[i] = '9';
        }
        else {
          result[i] -= 1;
          break;
        }
    }
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

string integer_square_root(string n) {
    string low = "0";
    string high = n;
    string res;
  
    while (compareStrings(low, high) <= 0) {
        string mid = addStrings(low, high);
        mid = divideByTwo(mid);
      
        string midSqrt = multiplyStrings(mid, mid);
      
        int cmp = compareStrings(midSqrt, n);

        if (cmp == 0) {
              return mid;
        } 
        else if (cmp < 0) {
            res = mid;
            low = addOne(mid);
        } 
        else {
            high = subtractOne(mid);
        }
    }
  
    return res;
}