class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> ump;
        for (auto it : s)
        {
            ump[it]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (ump[s[i]] == 1)
                return i;
        }
        return -1;
    }
};