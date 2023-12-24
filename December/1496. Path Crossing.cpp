class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_map<char, pair<int, int>> ump;
        ump['N'] = {0, 1};
        ump['S'] = {0, -1};
        ump['W'] = {-1, 0};
        ump['E'] = {1, 0};

        unordered_set<string> vis;
        vis.insert("0,0");

        int row = 0, col = 0;
        for (auto &it : path)
        {
            pair<int, int> curr = ump[it];
            int drow = curr.first;
            int dcol = curr.second;

            row += drow;
            col += dcol;
            string hash = to_string(row) + "," + to_string(col);
            if (vis.find(hash) != vis.end())
            {
                return true;
            }
            vis.insert(hash);
        }
        return false;
    }
};