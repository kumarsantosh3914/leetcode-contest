class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // vector<int> prefixLeftSum;
        // int ans=0;
        // int leftCnt=1;
        // int leftSum=0;
        // for(int i=0; i<cardPoints.size(); i++) {
        //     leftSum += cardPoints[i];
        //     prefixLeftSum.push_back(leftSum);
        //     if(leftCnt == k) {
        //         ans = max(ans, leftSum);
        //         break;
        //     }
        //     leftCnt++;
        // }

        // int rightCnt=k;
        // int rightSum=0;
        // for(int i=cardPoints.size()-1; i>=0; i--) {
        //     rightSum += cardPoints[i];
        //     if((rightCnt-2)>=0) ans=max(ans,(rightSum+prefixLeftSum[rightCnt-2]));
        //     if(rightCnt == 1) {
        //         ans = max(rightSum, ans);
        //         break;
        //     }
        //     rightCnt--;
        // }
        // return ans;

        // second approach
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += cardPoints[i];
        }

        int cur = ans;
        for (int i = k - 1; i >= 0; i--)
        {
            // we remove the last visited element and add the non-visited element from the last
            cur -= cardPoints[i];
            cur += cardPoints[cardPoints.size() - k + i];
            // we check the maximum value any possible combination can give
            ans = max(ans, cur);
        }
        return ans;
    }
};