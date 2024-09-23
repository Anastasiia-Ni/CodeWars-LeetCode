/* You are given a 0-indexed string s and a dictionary of words dictionary. 
You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
There may be some extra characters in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.

Example 1:
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 
Constraints:
1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words */

using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
private:
    struct TrieNode {
        bool word = false;
        vector<TrieNode *> children;

        TrieNode() : children(26) {}
    };

    struct Trie {
        TrieNode *root;

        Trie(unordered_set<string> &words) {
            root = new TrieNode();
            for (const string &word : words) {
                TrieNode *curr = root;
                for (const char &c : word) {
                    int index = c - 'a';
                    if (!curr->children[index]) {
                        curr->children[index] = new TrieNode();
                    }
                    curr = curr->children[index];
                }
                curr->word = true;
            }
        }

        vector<int> search(const string &s, int start) {
            vector<int> result;
            TrieNode *curr = root;
            for (int i = start; i < s.size(); ++i) {
                int index = s[i] - 'a';
                if (!curr->children[index]) {
                    break;
                }
                curr = curr->children[index];
                if (curr->word) {
                    result.push_back(i + 1);
                }
            }
            return result;
        }

        ~Trie() { clear(root); }
        void clear(TrieNode* node) {
            if (!node) return;

            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    clear(node->children[i]);
                }
            }
            delete node;
        }
        
    };
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words = {dictionary.begin(), dictionary.end()};
        const int n = s.size();
        vector<int> dp (n + 1, n);
        dp[0] = 0;

        Trie trie = Trie(words);

        for (int i = 0; i < n; ++i) {
            if (dp[i] == n) continue;
            vector<int> matches = trie.search(s, i);
            for (int end : matches) {
                dp[end] = min(dp[end], dp[i]);
            }
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }

        return dp[n];
    }
};