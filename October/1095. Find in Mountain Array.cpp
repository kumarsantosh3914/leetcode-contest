class Solution
{
private:
    int findPeakIndex(int low, int high, MountainArray &mountainArr)
    {
        while (low != high)
        {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed)
    {
        while (low != high)
        {
            int mid = low + (high - low) / 2;
            if (reversed)
            {
                if (mountainArr.get(mid) > target)
                    low = mid + 1;
                else
                    high = mid;
            }
            else
            {
                if (mountainArr.get(mid) < target)
                    low = mid + 1;
                else
                    high = mid;
            }
        }
        return low;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int length = mountainArr.length();

        // Find the index of the peak element in the mountain array.
        int peakIndex = findPeakIndex(1, length - 2, mountainArr);

        // Binary search for the target in the increasing part of the mountain array.
        int increasingIndex = binarySearch(0, peakIndex, target, mountainArr, false);
        if (mountainArr.get(increasingIndex) == target)
            return increasingIndex; // Target found in the increasing part.

        // Binary search for the target in the decreasing part of the mountain array.
        int decreasingIndex = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
        if (mountainArr.get(decreasingIndex) == target)
            return decreasingIndex;

        return -1;
    }
};