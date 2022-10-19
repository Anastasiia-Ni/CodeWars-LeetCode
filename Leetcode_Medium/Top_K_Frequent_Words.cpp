/* Given an array of strings words and an integer k, 
return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. 
Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, 
with the number of occurrence being 4, 3, 2 and 1 respectively.
 
Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]] */

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> res;
        vector<vector<string> > tmp(words.size() + 1);
        for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
            mp[*it]++;
        int i = 0;
        for (unordered_map<string, int>::iterator im = mp.begin(); im != mp.end(); im++)
            tmp[im->second].push_back(im->first);       
        for (int n = words.size(); n > 0; n--) {
            sort(begin(tmp[n]), end(tmp[n]));
            for (vector<string>::iterator iv =  tmp[n].begin(); iv != tmp[n].end(); iv++) { 
                res.push_back(*iv);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};