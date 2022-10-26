/* Write an algorithm that takes an array and moves all 
of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0} */ 

#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  std::vector<int>res;
  int zero = 0;
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] == 0)
      zero++;
    else
      res.push_back(input[i]);
  }
  while(zero--)
    res.push_back(0); 
  return (res);
}