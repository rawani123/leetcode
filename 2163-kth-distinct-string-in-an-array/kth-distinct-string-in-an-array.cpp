

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequency;
        
        // Step 1: Count the frequencies of each string
        for (const auto& str : arr) {
            frequency[str]++;
        }
        
        // Step 2: Find the k-th distinct string without storing all distinct strings
        int count = 0;
        for (const auto& str : arr) {
            if (frequency[str] == 1) {
                count++;
                if (count == k) {
                    return str;
                }
            }
        }
        
        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};

