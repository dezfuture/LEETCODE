/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 */

// @lc code=start
class Solution
{
public:
    struct customer
    {
        string name;
        int time;
        int amount;
        string city;
    };

    customer create(string s)
    {
        customer obj;
        vector<string> hell;
        string temp;

        for (auto c : s)
        {
            if (c == ',')
            {
                hell.push_back(temp);
                temp.clear();
                continue;
            }

            temp += c;
        }

        hell.push_back(temp);

        obj.name = hell[0];
        obj.time = stoi(hell[1]);
        obj.amount = stoi(hell[2]);
        obj.city = hell[3];

        return obj;
    }

    vector<string> invalidTransactions(vector<string> &transactions)
    {
        int n = transactions.size();

        vector<bool> invalid(n, 0);

        vector<customer> details;
        vector<string> res;
        unordered_map<string, vector<int>> m;

        int i = 0;

        for (auto &t : transactions)
        {
            customer obj;
            obj = create(t);

            invalid[i] = obj.amount > 1000;
            m[obj.name].push_back(i);
            details.push_back(obj);
            i++;
        }

        i = 0;

        for (auto &t : transactions)
        {
            customer obj;
            obj = create(t);

            if (m.find(obj.name) != m.end())
            {
                vector<int> hell = m[obj.name];
                for (auto &i : hell)
                {
                    if (details[i].city != obj.city && abs(details[i].time - obj.time) <= 60)
                    {
                        invalid[i] = true;
                    }
                }
            }

            i++;
        }

        for (int i = 0; i < invalid.size(); i++)
        {
            if (invalid[i])
            {
                res.push_back(transactions[i]);
            }
        }

        return res;
    }
};
// @lc code=end
