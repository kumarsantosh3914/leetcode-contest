class Solution
{
private:
    int bfs(vector<vector<int>> routes, unordered_map<int, vector<int>> &busStop, int src, int dest)
    {
        if (src == dest)
            return 0;
        unordered_map<int, bool> visitedStops;
        for (auto it = busStop.begin(); it != busStop.end(); it++)
        {
            visitedStops[it->first] = false;
        }
        vector<bool> visitedBus(routes.size(), false);
        queue<pair<int, int>> q;
        q.push({src, 0});
        visitedStops[src] = true;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int curStop = front.first;
            int count = front.second;
            if (curStop == dest)
                return count;
            vector<int> busOptions = busStop[curStop];
            for (int i = 0; i < busOptions.size(); i++)
            {
                int curBus = busOptions[i];
                if (visitedBus[curBus])
                    continue;
                else
                {
                    vector<int> nextStops = routes[curBus];
                    for (int j = 0; j < nextStops.size(); j++)
                    {
                        int nextStop = nextStops[j];
                        if (visitedStops[nextStop])
                            continue;
                        else
                        {
                            q.push({nextStop, count + 1});
                            visitedStops[nextStop] = true;
                        }
                    }
                    visitedBus[curBus] = true;
                }
            }
        }
        return -1;
    }

public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int n = routes.size();
        if (source == target || n == 0)
            return 0;
        unordered_map<int, vector<int>> busStops;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                int curStop = routes[i][j];
                int curBus = i;
                busStops[curStop].push_back(curBus);
            }
        }
        return bfs(routes, busStops, source, target);
    }
};