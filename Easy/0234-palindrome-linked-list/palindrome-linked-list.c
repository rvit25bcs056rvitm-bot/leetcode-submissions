/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    struct ListNode* curr = head;
    int i = 0;
    int arr[10000000];
    while(curr != NULL){
        arr[i] = curr->val;
        i++;
        curr = curr->next;
    }
    int j = 0;
    i--;
    while(j<i){
        if(arr[j] != arr[i]){
            return false;
        } 
        j++;
        i--;
    }
    return true;

}