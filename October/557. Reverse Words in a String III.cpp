class Solution
{
public:
    string reverseWords(string s)
    {
        int ind = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                reverse(s.begin() + ind, s.begin() + j);
                ind = j + 1;
            }
        }
        reverse(s.begin() + ind, s.end());
        return s;
    }
};