class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size();
        int n = needle.size();
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            // as long as the characters are equal, increment needleIndex
            if (haystack[i] == needle[idx])
            {
                idx++;
            }
            else
            {
                // start from the next index of previous start index
                i = i - idx;
                idx = 0;
            }
            // check if needleIndex reached needle size
            if (idx == n)
                return i - n + 1;
        }
        return -1;
    }
};