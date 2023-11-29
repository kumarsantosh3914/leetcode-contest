class Solution
{
private:
    int modulo = 1e9 + 7;
    int helper(int ind, int seats, string &corridor, vector<vector<int>> &dp)
    {
        // base case
        if (ind == corridor.size())
        {
            if (seats == 2)
                return 1;
            return 0;
        }
        if (dp[ind][seats] != -1)
            return dp[ind][seats];

        // if the seats are 2
        // if its a plant, i can place a barrier, i cannot place a barrier
        // if its a seats, i place a barrier before that seat
        int calls = 0;
        if (seats == 2)
        {
            if (corridor[ind] == 'P')
            {
                // place
                calls += helper(ind + 1, 0, corridor, dp);
                calls %= modulo;
                // not place
                calls += helper(ind + 1, seats, corridor, dp);
                calls %= modulo;
            }
            // if its a seat itself
            // then place the barrier before it
            // ans move to the next index saying that the barrier has been placed
            else
            {
                calls += helper(ind + 1, 1, corridor, dp);
                calls %= modulo;
            }
        }
        // if seats are not 2
        // you cannot place a barrier
        else
        {
            calls += helper(ind + 1, seats + (corridor[ind] == 'S'), corridor, dp);
            calls %= modulo;
        }
        return dp[ind][seats] = calls;
    }

public:
    int numberOfWays(string corridor)
    {
        vector<vector<int>> dp(corridor.size(), vector<int>(3, -1));
        return helper(0, 0, corridor, dp);
    }
};