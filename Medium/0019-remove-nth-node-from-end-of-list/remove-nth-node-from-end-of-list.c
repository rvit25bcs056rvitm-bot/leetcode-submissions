/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    struct ListNode* gcurr = head;

    for(int i = 0; i<n; i++){
        gcurr = gcurr->next;
    }
    
    if (gcurr == NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while(gcurr->next != NULL){
        gcurr = gcurr->next;
        curr = curr->next;   
    }
    struct ListNode* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}