class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        // Calculate the absolute differences between x and y coordinates of source and destination.
        int xDifference = abs(sx - fx);
        int yDifference = abs(sy - fy);

        if (xDifference == 0 && yDifference == 0 && t == 1)
            return false;

        return (min(xDifference, yDifference) + abs(xDifference - yDifference)) <= t;
    }
};
