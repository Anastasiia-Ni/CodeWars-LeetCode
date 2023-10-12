/* You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
If such an index does not exist, return -1.
You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example 1:
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 
Constraints:
3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109 */ 


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
    public:
    int get(int index);
    int length();
};

class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();

        int peak_idx = findPeakIndex(mountainArr, 0, len - 1);
        int idx = binarySearch(mountainArr, 0, peak_idx, target, 1);
        if (idx < 0)
            idx = binarySearch(mountainArr, peak_idx + 1, len - 1, target, 0);

        return idx;
    }

    int findPeakIndex(MountainArray &mountainArr, int left, int right) {
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int mid_num = mountainArr.get(mid);
            int after_mid = mountainArr.get(mid + 1);
            
            if (mid_num < after_mid)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }

    int binarySearch (MountainArray &mountainArr, int left, int right, int target, bool asc) {
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int mid_num = mountainArr.get(mid);

            if (target == mid_num)
                return mid;
            if (asc) {
                if (target < mid_num)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (target > mid_num)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};