#define mod 1000000007
class Solution
{
private:
    long long helper(vector<int> &locations, int startCity, int finish, int fuel, vector<vector<int>> &dp)
    {
        if (fuel < 0)
            return 0;

        if (dp[startCity][fuel] != -1)
            return dp[startCity][fuel];

        long long routeCount = 0;
        if (startCity == finish)
            routeCount = 1;
        else
            routeCount = 0;

        // visit all city except startCity
        for (int nextCity = 0; nextCity < locations.size(); nextCity++)
        {
            if (nextCity != startCity)
            {
                routeCount = (routeCount + helper(locations, nextCity, finish, fuel - abs(locations[startCity] - locations[nextCity]), dp)) % mod;
            }
        }
        return dp[startCity][fuel] = (routeCount) % mod;
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1, -1));
        return helper(locations, start, finish, fuel, dp);
    }
};