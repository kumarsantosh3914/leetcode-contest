class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int count = 0;
        int i = 0, j = 0, windowSum = 0;
        while (j < arr.size())
        {
            windowSum += arr[j];
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                int average = windowSum / k;
                if (average >= threshold)
                {
                    count++;
                }
                windowSum -= arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};