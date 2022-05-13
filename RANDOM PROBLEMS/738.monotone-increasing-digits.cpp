/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start

// !using deque

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string res = "";
        string num = to_string(n);

        deque<char> q;
        q.push_back(num[0]);

        for (int i = 1; i < num.size(); i++)
        {
            if (!q.empty() && (q.back() - '0' > num[i] - '0'))
            {
                if (q.front() - '0' < q.back() - '0')
                {
                    while ((q.front() != q.back()))
                    {
                        res += q.front();
                        q.pop_front();
                    }
                }

                int remaining = (q.front() - '0') - 1;
                res += (remaining + '0');

                int rem_len = num.size() - res.size();

                for (int j = 0; j < rem_len; j++)
                {
                    res += '9';
                }

                return stoi(res);
            }
            else
            {
                q.push_back(num[i]);
            }
        }
        return n;
    }
};

// !Greedy Solution

// class Solution
// {
// public:
//     int monotoneIncreasingDigits(int n)
//     {
//         string s = to_string(n);

//         int len = s.length();
//         bool flag = false;
//         int index = -1;

//         for (int i = len - 1; i > 0; i--)
//         {
//             if (s[i] < s[i - 1])
//             {
//                 index = i - 1;

//                 s[index]--;
//                 flag = true;
//             }

//             if (flag)
//             {
//                 for (int j = index + 1; j < len; j++)
//                 {
//                     s[j] = '9';
//                 }

//                 flag = false;
//             }
//         }

//         return stoi(s);
//     }
// };
// @lc code=end
