class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int countOne = -1;
        string res = "";
        for (auto &ch : s)
        {
            countOne += (ch == '1') ? 1 : 0;
        }
        for (int i = 0; i < s.size(); i++, countOne--)
        {
            res += (countOne > 0) ? '1' : '0';
        }
        res.pop_back();
        return res + '1';
    }
};
