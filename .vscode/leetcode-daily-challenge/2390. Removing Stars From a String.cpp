class Solution
{
public:
    string removeStars(string s)
    {
        /*
          Pointer i is the current string position, and j - the insertion position.
          We copy the character from position i to position j.
          If this character is *, we decrease j; otherwise - increase j.
        */
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '*')
                i--;
            else
                s[i++] = s[j];
        }
        return s.substr(0, i);
    }
};