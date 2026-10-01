/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    int i = 0;
    struct ListNode* current = head;
    while(current != NULL){
        current = current->next;
        i++;
    }
    struct ListNode* current1 = head;
    for(int j = 0; j<i/2; j++){
        current1 = current1->next;
    }
    return current1;
}