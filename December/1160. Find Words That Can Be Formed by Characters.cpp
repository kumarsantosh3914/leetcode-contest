class Solution
{
private:
    bool canForm(string &str, vector<int> &counts)
    {
        vector<int> count(26, 0);
        for (auto &ch : str)
        {
            count[ch - 'a']++;
            if (count[ch - 'a'] > counts[ch - 'a'])
            {
                return false;
            }
        }
        return true;
    }

public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> counts(26, 0);
        for (auto &ch : chars)
        {
            counts[ch - 'a']++;
        }

        int ans = 0;
        for (auto &it : words)
        {
            if (canForm(it, counts))
            {
                ans += it.size();
            }
        }
        return ans;
    }
};