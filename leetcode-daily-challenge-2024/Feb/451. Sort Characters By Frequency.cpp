class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> umap;
        // max-heap according to frequency of character
        priority_queue<pair<int, char>> maxHeap;
        for (auto it : s)
        {
            umap[it]++;
        }
        for (auto it : umap)
        {
            // heap will be constructed on the basis of frequency
            maxHeap.push({it.second, it.first});
        }
        // s = "";
        string ans = "";
        while (!maxHeap.empty())
        {
            // frequency times the character
            ans += string(maxHeap.top().first, maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};