class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string str = to_string(num);
        string temp = "";
        int i = 0, j = 0, cnt = 0;
        while (j < str.size())
        {
            temp += str[j];
            if (j - i + 1 < k)
            {
                j++;
            }
            else
            {
                if (stoi(temp) != 0 && num % (stoi(temp)) == 0)
                {
                    cnt++;
                }
                temp = temp.substr(1);
                i++;
                j++;
            }
        }
        return cnt;
    }
};
