class Solution
{
public:
    int minimumOneBitOperations(int n, int ans = 0)
    {
        if (n == 0)
            return ans;
        int b = 1;
        while ((b << 1) <= n)
        {
            b = b << 1;
        }
        return minimumOneBitOperations((b >> 1) ^ b ^ n, ans + b);
    }
};