class MyHashMap
{
private:
    vector<int> mp;
    int size;

public:
    MyHashMap()
    {
        size = 1e6 + 1;
        mp.resize(size);
        fill(mp.begin(), mp.end(), -1);
    }

    void put(int key, int value)
    {
        mp[key] = value;
    }

    int get(int key)
    {
        return mp[key];
    }

    void remove(int key)
    {
        mp[key] = -1;
    }
};

/**
 * @brief 
 * 
 */
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */