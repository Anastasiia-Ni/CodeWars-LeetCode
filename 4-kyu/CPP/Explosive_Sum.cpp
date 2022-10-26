/* How many ways can you make the sum of a number?
number theory and combinatorics, a partition of a positive integer n, 
also called an integer partition, is a way of writing n as a sum of positive integers. 
Two sums that differ only in the order of their summands are considered the same partition. 
If order matters, the sum becomes a composition. 
For example, 4 can be partitioned in five distinct ways:
4
3 + 1
2 + 2
2 + 1 + 1
1 + 1 + 1 + 1

Examples
Basic
exp_sum(1) // 1
exp_sum(2) // 2  -> 1+1 , 2
exp_sum(3) // 3 -> 1+1+1, 1+2, 3
exp_sum(4) // 5 -> 1+1+1+1, 1+1+2, 1+3, 2+2, 4
exp_sum(5) // 7 -> 1+1+1+1+1, 1+1+1+2, 1+1+3, 1+2+2, 1+4, 5, 2+3
exp_sum(10) // 42

Explosive
exp_sum(50) // 204226
exp_sum(80) // 15796476
exp_sum(100) // 190569292 */

#include <iostream>
#include <vector>

using ull = unsigned long long;

ull exp_sum(unsigned int n) {
  std::vector<ull> vec(n + 1, 0);
  vec[0] = 1;
  for(size_t i = 1; i <= n; i++) {
      for(size_t j = i; j <= n; j++) {
          vec[j] += vec[j - i];
      }
  }
  return vec[n];
}