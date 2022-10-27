/* You are given two images, img1 and img2, represented as binary, 
square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, 
right, up, and/or down any number of units. We then place it on top of the other image. 
We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. 
Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap. */

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int largestOverlap(vector<vector<int> >& img1, vector<vector<int> >& img2) {
        int n = img1.size();
        unordered_map<int, int> tmp;
        int res = 0;
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x1 = 0; x1 < n; ++x1) {
                if (img1[y1][x1]) {
                    for (int y2 = 0; y2 < n; ++y2) {
                        for (int x2 = 0; x2 < n; ++x2) {                      
                            if (img2[y2][x2])                 
                            ++tmp[(x1 - x2) * 100 + (y1 - y2)];
                        }
                    }
                }
            } 
        }
        unordered_map<int, int>::iterator it;
        for (it = tmp.begin(); it != tmp.end(); it++)
            res = max(res, it->second);
        return res;
    }
};