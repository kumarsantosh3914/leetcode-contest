class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;

        // counting the frequency of elements
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        vector<int> ans;
        // copy frequency of map into vector
        for (auto i : m)
            ans.push_back(i.second);

        // copy vector into set
        set<int> st(ans.begin(), ans.end());

        int n = ans.size();
        int y = st.size();

        // compare vector size and set size
        if (n == y)
            return true;
        return false;
    }
};