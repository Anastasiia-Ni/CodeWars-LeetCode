/* You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
Return an array answer where answer[i] is the answer to the ith query.

Example 1:
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8

Example 2:
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 
Constraints:
1 <= arr.length, queries.length <= 3 * 10**4
1 <= arr[i] <= 10**9
queries[i].length == 2
0 <= lefti <= righti < arr.length */


using namespace std;
#include <vector>

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        vector<int> xors(arr.size() + 1);

        for (int i = 1; i <= arr.size(); ++i) {
            xors[i] = xors[i - 1] ^ arr[i - 1];
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }

        return res;
    }
};