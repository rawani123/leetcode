class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        vector<string> ans;
        int minimumIndexSum = INT_MAX;
        
        
        for (int i = 0; i < list1.size(); i++) {
            map1[list1[i]] = i;
        }
        
        
        for (int j = 0; j < list2.size(); j++) {
            if (map1.find(list2[j]) != map1.end()) {
                int i = map1[list2[j]];
                int indexSum = i + j;
                if (indexSum < minimumIndexSum) {
                    minimumIndexSum = indexSum;
                    ans = {list2[j]};  
                } else if (indexSum == minimumIndexSum) {
                    ans.push_back(list2[j]);  
                }
            }
        }
        
        return ans;
    }

};