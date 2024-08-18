class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half
        ListNode* secondHalfStart = reverseList(slow);
        ListNode* firstHalfStart = head;
        
        // Step 3: Compare both halves
        ListNode* p1 = firstHalfStart;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // Step 4 (Optional): Restore the list
        reverseList(secondHalfStart);
        
        return result;
    }
};
