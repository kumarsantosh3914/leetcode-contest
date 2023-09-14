class Solution {
private:
    int helper(int Aclickboard, int Aonscreen, int n) {
        if(Aonscreen > n) return 100000000;

        if(Aonscreen == n) return 0;

        if(Aclickboard == 0) return 1 + helper(Aonscreen, Aonscreen, n);

        if(Aclickboard == Aonscreen) return 1 + helper(Aonscreen, Aonscreen + Aclickboard, n);

        int copy = helper(Aonscreen, Aonscreen, n);
        int paste = helper(Aclickboard, Aclickboard + Aonscreen, n);

        return 1 + min(copy, paste);
    }
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        return 1 + helper(1, 1, n);
    }
};