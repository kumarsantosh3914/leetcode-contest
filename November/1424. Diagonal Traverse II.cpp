class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        // Using an unordered_map to store elements with the same diagonal sum
        unordered_map<int, vector<int>> umap;
        // Initialize the maximum diagonal sum
        int maxi = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                // Calculate the diagonal sum for the current element
                int sum = i + j;
                // Store the element in the unordered_map with the diagonal sum as key
                umap[sum].push_back(nums[i][j]);

                // Update the maximum diagonal sum
                maxi = max(maxi, sum);
            }
        }

        vector<int> ans;
        for (int i = 0; i <= maxi; i++)
        {
            for (auto &it : umap[i])
            {
                // Append elements to the result vector
                ans.push_back(it);
            }
        }
        return ans;
    }
};
