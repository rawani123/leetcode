class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* pA = headA;
        ListNode* pB = headB;
        
        // Traverse both lists
        while (pA != pB) {
            // If pA reaches the end of list A, redirect it to the head of list B
            pA = (pA == nullptr) ? headB : pA->next;
            // If pB reaches the end of list B, redirect it to the head of list A
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        // If they meet, pA (or pB) is the intersection node, otherwise, it's nullptr
        return pA;
    }
};
