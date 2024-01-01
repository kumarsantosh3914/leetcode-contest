class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int arr[26];
        memset(arr, -1, sizeof arr);
        int ans = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == -1)
            {
                arr[s[i] - 'a'] = i;
            }
            int optain = i - arr[s[i] - 'a'] - 1;
            ans = max(ans, optain);
        }
        return ans;
    }
};