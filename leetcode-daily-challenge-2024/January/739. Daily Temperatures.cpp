class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (s.size() && temperatures[s.top()] < temperatures[i])
            {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};