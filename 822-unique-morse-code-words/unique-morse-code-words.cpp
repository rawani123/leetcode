class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        
        vector<string> morseCodes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                                               "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
                                               "..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> uniqueTransformations;

        for (string& word : words) {
            string transformation;
            for (char c : word) {
                transformation += morseCodes[c - 'a'];
            }
            uniqueTransformations.insert(transformation);
        }

        return uniqueTransformations.size();
    }
};