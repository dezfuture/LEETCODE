/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> res;

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && asteroids[i] < 0 && s.top() > 0)
            {
                int diff = asteroids[i] + s.top();
                if (diff < 0)
                {
                    s.pop();
                }
                else if (diff > 0)
                {
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                    s.pop();
                }
            }
            if (asteroids[i])
            {
                s.push(asteroids[i]);
            }
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
