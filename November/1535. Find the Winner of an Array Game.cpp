class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxi = *max_element(arr.begin(), arr.end());

        if (arr.size() <= k)
        {
            return maxi;
        }

        int winner = arr[0];
        int winCount = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > winner)
            {
                winner = arr[i];
                winCount = 1;
            }
            else
            {
                winCount++;
            }
            if (winCount == k || winner == maxi)
            {
                return winner;
            }
        }
        return 0;
    }
};