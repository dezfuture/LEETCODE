/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 *
 * https://leetcode.com/problems/car-pooling/description/
 *
 * algorithms
 * Medium (59.47%)
 * Likes:    2445
 * Dislikes: 57
 * Total Accepted:    120.3K
 * Total Submissions: 202.7K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * There is a car with capacity empty seats. The vehicle only drives east
 * (i.e., it cannot turn around and drive west).
 *
 * You are given the integer capacity and an array trips where trip[i] =
 * [numPassengersi, fromi, toi] indicates that the i^th trip has numPassengersi
 * passengers and the locations to pick them up and drop them off are fromi and
 * toi respectively. The locations are given as the number of kilometers due
 * east from the car's initial location.
 *
 * Return true if it is possible to pick up and drop off all passengers for all
 * the given trips, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 *
 *
 * Example 2:
 *
 *
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengersi <= 100
 * 0 <= fromi < toi <= 1000
 * 1 <= capacity <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int curr = 0;
        vector<pair<int, int>> v;

        for (int i = 0; i < trips.size(); i++)
        {
            v.push_back({trips[i][1], trips[i][0]});
            v.push_back({trips[i][2], -trips[i][0]});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            curr += v[i].second;

            if (curr > capacity)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
