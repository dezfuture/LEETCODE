/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (39.16%)
 * Likes:    3019
 * Dislikes: 343
 * Total Accepted:    324K
 * Total Submissions: 813.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 *
 *
 * Example 1:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lowercase English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string x;
        vector<string> v;
        stringstream iss(s);

        while (iss >> x)
        {
            v.push_back(x);
        }

        if (v.size() != pattern.size())
        {
            return false;
        }
        else
        {
            set<string> hell;
            map<char, string> m;
            for (int i = 0; i < pattern.size(); i++)
            {
                if (m.find(pattern[i]) == m.end())
                {
                    m[pattern[i]] = v[i];
                    hell.insert(v[i]);
                }
                else if (m[pattern[i]] != v[i])
                {
                    return false;
                }
            }

            return hell.size() == m.size();
        }
    }
};
// @lc code=end
