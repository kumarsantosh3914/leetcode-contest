class Solution
{
public:
    int totalMoney(int n)
    {
        int ans = 0;
        int completeWeek = n / 7;
        for (int i = 1; i <= completeWeek; i++)
        {
            ans += (i + 3) * 7;
        }

        for (int i = completeWeek * 7; i < n; i++)
        {
            ans += ++completeWeek;
        }
        return ans;
    }
};