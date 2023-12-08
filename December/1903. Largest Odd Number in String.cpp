class Solution
{
public:
    string largestOddNumber(string num)
    {
        int idx = num.size() - 1;
        while (idx >= 0)
        {
            int n = num[idx];
            if (n % 2 != 0)
                return num.substr(0, idx + 1);
            idx--;
        }
        return "";
    }
};