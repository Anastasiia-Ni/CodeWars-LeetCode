/*You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. 
You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, 
where gcd is the greatest common divisor.
Your task is to determine if for every pair of indices i and j in nums, where i < j,
there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

Example 1:
Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

Example 2:
Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.

Example 3:
Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
 
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

using namespace std;
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

class UnionFind {
private:
    vector<int> parents;
    vector<int> sizes;

public: 
    UnionFind(int n) : parents(n), sizes(n, 1) { 
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        return parents[node];
    }

    bool unite(int node_a, int node_b) {
        int root_a = this->find(node_a);
        int root_b = this->find(node_b);
            
        if (root_a == root_b) {
            return false;
        }
            
        if (sizes[root_a] > sizes[root_b]) {
            parents[root_b] = root_a;
            sizes[root_a] += sizes[root_b];
        } 
        else {
            parents[root_a] = root_b;
            sizes[root_b] += sizes[root_a];
        }

        return true;
    }
};


class Solution {
private:
    unordered_map<int, vector<int>> primeFactors;

    void precomputePrimeFactors(int max_value) {
        for (int number = 1; number <= max_value; ++number) {
            int value = number;
            int factor = 2;
            while (factor <= value / factor) {
                if (value % factor == 0) {
                    primeFactors[number].push_back(factor);
                    while (value % factor == 0) {
                        value /= factor;
                    }
                }
                factor++;
            }
            if (value > 1) {
                primeFactors[number].push_back(value);
            }
        }
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int count = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        precomputePrimeFactors(count + max_num + 1);

        UnionFind uf(count + max_num + 1);

        for (int i = 0; i < count; ++i) {
            for (int prime : primeFactors[nums[i]]) {
                uf.unite(i, prime + count);
            }
        }

        unordered_set<int> root_set;
        for (int i = 0; i < count; ++i) {
            root_set.insert(uf.find(i));
        }

        return root_set.size() == 1;
    }
};