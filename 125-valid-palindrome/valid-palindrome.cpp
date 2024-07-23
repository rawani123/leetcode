class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
      for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) {
           filtered += tolower(s[i]);
        }
    }  
    
    string fromStart;
    for(auto c:filtered){
        fromStart+=c;
    }
    string fromEnd;
    for(int i=filtered.size()-1;i>=0;i--){
        fromEnd+=filtered[i];
    }
    return (fromStart==fromEnd);
    }
};