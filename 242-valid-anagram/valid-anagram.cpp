class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char, int> charCount;

        
        if (s.size() != t.size()) return false;

        for (char c : s) {
            charCount[c]++;
        }

       
        for (char c : t) {
            charCount[c]--;
            
            if (charCount[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
