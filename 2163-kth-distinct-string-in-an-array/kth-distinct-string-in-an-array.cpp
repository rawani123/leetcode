

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> frequency;
        
        // Step 1: Count the frequencies of each string
        for (const auto& str : arr) {
            frequency[str]++;
        }
        
        // Step 2: Collect the distinct strings
        vector<string> distinctStrings;
        for (const auto& str : arr) {
            if (frequency[str] == 1) {
                distinctStrings.push_back(str);
            }
        }
        
        // Step 3: Return the k-th distinct string if it exists
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        }
    }
};

