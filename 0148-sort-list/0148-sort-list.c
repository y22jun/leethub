 struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if (!left) return right;
    if (!right) return left;
    if (left->val < right->val)
    {
        left->next = merge(left->next, right);
        return left;
    } 
    else 
    {
        right->next = merge(left, right->next);
        return right;
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* left = head;
    struct ListNode* right = slow->next;
    slow->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}