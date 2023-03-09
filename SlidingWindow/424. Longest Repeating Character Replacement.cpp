class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i = 0, j = 0;
        int maxi = INT_MIN;
        int res = -1;
        unordered_map<char, int> ump;
        while (j < s.size())
        {
            ump[s[j]]++;
            maxi = max(maxi, ump[s[j]]);
            if ((j - i + 1) - maxi <= k)
            {
                res = max(res, j - i + 1);
                j++;
            }
            else if ((j - i + 1) - maxi > k)
            {
                while ((j - i + 1) - maxi > k)
                {
                    ump[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};
