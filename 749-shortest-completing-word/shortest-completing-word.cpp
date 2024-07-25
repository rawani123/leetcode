
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> freq;
        
        // Populate the frequency map with characters from the licensePlate
        for (char c : licensePlate) {
            if (isalpha(c)) {
                c = tolower(c);
                freq[c]++;
            }
        }
        
        string ans;
        int min_length = INT_MAX;
        
        for (string& word : words) {
            if (isCompletingWord(word, freq)) {
                if (word.length() < min_length) {
                    min_length = word.length();
                    ans = word;
                }
            }
        }
        
        return ans;
    }

private:
    bool isCompletingWord(string& word, unordered_map<char, int>& freq) {
        unordered_map<char, int> wordFreq;
        
        for (char c : word) {
            wordFreq[c]++;
        }
        
        for (auto& entry : freq) {
            if (wordFreq[entry.first] < entry.second) {
                return false;
            }
        }
        
        return true;
    }
};