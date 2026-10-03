/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL){
        return false;
    }
    struct ListNode *curr = head;
    struct ListNode *tcurr = head;
    int flag = 0;
    while(tcurr != NULL && tcurr->next != NULL){
        curr = curr->next;
        tcurr = tcurr->next->next;
        if(tcurr == curr){
            return true;
        }
    }
    return false;
}