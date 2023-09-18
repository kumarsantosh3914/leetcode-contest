class Solution {
private:
    int countNoOfOnes(vector<int> &num, int left, int right) {
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(num[mid] == 1) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans + 1;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<mat.size(); i++) {
            int noOfOnes = countNoOfOnes(mat[i], 0, mat[0].size() - 1);
            pq.push({noOfOnes, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res(k);
        int j = k - 1;
        while(pq.size()) {
            auto it = pq.top();
            pq.pop();

            res[j--] = it.second;
        }
        return res;
    }
};