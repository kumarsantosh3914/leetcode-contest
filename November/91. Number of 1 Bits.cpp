class Solution
{
public:
    int hammingWeight(uint32_t N)
    {
        int cnt = 0;
        while (N)
        {
            cnt += (N & 1);
            N >>= 1;
        }
        return cnt;
    }
};