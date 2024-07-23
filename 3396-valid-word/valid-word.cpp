class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
       bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }
            if (isVowel(c)) {
                hasVowel = true;
            } else if (isalpha(c)) {
                hasConsonant = true;
            }
        }
            return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
};