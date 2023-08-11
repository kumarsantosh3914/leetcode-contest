class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // There are two scenarios. One where the array is rotated and one 
        // where it is not.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) { // Obvious solution
                return true;
            // Ascending from mid to right.
            } else if (nums[mid] < nums[right]) {
                // If the target is within the right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                // Ascending from left to mid.
            } else if (nums[mid] > nums[right]) {
                // Look if number is in the left half.
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }       
            } else {
                right--;
            }
        }
        return false;
    }
};