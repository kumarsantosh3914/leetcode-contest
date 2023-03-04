class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);
        // case 1
        if (k == 0)
            return ans;
        // taking a window of k elements
        // first window will be from index 1 to index k
        int left = 1, right = k;
        // case 2
        if (k < 0)
        {
            // if k is negative then the first window will be the last k elements
            k *= -1;
            left = n - k;
            right = n - 1;
        }
        int sum = 0;
        // maintaining first window
        for (int i = left; i <= right; i++)
        {
            sum += code[i];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = sum;
            // sliding the window
            sum -= code[(left++) % n];
            sum += code[(++right) % n];
        }
        return ans;
    }
};
