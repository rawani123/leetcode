#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 10000; // Size of the hash table
    vector<vector<pair<int, int>>> table; // Vector of vector of pairs to handle collisions
    
    int hash(int key) {
        return key % SIZE; // Hash function
    }
    
public:
    MyHashMap() : table(SIZE) {}
    
    void put(int key, int value) {
        int index = hash(key);
        // Search for key in the bucket
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key exists
                return;
            }
        }
        // Key not found, insert new pair
        table[index].emplace_back(key, value);
    }
    
    int get(int key) {
        int index = hash(key);
        // Search for key in the bucket
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return value if key exists
            }
        }
        return -1; // Key not found
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        // Search for key in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it); // Remove key-value pair
                return;
            }
        }
    }
};
