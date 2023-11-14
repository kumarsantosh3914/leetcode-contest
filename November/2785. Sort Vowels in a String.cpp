class Solution
{
public:
    string sortVowels(string s)
    {
        priority_queue<char, vector<char>, greater<char>> q;
        string ans = s;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
                c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
            {
                q.push(c);
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
                c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
            {
                ans[i] = q.top();
                q.pop();
            }
        }
        return ans;
    }
};