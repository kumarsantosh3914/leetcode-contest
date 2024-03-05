class Solution
{
public:
    int minimumLength(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                break;
            }

            char ch = s[left];
            while (left <= right && s[left] == ch)
                left++;
            while (right >= left && s[right] == ch)
                right--;
        }
        if (left > right)
        {
            return 0;
        }
        return right - left + 1;
    }
};