/* This time we want to write calculations using functions and get the results. Let's have a look at some examples:
seven(times(five())); // must return 35
four(plus(nine())); // must return 13
eight(minus(three())); // must return 5
six(divided_by(two())); // must return 3

Requirements:

There must be a function for each number from 0 ("zero") to 9 ("nine")
There must be a function for each of the following mathematical operations: plus, minus, times, divided_by
Each calculation consist of exactly one operation and two numbers
The most outer function represents the left operand, the most inner function represents the right operand
Division should be integer division. For example, this should return 2, not 2.666666...:
eight(divided_by(three())); */

// You have complete freedom over the function signatures, as long as all the needed functions get defined.
// Do not `using namespace std`, because your `plus` function might clash with `std::plus` :)


#include <functional>

int zero(std::function<int(int)> func = nullptr) { return func ? func(0) : 0; }
int one(std::function<int(int)> func = nullptr) { return func ? func(1) : 1; }
int two(std::function<int(int)> func = nullptr) { return func ? func(2) : 2; }
int three(std::function<int(int)> func = nullptr) { return func ? func(3) : 3; }
int four(std::function<int(int)> func = nullptr) { return func ? func(4) : 4; }
int five(std::function<int(int)> func = nullptr) { return func ? func(5) : 5; }
int six(std::function<int(int)> func = nullptr) { return func ? func(6) : 6; }
int seven(std::function<int(int)> func = nullptr) { return func ? func(7) : 7; }
int eight(std::function<int(int)> func = nullptr) { return func ? func(8) : 8; }
int nine(std::function<int(int)> func = nullptr) {  return func ? func(9) : 9; }

std::function<int(int)> plus( int x ) { return [x](int y) { return y + x; }; }
std::function<int(int)> minus( int x ) { return [x](int y) { return y - x; }; }
std::function<int(int)> times( int x ) { return [x](int y) { return y * x; };}
std::function<int(int)> divided_by( int x ) { return [x](int y) { return y / x; }; }