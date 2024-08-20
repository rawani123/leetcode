class MyHashSet {
private:
    // Using a boolean array to store presence of elements
    bool hashSet[1000001];
    
public:
    // Constructor initializes the array with all false values
    MyHashSet() {
        // Initializing all elements to false
        for(int i = 0; i <= 1000000; ++i) {
            hashSet[i] = false;
        }
    }
    
    // Adds the key to the set by marking its corresponding index as true
    void add(int key) {
        hashSet[key] = true;
    }
    
    // Removes the key from the set by marking its corresponding index as false
    void remove(int key) {
        hashSet[key] = false;
    }
    
    // Checks if the key is present in the set by returning the value at the corresponding index
    bool contains(int key) {
        return hashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
