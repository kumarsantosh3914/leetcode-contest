class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> ump;
        for (const auto &it : s)
        {
            ump[it]++;
        }

        string ans = "";
        for (const auto &ch : order)
        {
            if (ump.find(ch) != ump.end())
            {
                ans += string(ump[ch], ch);
                ump.erase(ch);
            }
        }

        for (const auto &it : ump)
        {
            ans += string(it.second, it.first);
        }
        return ans;
    }
};