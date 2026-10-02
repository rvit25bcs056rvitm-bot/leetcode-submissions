#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *final = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *current = list1;
    struct ListNode *current1 = list2;
    int size = 0;

    while (current != NULL) {
        current = current->next;
        size++;
    }

    while (current1 != NULL) {
        current1 = current1->next;
        size++;
    }

    struct ListNode *newNode;

    for (int i = 0; i < size; i++) {
        newNode = malloc(sizeof(struct ListNode));

        if (list1 != NULL && (list2 == NULL || list1->val <= list2->val)) {
            newNode->val = list1->val;
            list1 = list1->next;
        }
        else {
            newNode->val = list2->val;
            list2 = list2->next;
        }

        newNode->next = NULL;

        if (final == NULL) {
            final = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return final;
}