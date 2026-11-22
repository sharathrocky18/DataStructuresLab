struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = &dummy;

    while (cur->next != NULL) {
        if (cur->next->val == val)
            cur->next = cur->next->next;   // skip the node
        else
            cur = cur->next;               // move forward
    }
    return dummy.next;
}