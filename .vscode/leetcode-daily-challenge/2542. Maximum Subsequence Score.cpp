class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long sum = 0;
        long long ans = 0;
        vector<pair<int, int>> nums;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.begin(), nums.end());
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            pq.push(nums[i].second);
            sum += nums[i].second;
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                ans = max(ans, nums[i].first * sum);
        }
        return ans;
    }
};