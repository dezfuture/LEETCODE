/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution
{
public:
    string numberToWords(int num)
    {
        string word[] = {"Zero", "One", "Two", "Three", "Four",
                         "Five", "Six", "Seven", "Eight", "Nine",
                         "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                         "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string word10[] = {"None", "Ten", "Twenty", "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string res = "";

        if (num >= 1000000000)
        {
            res += numberToWords(num / 1000000000) + " " + "Billion" + " ";
            num %= 1000000000;
        }

        if (num >= 1000000)
        {
            res += numberToWords(num / 1000000) + " " + "Million" + " ";
            num %= 1000000;
        }

        if (num >= 1000)
        {
            res += numberToWords(num / 1000) + " " + "Thousand" + " ";
            num %= 1000;
        }
        if (num >= 100)
        {
            res += word[num / 100] + " " + "Hundred" + " ";
            num %= 100;
        }
        if (num >= 20)
        {
            res += word10[num / 10] + " ";
            num %= 10;
        }
        if (num == 0)
        {
            if (res == "")
            {
                return word[0];
            }
        }
        else
        {
            res += word[num] + " ";
        }

        res.pop_back();
        return res;
    }
};
// @lc code=end
