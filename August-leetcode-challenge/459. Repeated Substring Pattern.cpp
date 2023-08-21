class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s;
        for(int i=0; i<s.size() - 1; i++) {
            char ch = temp[0];
            temp.erase(0, 1); 
            temp.push_back(ch);
            if(temp == s) return true;
        }
        return false;
    }
};