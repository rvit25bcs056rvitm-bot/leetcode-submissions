/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* curr = head;
    struct ListNode* next = head->next;
    while(curr != NULL && next != NULL){
        if(curr->val == next->val){
            struct ListNode* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            next = curr->next;
        }
        else{
            curr = curr->next;
            next = next->next;
        }
    }
    return head;
}