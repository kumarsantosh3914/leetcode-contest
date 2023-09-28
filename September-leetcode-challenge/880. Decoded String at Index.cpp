class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int count = 0;
        for(auto &ch: s) {
            if(isdigit(ch)) {
                count = count * (ch - '0');
            }
            else {
                count += 1;
            }
        }

        string ans;
        for(int i=s.size() - 1; i>=0; i--) {
            k = k % count;
            if(k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if(isalpha(s[i])) {
                count -= 1;
            }
            else {
                count /= (s[i] - '0');
            }
        }
        return "";
    }
};