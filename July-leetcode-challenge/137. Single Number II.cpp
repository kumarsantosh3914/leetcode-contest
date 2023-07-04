class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(auto &it: nums) {
            ump[it]++;
        }

        for(auto &it: ump) {
            if(it.second == 1) return it.first;
        }
        return 0;
    }
};