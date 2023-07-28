class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int i=0; i<batteries.size(); i++) 
            sum+=batteries[i];
        
        long long r=sum/n+1;
        sort(batteries.begin(), batteries.end());
        long long l=batteries[batteries.size()-n];
        long long ans=0;
        while(l<r) {
            long long mid=(l+r)/2;
            int k=batteries.size()-1;
            while(k>=0 && batteries[k]>=mid) 
                k--;
            int rem=n-(batteries.size()-1-k);
            long long temp=0;
            while(k>=0) 
                temp+=batteries[k], k--;
            if(rem<=0 || rem*mid <=temp)
                ans=max(ans,mid), l=mid+1;
            else
                r=mid;
        }
        return ans;
    }
};