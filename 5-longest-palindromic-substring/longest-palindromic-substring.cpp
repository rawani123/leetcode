class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start = 0,
            end = 0; // To track the indices of the longest palindrome
        for (int i = 0; i < s.size(); i++) {
            // 1️⃣ Odd length palindrome (center at i)
            int len1 = expandFromCenter(s, i, i);

            // 2️⃣ Even length palindrome (center between i and i+1)
            int len2 = expandFromCenter(s, i, i + 1);

            int len = max(len1, len2); // Maximum length from the two expansions
            if (len > end - start + 1) {
                start = i - (len - 1) / 2; // Adjusting the start index
                end = i + len / 2;         // Adjusting the end index
            }
        }
        return s.substr(start,
                        end - start + 1); // Extract the longest palindrome
    }

    // \U0001f504 Function to expand from the center and return palindrome lengt
    int expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Final palindrome length
    }
};