/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int arr[100000];
int top = -1;

int pop(){
    int popped = arr[top];
    top--;
    return popped;
}

void push(int value){
    top++;
    arr[top] = value;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    top = -1;
    int *result = calloc(temperaturesSize, sizeof(int));

    for (int i = 0; i < temperaturesSize; i++) {

        while (top != -1 &&
               temperatures[i] > temperatures[arr[top]]) {

            int oldIndex = pop();

            result[oldIndex] = i - oldIndex;
        }

        push(i);
    }

    *returnSize = temperaturesSize;

    return result;
}