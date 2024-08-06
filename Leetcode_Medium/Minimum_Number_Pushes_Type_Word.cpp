/* You are given a string word containing lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, 
which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], 
we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.
An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.
*/


using namespace std;
#include <vector>
#include <iostream>
#include <unordered_map>
    
int minimumPushes(string word) {
    int res = 0;
    unordered_map<char, int> m;
    for (char &c : word){
        m[c]++;
    }
    vector<pair<char, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b){ return a.second > b.second;});

    for (int i = 0, cnt = 1; i < vec.size(); cnt++) {
        int but = 8;
        while (i < vec.size() && but) {
            cout << vec[i].first << " - " << vec[i].second << " " << cnt << endl;
            res += (vec[i].second * cnt);
            i++;
            but--;
        }
    }

    return res;
}

int main () {
    int x = minimumPushes("aabbccddeeffgghhiiiiii");
    cout << "Result: " << x << endl;
}