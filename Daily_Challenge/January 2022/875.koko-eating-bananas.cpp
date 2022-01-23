/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    3521
 * Dislikes: 162
 * Total Accepted:    148.1K
 * Total Submissions: 271K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has
 * piles[i] bananas. The guards have gone and will come back in h hours.
 *
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she
 * chooses some pile of bananas and eats k bananas from that pile. If the pile
 * has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 *
 * Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h
 * hours.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 *
 *
 * Example 3:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int temp = 0;

            for (auto x : piles)
            {
                temp += x / mid + (x % mid != 0);
            }

            if (temp <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high;
    }
};

// basic brute force solution

/*

int minEatingSpeed(vector<int> &piles, int h)
    {
        int res = 1;

        while (1)
        {
            int hours = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                hours += piles[i] / res + (piles[i] % res != 0);

                if (hours > h)
                {
                    break;
                }
            }

            if (hours <= h)
            {
                return res;
            }
            else
            {
                res++;
            }
        }
    }

*/
// @lc code=end