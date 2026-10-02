/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* curr = node->next;
    node->val = curr->val;
    node->next = curr->next;
    free(curr);
}