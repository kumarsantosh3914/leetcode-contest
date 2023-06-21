class Solution
{
private:
    // A function to calculate the cost of making all elements equal to a given element
    int findCost(vector<int> &nums, vector<int> &cost, int element)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = abs(nums[i] - element);
            ans += (a * cost[i]);
        }
        return ans;
    }

public:
    // Function to find the minimum cost of making all elements equal
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int minElement = INT_MAX; // Initialize the minimum element of the array
        int maxElement = INT_MIN; // Initialize the maximum element of the array
        for (auto it : nums)
        {
            minElement = min(minElement, it); // Find the minimum element of the array
            maxElement = max(maxElement, it); // Find the maximum element of the array
        }
        long long ans = LLONG_MAX; // Initialize the answer with a very large number
        while (minElement <= maxElement)
        {                                                         // Perform binary search until the minimum element is less than or equal to the maximum element
            int mid = minElement + (maxElement - minElement) / 2; // Calculate the middle element
            int temp = findCost(nums, cost, mid);                 // Calculate the cost of making all elements equal to the middle element
            ans = min(ans, (long long)temp);                      // Update the answer with the minimum cost
            int left = findCost(nums, cost, mid - 1);             // Calculate the cost of making all elements equal to the element left to the middle element
            int right = findCost(nums, cost, mid + 1);            // Calculate the cost of making all elements equal to the element right to the middle element
            // If the cost of making all elements equal to the middle element is less than the cost of making all elements equal to the left and right elements, return the answer
            if (temp < left && temp < right)
                return ans;
            // If the cost of making all elements equal to the middle element is less than the cost of making all elements equal to the left element but greater than the cost of making all elements equal to the right element, update the minimum element to middle element + 1
            else if (temp < left && temp > right)
                minElement = mid + 1;
            // If the cost of making all elements equal to the middle element is greater than the cost of making all elements equal to the left element but less than the cost of making all elements equal to the right element, update the maximum element to middle element - 1
            else
                maxElement = mid - 1;
        }
        return ans; // Return the minimum cost
    }
};