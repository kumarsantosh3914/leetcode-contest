class LRUCache {
public:
    class node{
        public:
           int key_;
           int val;
           node* next;
           node* prev;
        node(int _key, int _val) {
            key_ = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1,-1); // Dummy node for the head of the linked list
    node* tail = new node(-1,-1); // Dummy node for the tail of the linked list
    int cap;
    unordered_map<int,node*> mp; // Map to store key-node pairs
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail; // Initialize the head's next pointer to the tail
        tail->prev = head; // Initialize the tail's prev pointer to the head
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp; // Set new node's next pointer to the current head's next node
        newnode->prev = head; // Set new node's prev pointer to the head
        head->next = newnode; // Update the head's next pointer to the new node
        temp->prev = newnode; // Update the current head's next node's prev pointer to the new node
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext; // Update the previous node's next pointer to the next node
        delnext->prev = delprev; // Update the next node's prev pointer to the previous node
    }
    
    int get(int key_) {
        if(mp.find(key_) != mp.end()) { // If the key exists in the map
            node* resnode = mp[key_];
            int res = resnode->val; // Get the value of the node
            mp.erase(key_); // Erase the key from the map
            deletenode(resnode); // Delete the node from the linked list
            addnode(resnode); // Add the node at the head of the linked list
            mp[key_] = head->next; // Update the key-node entry in the map to point to the new head node
            return res;
        }
        return -1; // Key not found in the map
    }
    
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()) { // If the key exists in the map
            node* existingnode = mp[key_];
            mp.erase(key_); // Erase the key from the map
            deletenode(existingnode); // Delete the existing node from the linked list
        }
        if(mp.size() == cap) { // If the cache is already full
            mp.erase(tail->prev->key_); // Erase the key from the map corresponding to the tail node
            deletenode(tail->prev); // Delete the tail node from the linked list
        }
        
        addnode(new node(key_, value)); // Create a new node with the given key and value, and add it to the linked list
        mp[key_] = head->next; // Add the key-node entry to the map with the new head node
    }
};