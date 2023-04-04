class Solution
{
public:
    int partitionString(string s)
    {
        int ind = 0;
        int n = s.size();
        int cnt = 0;

        set<char> stt;
        while (ind < n)
        {
            if (stt.find(s[ind]) == stt.end())
            {
                stt.insert(s[ind]);
                ind++;
            }
            else
            {
                stt.clear();
                cnt++;
                stt.insert(s[ind]);
                ind++;
            }
        }
        return cnt + 1;
    }
};