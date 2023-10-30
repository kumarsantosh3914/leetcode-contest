class Solution
{
private:
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{{'s', {'a', 'e', 'i', 'o', 'u'}},
                                                     {'a', {'e'}},
                                                     {'e', {'a', 'i'}},
                                                     {'i', {'a', 'e', 'o', 'u'}},
                                                     {'o', {'i', 'u'}},
                                                     {'u', {'a'}}};
    unordered_map<char, vector<int>> dp;

    int solve(int rem, char prev)
    {
        if (rem == 0)
            return 1;
        if (dp[prev][rem])
            return dp[prev][rem];
        for (auto c : mappings.at(prev))
            dp[prev][rem] = (dp[prev][rem] + solve(rem - 1, c)) % MOD;
        return dp[prev][rem];
    }

public:
    int countVowelPermutation(int n)
    {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n + 1);
        return solve(n, 's');
    }
};