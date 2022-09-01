/* Given a string array words, return the maximum value 
of length(word[i]) * length(word[j]) where the two words do not share common letters. 
If no such two words exist, return 0.

Example 1:
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

Example 2:
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".

Example 3:
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.

Constraints:
2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters. */

int isFind(char *word1, char *word2) {
    for (int i = 0; word1[i]; i++){
        if (strchr(word2, word1[i]))
            return (1);
    }
    return (0);
}

int maxProduct(char ** words, int wordsSize){
    int max = 0;
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (!isFind(words[i], words[j])) {
                int len2 = strlen(words[i]) * strlen(words[j]);
                if (len2 > max)
                    max = len2;
            }             
        }
    }
    return (max);
}