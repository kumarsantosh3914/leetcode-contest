class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        unordered_map<char, int> ump;
        int i = 0, j = 0;
        int count = 0;
        while (j < s.size())
        {
            ump[s[j]]++;
            if (j - i + 1 < 3)
            {
                j++;
            }
            else if (j - i + 1 == 3)
            {
                if (ump.size() == 3)
                    count++;
                ump[s[i]]--;
                if (ump[s[i]] == 0)
                    ump.erase(s[i]);
                i++;
                j++;
            }
        }
        return count;
    }
};
