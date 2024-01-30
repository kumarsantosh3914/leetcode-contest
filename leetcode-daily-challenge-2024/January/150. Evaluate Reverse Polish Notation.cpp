class Solution
{
private:
    int swap(string s)
    {
        char k;
        int ret = 0;
        int flag = 1;
        for (int i = 0; i < s.size(); i++)
        {
            k = s[i];
            if (k != '-')
            {
                ret = ret * 10 + k - '0';
            }
            else
            {
                flag = -1;
            }
        }
        return flag * ret;
    }

public:
    int evalRPN(vector<string> &s)
    {
        stack<long long> ss;
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == "+")
            {
                int first = ss.top();
                ss.pop();
                int second = ss.top();
                ss.pop();
                ss.push((first + second));
            }
            else if (s[i] == "-")
            {
                int first = ss.top();
                ss.pop();
                int second = ss.top();
                ss.pop();
                ss.push((second - first));
            }
            else if (s[i] == "*")
            {
                long long first = ss.top();
                ss.pop();
                long long second = ss.top();
                ss.pop();
                ss.push((first * second));
            }
            else if (s[i] == "/")
            {
                int first = ss.top();
                ss.pop();
                int second = ss.top();
                ss.pop();
                ss.push((second / first));
            }
            else
            {
                int temp = swap(s[i]);
                ss.push(temp);
            }
        }
        return ss.top();
    }
};
