class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);       // Odd length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);   // Even length palindromes
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};
 