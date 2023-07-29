class Solution {
public:
    int solve(int i, int j, vector<int> &nums) {
        // base case
        if(i > j) return 0;

        int choice1 = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int choice2 = nums[j] + min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));

        return max(choice1, choice2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int bestScore = solve(0, n - 1, nums);
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(bestScore >= sum - bestScore) return true;
        return false;
    }
};