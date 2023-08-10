class Solution {
private:
    bool check (int mid, vector<int> &nums, int p) {
        int count = 0;
        for(int i=0; i<nums.size() - 1; i++) {
            if(nums[i + 1] - nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1e9;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(check(mid, nums, p)) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }
};