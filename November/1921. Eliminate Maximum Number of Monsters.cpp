class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<double> time;
        for (int i = 0; i < speed.size(); i++)
        {
            time.push_back((double)dist[i] / (double)speed[i]);
        }
        sort(time.begin(), time.end());
        int t = 0;
        int ans = 0;
        for (auto it : time)
        {
            if (it <= t)
            {
                break;
            }
            else
            {
                ans++;
                t++;
            }
        }
        return ans;
    }
};