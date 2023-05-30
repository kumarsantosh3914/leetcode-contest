class MyHashSet
{
private:
    // Vector of lists to represent the hash set
    vector<list<int>> nums;

    long long hash(long long key)
    {
        // Hash function to evaluate the hash value for a given key
        return ((key * 1031237) & ((1 << 20) - 1)) >> 5;
    }

public:
    MyHashSet()
    {
        // Initialize the vector with 2^15 (32768) empty lists
        nums = vector<list<int>>(1 << 15);
    }

    void add(int key)
    {
        // Calculate the hash value for the key
        int t = hash(key);
        // Check if the key is already present in the list at index t
        if (find(nums[t].begin(), nums[t].end(), key) == nums[t].end())
        {
            // Add the key to the list at index t if it doesn't already exist
            nums[t].push_back(key);
        }
    }

    void remove(int key)
    {
        // Calculate the hash value for the key
        int t = hash(key);
        // Remove the key from the list at index t
        nums[t].remove(key);
    }

    bool contains(int key)
    {
        // Calculate the hash value for the key
        int t = hash(key);
        // Check if the key exists in the list at index t
        return find(nums[t].begin(), nums[t].end(), key) != nums[t].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
