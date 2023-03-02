#include <bits/stdc++.h>
// #include "vector"
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0;
        double maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                sum += nums[i];
            }
            else
            {
                maxi = max(sum, maxi);
                sum += nums[i] - nums[i - k];
            }
        }
        maxi = max(sum, maxi);
        return maxi / k;
    }
};
