class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size();
        while (left < right)
        {
            if (power >= tokens[left])
            {
                power -= tokens[left++];
            }
            else if (left - (tokens.size() - right) && right > left + 1)
                power += tokens[--right];
            else
                break;
        }
        return left - (tokens.size() - right);
    }
};