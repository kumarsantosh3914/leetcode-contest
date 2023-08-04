class Solution {
private:
    void helper(int ind, string output, vector<string> &ans, string digits, string mapping[]) {
        //base case
        if(ind >= digits.size()) {
            ans.push_back(output);
            return;
        }
        
        int number=digits[ind] - '0';
        string value=mapping[number];
        for(int i=0; i<value.size(); i++) {
            output.push_back(value[i]);
            helper(ind+1, output, ans, digits, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string output;
        int ind=0;
        string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(ind, output, ans, digits, mapping);
        return ans;
    }
};