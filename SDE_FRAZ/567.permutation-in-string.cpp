/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    // ? neetcode solution

    bool checkInclusion(string a, string b)
    {
        int n = a.size();
        int m = b.size();

        if (n > m)
        {
            return false;
        }

        vector<int> temp(26, 0), hell(26, 0);

        for (int i = 0; i < n; i++)
        {
            temp[a[i] - 'a']++;
            hell[b[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; i++)
        {
            if (temp[i] == hell[i])
            {
                matches++;
            }
        }

        int l = 0;
        for (int r = n; r < m; r++)
        {
            if (matches == 26)
            {
                return true;
            }

            int index = b[r] - 'a';

            hell[index]++;

            if (temp[index] == hell[index])
            {
                matches++;
            }
            else if (temp[index] + 1 == hell[index])
            {
                matches--;
            }

            index = b[l] - 'a';
            hell[index]--;

            if (temp[index] == hell[index])
            {
                matches++;
            }
            else if (temp[index] - 1 == hell[index])
            {
                matches--;
            }
            l++;
        }

        return matches == 26;
    }

    // ? sliding window solution

    //     bool checkInclusion(string a, string b)
    //     {
    //         int n = a.size();
    //         int m = b.size();

    //         if (n > m)
    //         {
    //             return false;
    //         }

    //         vector<int> temp(26, 0), hell(26, 0);

    //         for (auto it : a)
    //         {
    //             temp[it - 'a']++;
    //         }

    //         int low = 0, high = 0;

    //         while (high < m)
    //         {
    //             hell[b[high] - 'a']++;

    //             if ((high - low + 1) == n)
    //             {
    //                 if (solve(temp, hell))
    //                 {
    //                     return true;
    //                 }
    //             }

    //             if (high - low + 1 < n)
    //             {
    //                 high++;
    //             }
    //             else
    //             {
    //                 hell[b[low] - 'a']--;
    //                 low++;
    //                 high++;
    //             }
    //         }

    //         return false;
    //     }

    // private:
    //     bool solve(vector<int> temp, vector<int> hell)
    //     {
    //         for (int i = 0; i < 26; i++)
    //         {
    //             if (temp[i] != hell[i])
    //             {
    //                 return false;
    //             }
    //         }

    //         return true;
    //     }
};
// @lc code=end
