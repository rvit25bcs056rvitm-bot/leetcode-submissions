/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int arr[100];
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

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *result = malloc(pricesSize*sizeof(int));
    int k = 0;
    top = -1;
    for (int i = 0; i < pricesSize; i++) {
        result[i] = prices[i];
    }
    for(int i = 0; i<pricesSize; i++){
        while(top != -1 && prices[i] <= prices[arr[top]]){
            int popped = pop();
            result[popped] = prices[popped] - prices[i];
        }
        push(i);
        k++;
    }
    *returnSize = pricesSize;
    return result;
}