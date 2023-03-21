class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0, i, size = flowerbed.size();
        for (i = 0; i < size; i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
            {
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};