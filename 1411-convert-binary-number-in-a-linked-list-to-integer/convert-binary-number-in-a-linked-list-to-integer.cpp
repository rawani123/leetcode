class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            // Shift result to the left by 1 to make space for the new bit
            result = (result << 1) | head->val;
            head = head->next; // Move to the next node
        }
        return result;
    }
};
