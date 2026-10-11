/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int arr[100000];
    int top;
};

void push(struct stack* stack1, int val) {
    stack1->top++;
    stack1->arr[stack1->top] = val;
}

int pop(struct stack* stack1) {
    int popped = stack1->arr[stack1->top];
    stack1->top--;
    return popped;
}

int* nextGreaterElement(int* nums1, int nums1Size,
                        int* nums2, int nums2Size,
                        int* returnSize) {

    struct stack* stack1 = malloc(sizeof(struct stack));
    stack1->top = -1;

    // Allocate space for values from 0 to 10000
    int* nextGreater = malloc(10001 * sizeof(int));

    for (int i = 0; i <= 10000; i++) {
        nextGreater[i] = -1;
    }

    // Find the next greater element for each value in nums2
    for (int i = 0; i < nums2Size; i++) {

        while (stack1->top != -1 &&
               nums2[i] > stack1->arr[stack1->top]) {

            int popped = pop(stack1);
            nextGreater[popped] = nums2[i];
        }

        push(stack1, nums2[i]);
    }

    // Construct the answer for nums1
    int* result = malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        result[i] = nextGreater[nums1[i]];
    }

    *returnSize = nums1Size;

    free(stack1);
    free(nextGreater);

    return result;
}