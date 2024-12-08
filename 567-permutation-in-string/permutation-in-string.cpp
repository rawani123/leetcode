class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: If s1 is longer than s2, it's impossible for s2 to contain
        // a permutation of s1
        if (s1.size() > s2.size())
            return false;

        // Frequency arrays to store counts of characters
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);

        // Fill the frequency array for s1 and the initial window in s2
        for (int i = 0; i < s1.size(); ++i) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        // Check if the initial window matches
        if (s1_count == s2_count)
            return true;

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); ++i) {
            // Include the new character in the window
            s2_count[s2[i] - 'a']++;
            // Remove the character that is no longer in the window
            s2_count[s2[i - s1.size()] - 'a']--;

            // Check if the current window matches
            if (s1_count == s2_count)
                return true;
        }

        // If no match is found
        return false;
    }
};