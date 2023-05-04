class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> q1, q2;
        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
            {
                q1.push(i);
            }
            else
            {
                q2.push(i);
            }
        }

        while (!q1.empty() && !q2.empty())
        {
            int rIdx = q1.front(), dIdx = q2.front();
            q1.pop(), q2.pop();
            if (rIdx < dIdx)
            {
                q1.push(rIdx + senate.size());
            }
            else
            {
                q2.push(dIdx + senate.size());
            }
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
};
