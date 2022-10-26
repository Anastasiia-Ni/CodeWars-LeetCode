/* The drawing shows 6 squares the sides of which have 
a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum 
of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80

Could you give the sum of the perimeters of all the squares in a rectangle 
when there are n + 1 squares:

The function perimeter has for parameter n where n + 1 is the number of squares 
(they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216 */

typedef unsigned long long ull;
ull perimeter(int n) {
  if (n == 1 || n == 2)
    return 8 * n;
  ull x1 = 1, x2 = 1, temp, sum = 2;
 
  for(int i = 2; i <= n; i++)
  {
    temp = x2;
    x2 = x1 + x2;
    x1 = temp;
    sum += x2;
  }
  return sum * 4;
}
