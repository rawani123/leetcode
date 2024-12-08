class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // Frequency array for characters 'A' to 'Z'
        int start = 0, max_freq = 0, ans = 0;

        for (int end = 0; end < s.size(); ++end) {
            freq[s[end] - 'A']++;  // Update frequency of the current character
            max_freq = max(max_freq, freq[s[end] - 'A']);  // Update max_freq in the window

            int window_length = end - start + 1;
            if (window_length - max_freq > k) {
                freq[s[start] - 'A']--;  // Shrink the window
                start++;
            }

            ans = max(ans, end - start + 1);  // Update the maximum length
        }

        return ans;
    }
};
