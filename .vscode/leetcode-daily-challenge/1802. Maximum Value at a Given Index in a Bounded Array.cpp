#define ll long long int
class Solution
{
private:
    ll sum(ll element, ll x)
    {
        return x * element - (element * (element + 1)) / 2;
    }

public:
    ll maxValue(ll n, ll index, ll maxSum)
    {
        ll start = 0, end = INT_MAX;
        ll ans = 0;
        while (start <= end)
        {
            ll mid = start + (end - start) / 2;
            ll l = sum(min((ll)index, mid - 1), mid);
            l += max((ll)0, index - mid + 1);
            ll r = sum(min((ll)n - index - 1, mid - 1), mid);
            r += max((ll)0, n - index - 1 - mid + 1);
            if (l + r + mid <= maxSum)
            {
                ans = max(ans, mid);
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};