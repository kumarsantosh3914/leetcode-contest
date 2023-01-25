# Biweekly Contest 96
# [Minimum Common Value](https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/)

## **Approach**
Use 2 pointers total, 1 pointer each in both the arrays and compare the elements.


## **Complexity**
- Time complexity: O(n)

## **Code**
```
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, element;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                // if the ith element in nums1 is smaller than
                // the jth element in nums2, increment pointer i
                i++;
            } else if(nums1[i]>nums2[j]) {
                // if the ith element in nums1 is greater than
                // the jth element in nums2, increment pointer j
                j++;
            } else if(nums1[i] == nums2[j]) {
                // if the ith and jth elements are equal, return it
                // this will always return the smallest element
                return nums1[i];
            }
        }
        return -1;
    }
};
```

## [Minimum Operations to Make Array Equal ll](https://leetcode.com/contest/biweekly-contest-96/problems/minimum-operations-to-make-array-equal-ii/)
## **Intuition**
For making nums1 as nums2, we are adding k at any index and substracking k from another index and continue this process untill they both are equal (According to the question).

When the element of nums1 is greater than nums2 we need to decrese it and if it is lesser we need to increase it by using k.

So to keep track of it, I used pDiff and nDiff and at last there difference must be ) which insures it can be possible to make nums1 as nums2 by using pDff / k or nDiff / k steps.

## **Complexity**
- **Time complexity: O(n)**

## **Code**
```
class Solution 
{
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        if(k==0) //if k is 0 then we can do nothing
        {
            //if nums1 and nums2 are equal operations will be 0 
            //otherwise it is impossible to make them equal
            if(nums1==nums2) return 0; 
            return -1;
        }
        
        //p_diff stores positive difference between nums1[i] and nums2[i] 
        //n_diff stores negative difference between nums1[i] and nums2[i] 
        long long p_diff=0, n_diff=0; 
        
        for(int i=0; i<nums1.size(); i++)
        {
            if(nums1[i] >= nums2[i])
            {
                //we need to check whether we can make them equal by using k
                if((nums1[i]-nums2[i])%k==0) 
                    p_diff += nums1[i]-nums2[i];
                else
                    return -1;
            } 
            else 
            {
                //we need to check whether we can make them equal by using k
                if((nums2[i]-nums1[i])%k==0)
                    n_diff += nums2[i]-nums1[i];
                else
                    return -1;
            }
        }
        
        long long ans=-1;
        //if both difference(p_diff,n_diff) are equal, we can make nums1 equals to nums2
        if(p_diff-n_diff==0) ans = (p_diff/k);
        return ans;
        
    }
};
```
## [Maximum Subsequence Score](https://leetcode.com/contest/biweekly-contest-96/problems/maximum-subsequence-score/)
## **Intuition**
The idea is to consider for each element of array of nums2[i] as minimum once and check for maximum possible values available in nums1 keeping in mind nums2[i] as minimum.

## **Approach**
- First we sort the nums2 array in decreasing order and as we need to know the mapping of nums2[i] to nums1[i] so for that we make their pairs and then we sort.
- Now we will iterate throught p array one by one and let p[i].first as the minimum for an instance then all the elements to left of p array can be considered for sum part.
- But we can make priority queue for knowing top k elements to left of p array.
- And we will only keep k maximum elements at a time in priority queue and kepp the tab of their sum.
- Now please read the code and you will understand it. 

## **Complexity**
- **Time complexity: O(N * Log(N) + (N - K) * Log(k))**
- **Space complexity: O(N) + O(K) = O(N + K)**

## **Code**
```
class Solution {
    public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> p ;
        for(int i = 0 ; i<nums1.size() ; i++) {
            p.push_back({nums2[i] , nums1[i]});
        }
        sort(p.rbegin() , p.rend());
        long long ans  = 0;
        long long sum  = 0;
        priority_queue<int> pq;
        for(int i = 0 ; i<k-1 ; i++) {
            sum += p[i].second;
            pq.push(-p[i].second);
        }

        for(int i = k-1 ; i<nums1.size() ; i++) {
            sum += p[i].second;
            pq.push(-p[i].second);
            ans = max(ans, sum * p[i].first );
            sum += pq.top();
            pq.pop();
        }
        
        return ans;
        
        
    }
};
```

## **[Check if Point Is Reachable](https://leetcode.com/contest/biweekly-contest-96/problems/check-if-point-is-reachable/)**
## **Intuition**
- If we move from `(targetX, targetY)` to the points `(targetX, targetY - targetX)` or `(targetX - targetY, targetY)` , the GCD of the pair remains the same.
- If we move from `(targetX, targetY)` to the points `(2 * targetX, targetY)` or `(targetX, 2 * targetY)` , the GCD of the pair remains same or gets doubled.
- GCD of (1, 1) is 1. From here it can either reamin same or get multiplied by 2 each time. Therefore, from the above observations, point(1, 1) can move to point  `(targetX, targetY)` if and only if gcd of `(targetX, targetY)` is a power of 2.

## **Approach**
- Find gcd of `targetX` and `targetY` .
- Check if gcd is a power of 2. If it is, return `True` else return `False` .

## **Complexity**
- Time complexity: `O(gcd) = O(log(min(targetX, targetY)))`
- Space complexity: `O(gcd)`

## **Code**
```
bool isReachable(int targetX, int targetY) {
    int g = __gcd(targetX, targetY);
    return (g & (g - 1)) == 0; // check g is power of 2
}
```


