class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        if (words.size() == 1)
        {
            return true;
        }

        vector<int> freq(26, 0);
        for (const string &st : words)
        {
            for (const auto &it : st)
            {
                freq[it - 'a']++;
            }
        }

        for (const auto &it : freq)
        {
            if (it % words.size() != 0)
            {
                return false;
            }
        }
        return true;
    }
};