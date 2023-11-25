class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int ans = 0;
        for (int i = n / 3; i < n; i += 2)
        {
            // cout << i << " ";
            ans += piles[i];
        }
        return ans;
    }
};
