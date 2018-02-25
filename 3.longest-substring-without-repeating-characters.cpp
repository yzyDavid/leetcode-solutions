/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.63%)
 * Total Accepted:    439.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto l = s.size();
        if (l == 0) return 0;
        int i, j;
        int first = 0, last = 0;
        int max_len = 1;
        for (i = 0; i < l; ++i)
        {
            last = i;
            if (first == last) continue;
            for (j = first; j < i; ++j)
            {
                if (s[i] == s[j])
                {
                    first = j + 1;
                    break;
                }
            }
            int len = last - first + 1;
            max_len = len > max_len ? len : max_len;
        }
        return max_len;
    }
};
