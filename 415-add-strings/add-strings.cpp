class Solution {
public:
    string addToString(string num1, string num2) {
        string ans;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int sum, carry = 0;

        
        while (index1 >= 0 || index2 >= 0 || carry) {
            sum = carry;
            if (index1 >= 0) {
                sum += num1[index1] - '0';
                index1--;
            }
            if (index2 >= 0) {
                sum += num2[index2] - '0';
                index2--;
            }
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans += c;
        }

        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addStrings(string num1, string num2) {
        if (num1.size() > num2.size()) {
            return addToString(num1, num2);
        } else {
            return addToString(num2, num1);
        }
    }
};