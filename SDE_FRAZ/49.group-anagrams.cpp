/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &s)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> m;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            auto hell = s[i];
            sort(hell.begin(), hell.end());
            m[hell].push_back(i);
        }

        for (auto a : m)
        {
            vector<string> temp;

            for (auto b : a.second)
            {
                temp.push_back(s[b]);
            }

            res.push_back(temp);
        }

        return res;
    }
};
// @lc code=end
