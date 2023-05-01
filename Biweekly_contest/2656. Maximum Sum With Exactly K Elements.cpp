class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        int sum = 0;
        while (k--)
        {
            int it = pq.top();
            pq.pop();
            sum += it;
            pq.push(it + 1);
        }
        return sum;
    }
};