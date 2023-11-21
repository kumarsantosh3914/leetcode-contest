class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int freq[50001] = {0};
        int minN = 50000, maxN = 0;
        for (int x : nums)
        {
            freq[x]++;
            minN = min(minN, x);
            maxN = max(maxN, x);
        }
        int count = 0, sum = 0;
        for (int x = maxN; x > minN; x--)
        {
            if (freq[x] > 0)
            {
                sum += freq[x];
                count += sum;
            }
        }
        return count;
    }
};