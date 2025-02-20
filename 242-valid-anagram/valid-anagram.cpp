class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();++i){
            hash[s[i]]++;
            hash[t[i]]--;
        }

        for(int i=0;i<s.size();i++){
            if(hash[s[i]]!=0) return false;
        }

        return true;
    }
};