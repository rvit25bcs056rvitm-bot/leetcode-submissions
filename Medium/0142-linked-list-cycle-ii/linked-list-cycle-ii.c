/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* followup = head;
    do {
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        fast = fast->next->next;
        slow = slow->next;
    }while(slow != fast);

    while(slow != followup){
        slow = slow->next;
        followup = followup->next;
    }
    
    return followup;
}