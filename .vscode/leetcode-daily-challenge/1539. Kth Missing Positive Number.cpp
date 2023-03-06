class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int left = 0, right = arr.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] - 1 - mid < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left + k;
    }
};
