class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        if(s == goal) return set<char>(s.begin(), s.end()).size() < s.size();

        int left = 0, right = s.size() - 1;
        while(left < s.size() && s[left] == goal[left]) left++;

        while(right >= 0 && s[right] == goal[right]) right--;
        if(left < right) swap(s[left], s[right]);
        return s == goal;
    }
};