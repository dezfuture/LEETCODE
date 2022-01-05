/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (60.11%)
 * Likes:    3105
 * Dislikes: 158
 * Total Accepted:    148K
 * Total Submissions: 245K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 * All the integer values in the input expression are in the range [0, 99].
 *
 *
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, vector<int>> m;

    vector<int> diffWaysToCompute(string s)
    {

        if (m.find(s) != m.end())
        {
            return m[s];
        }

        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-' || s[i] == '+' || s[i] == '*')
            {
                string a = s.substr(0, i);
                string b = s.substr(i + 1);
                vector<int> res1 = diffWaysToCompute(a);
                vector<int> res2 = diffWaysToCompute(b);

                m[a] = res1;
                m[b] = res2;
                for (auto x : res1)
                {
                    for (auto y : res2)
                    {
                        if (s[i] == '-')
                            res.push_back(x - y);
                        else if (s[i] == '+')
                            res.push_back(x + y);
                        else if (s[i] == '*')
                            res.push_back(x * y);
                    }
                }
            }
        }
        if (res.empty())
        {
            res.push_back(stoi(s));
            m[s] = res;
            return res;
        }

        m[s] = res;
        return res;
    }
};
// @lc code=end
