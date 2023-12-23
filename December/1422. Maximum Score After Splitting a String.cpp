class Solution
{
public:
    int maxScore(string s)
    {
        int Ones = 0, Zeros = 0;
        int res = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                Ones++;
            }
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                Zeros++;
            }
            else
                Ones--;
            res = max(res, Ones + Zeros);
        }
        return res;
    }
};