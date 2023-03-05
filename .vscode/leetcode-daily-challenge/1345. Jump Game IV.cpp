class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        // creating direct connection of same value
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        int jump = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int ind = q.front();
                q.pop();
                vis[ind] = true;
                if (ind == n - 1)
                    return jump;
                if (ind > 0 && !vis[ind - 1])
                    q.push(ind - 1);
                if (ind < n - 1 && !vis[ind + 1])
                    q.push(ind + 1);
                for (auto it : mp[arr[ind]])
                {
                    if (!vis[it])
                        q.push(it);
                }
                mp[arr[ind]] = {};
            }
            jump++;
        }
        return jump;
    }
};