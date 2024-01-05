class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        // Create an unordered map to store the frequency of each number in the input vector
        unordered_map<int, int> umap;
        for (auto &num : nums)
        {
            umap[num]++;
        }

        int ans = 0;
        // Iterate through the unordered map
        for (const auto &it : umap)
        {
            // Get the frequency of the current number
            int num = it.second;

            // Perform operations until the frequency becomes zero
            while (num)
            {
                // If there is only one occurrence of the number, it is not possible to make all elements equal
                if (num == 1)
                {
                    return -1;
                }
                // If the frequency is 4 or 2, perform an operation by subtracting 2 from the frequency
                else if (num == 4 || num == 2)
                {
                    num -= 2;
                    ans++;
                }
                // If the frequency is not 1, 2, or 4, perform an operation by subtracting 3 from the frequency
                else
                {
                    num -= 3;
                    ans++;
                }
            }
        }
        return ans;
    }
};
