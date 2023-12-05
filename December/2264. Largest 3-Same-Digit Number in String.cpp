class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        int n = num.size();
        for (int i = 0; i < n - 2; i++)
        {
            string temp;
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                temp.push_back(num[i]);
                temp.push_back(num[i + 1]);
                temp.push_back(num[i + 2]);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};