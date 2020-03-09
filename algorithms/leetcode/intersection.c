/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Tested on leetcode
// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/


int getListLen(struct ListNode *list) {
    int len = 0;
    
    for ( ; list ; list = list->next, len++);
    
    return len;
}


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len_a = getListLen(headA);
    int len_b = getListLen(headB);
 
    struct ListNode *f;
    struct ListNode *s;
    int diff = 0;
    
    // pick the list to advance first
    if (len_a > len_b) {
        diff = len_a - len_b;
        f = headA;
        s = headB;
    } else {
        diff = len_b - len_a;
        f = headB;
        s = headA;
    }
    
    // both f and s would start at the right lengths
    // after this
    for ( ; diff != 0 ; f = f->next, diff--);

    // advance both f and s
    // until they're NULL or the intersection is found
    while (f && s) {
        if (f == s) {
            return f;
        }
        f = f->next;
        s = s->next;
    }
    
    return NULL;
}
