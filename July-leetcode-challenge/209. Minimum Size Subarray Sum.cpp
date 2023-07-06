class Solution {
private:
//     bool blackBox(vector<int> nums, int n, int target, int k) {
//         //first find the first k size subarray sum
//         int sum=0;
//         for(int i=0; i<k; i++) sum += nums[i];
//         int maxi=sum;
//         int l=0, r=k-1;
//         while(r != n-1) {
//             sum -= nums[l];
//             l++;
            
//             sum += nums[r];
//             r++;
//             maxi=max(maxi, sum);
//         }
//         return maxi >= target;
//     }
    bool blackBox(int x, int target,  vector<int>& nums) {
        int cache = 0;
        for(int i = 0; i < x; i++) {
            cache += nums[i];
        }
        if(cache >= target)
            return true;
        
        for(int i = x; i < nums.size(); i++) {
            cache -= nums[i-x];
            cache += nums[i];
            if (cache >= target)
                return true;
        }
        
        return false;
    }

public:
    int minSubArrayLen(int target, vector<int>& nums) {
    //     int n=nums.size();
    //     int low=1, high=n;
    //     bool ansPossible=false;
    //     while(low < high) {
    //         int mid=(low+high)/2;
    //         if(blackBox(mid, target, nums) == true) {
    //             ansPossible=true;
    //             high=mid;
    //         }
    //         else {
    //             low=mid+1;
    //         }
    //     }
    //     if(ansPossible == true) return low;
    //     return 0;
        int n = nums.size();
        
        int ans = 0;
        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(blackBox(mid, target, nums)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return ans;
     }
};