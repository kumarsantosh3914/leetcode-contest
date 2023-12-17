class Solution
{
public:
    bool isAnagram(string a, string b)
    {
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        return (a == b);
    }
};