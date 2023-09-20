class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(auto &it: nums) {
                if(it <= mid) count++;
            }
            if(count <= mid) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};