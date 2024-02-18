class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int> pq;
        int n = heights.size(), i = 0;
        while (i < n - 1 && bricks >= 0)
        {
            if (heights[i] < heights[i + 1])
                pq.push(heights[i + 1] - heights[i]), bricks -= heights[i + 1] - heights[i];

            while (bricks < 0 && ladders)
                ladders--, bricks += pq.top(), pq.pop();

            if (bricks >= 0)
                i++;
        }

        return i;
    }
};