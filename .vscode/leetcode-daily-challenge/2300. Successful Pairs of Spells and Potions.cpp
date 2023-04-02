#define ll long long
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        // sort the potions
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++)
        {
            ll start = 0;
            ll end = potions.size() - 1;
            ll mid;
            int ind = -1;
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                ll x = spells[i] * 1LL * potions[mid];
                if (x >= success)
                {
                    ind = mid;
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            if (ind == -1)
                ans.push_back(0);
            else
                ans.push_back(potions.size() - ind);
        }
        return ans;
    }
};