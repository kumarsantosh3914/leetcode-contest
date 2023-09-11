class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<vector<int>> mp(groupSizes.size() + 1);

        for(int i=0; i<groupSizes.size(); i++) {
            int size = groupSizes[i];
            mp[size].push_back(i);

            if(mp[size].size() == size) {
                ans.push_back(mp[size]);
                mp[size] = {};
            }
        }
        return ans;
    }
};