class Solution {
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;

        while (cur != NULL && cur->next != NULL) {
            if (cur->val == cur->next->val)
                cur->next = cur->next->next;   // skip the duplicate
            else
                cur = cur->next;               // move forward
        }
        return head;
    }
};