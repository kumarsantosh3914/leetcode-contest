class Solution {
private:
    int getPivot(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] >= nums[0]) {
                start = mid + 1;
            }
            else end = mid;
        }
        return start;
    }

    int binarySearch(vector<int> &nums, int start, int end, int target) {
        int left = start, right = end;
        while(left <= right) {
            int mid = left + (right - left);
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    } 
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums);
        if(target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1,target); 
        }
        else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};