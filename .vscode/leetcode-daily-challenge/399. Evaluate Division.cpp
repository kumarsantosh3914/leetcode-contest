class Solution
{
private:
    void dfs(map<string, vector<pair<string, double>>> &adjList, string start, string end, double &value, map<string, bool> visited, bool &equal)
    {
        if (start == end)
        {
            equal = true;
            return;
        }
        visited[start] = true;
        for (auto it : adjList[start])
        {
            if (!visited[it.first])
            {
                value *= it.second;

                if (end == it.first)
                {
                    equal = true;
                    return;
                }
                dfs(adjList, it.first, end, value, visited, equal);

                if (equal)
                    return;
                else
                    value /= it.second;
            }
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<pair<string, double>>> adjList;
        for (int i = 0; i < equations.size(); i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            string u = queries[i][0];
            string v = queries[i][1];
            if (adjList.find(u) == adjList.end() || adjList.find(v) == adjList.end())
            {
                ans.push_back((double)-1);
            }
            else
            {
                map<string, bool> visited;
                double value = 1.00;
                bool equal = false;

                dfs(adjList, u, v, value, visited, equal);
                if (equal)
                    ans.push_back(value);
                else
                    ans.push_back(-1.00);
            }
        }
        return ans;
    }
};