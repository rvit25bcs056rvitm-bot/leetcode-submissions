#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head3->next = NULL;

    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* temp3 = head3;

    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
        }

        struct ListNode* newnode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newnode->val = sum % 10;
        newnode->next = NULL;
        carry = sum / 10;

        temp3->next = newnode;
        temp3 = newnode;
    }

    struct ListNode* result = head3->next;
    free(head3);

    return result;
}