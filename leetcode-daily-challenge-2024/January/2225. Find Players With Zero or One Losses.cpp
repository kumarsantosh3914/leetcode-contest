class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> loserCount;
        set<int> winner, loser;
        for (const auto &it : matches)
        {
            winner.insert(it[0]);
            loser.insert(it[1]);
            loserCount[it[1]]++;
        }

        vector<int> v1, v2;
        for (const auto &it : winner)
        {
            if (loserCount.find(it) == loserCount.end())
            {
                v1.push_back(it);
            }
        }

        for (const auto &it : loser)
        {
            if (loserCount[it] == 1)
            {
                v2.push_back(it);
            }
        }

        return {v1, v2};
    }
};