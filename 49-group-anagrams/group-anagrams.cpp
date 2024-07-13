class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;  
        
        for (string& s : strs) {  
            string key = s;     
            sort(key.begin(), key.end());           
            mp[key].push_back(s);
        }
        
        vector<vector<string>> groupedAnagrams;
        for (auto& kv : mp) {
            groupedAnagrams.push_back(kv.second); 
        }
        
        return groupedAnagrams;
    }
};