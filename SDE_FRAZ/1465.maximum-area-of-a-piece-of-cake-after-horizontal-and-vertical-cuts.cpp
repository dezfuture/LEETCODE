/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution
{
public:
    int mod = (int)1e9 + 7;

    int maxArea(int h, int w, vector<int> &hor, vector<int> &ver)
    {
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);

        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());

        int m = hor.size();
        int n = ver.size();

        int temp1 = -1e8, temp2 = -1e8;

        for (int i = 0; i < m - 1; i++)
        {
            temp1 = max(temp1, hor[i + 1] - hor[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            temp2 = max(temp2, ver[i + 1] - ver[i]);
        }

        return (long long)temp1 * (long long)temp2 % mod;
    }
};
// @lc code=end
