class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int res = 0;
        int prev = 0;
        for (auto &s : bank)
        {
            int count = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    count++;
                }
            }
            res += prev * count;
            if (count != 0)
            {
                prev = count;
            }
        }
        return res;
    }
};