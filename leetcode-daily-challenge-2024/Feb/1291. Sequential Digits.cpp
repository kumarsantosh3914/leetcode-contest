class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        queue<int> q;
        for (int i = 1; i <= 8; i++)
        {
            q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            if (temp >= low && temp <= high)
            {
                ans.push_back(temp);
            }
            int lastDigit = temp % 10;
            if (lastDigit + 1 <= 9)
            {
                q.push(temp * 10 + (lastDigit + 1));
            }
        }
        return ans;
    }
};