class Solution {
public:
    bool isPalindrome(string s) {
        // Remove non-alphanumeric characters and convert to lowercase
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // Check if the filtered string is a palindrome
        int left = 0, right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};