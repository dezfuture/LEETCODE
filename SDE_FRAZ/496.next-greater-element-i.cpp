/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int n = nums2.size();
        vector<int> hell(n, -1);
        stack<int> s;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {

            m[nums2[i]] = i;

            while (!s.empty() && nums2[i] > nums2[s.top()])
            {
                int k = s.top();
                hell[k] = nums2[i];
                s.pop();
            }

            s.push(i);
        }

        int len = nums1.size();
        vector<int> temp;

        for (int i = 0; i < len; i++)
        {
            int yoyo = hell[m[nums1[i]]];
            temp.push_back(yoyo);
        }

        return temp;
    }
};
// @lc code=end
