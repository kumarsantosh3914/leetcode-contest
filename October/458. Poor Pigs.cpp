class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int trail = minutesToTest / minutesToDie;
        int i = 0;
        int sum = 0;

        if (trail == 0)
            return 0;

        while (sum < buckets)
        {
            sum = pow(trail + 1, i);
            if (sum < buckets)
                i++;
            else
                break;
        }
        return i;
    }
};