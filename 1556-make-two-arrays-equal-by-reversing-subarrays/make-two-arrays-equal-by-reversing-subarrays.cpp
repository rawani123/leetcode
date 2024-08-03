

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> countMap;
        
        
        for (int num : target) {
            countMap[num]++;
        }
        
        
        for (int num : arr) {
            countMap[num]--;
           
            if (countMap[num] < 0) {
                return false;
            }
        }
        
        
        for (const auto& pair : countMap) {
            if (pair.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};
