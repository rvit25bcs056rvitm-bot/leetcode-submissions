#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int arr[10000];
int top = -1;

void push(int val) {
    top++;
    arr[top] = val;
}

int pop() {
    int popped = arr[top];
    top--;
    return popped;
}

int calPoints(char** operations, int operationsSize) {
    top = -1;
    int result = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == '+') {
            int a = arr[top];
            int b = arr[top - 1];
            int c = a + b;
            push(c);
        }
        else if (operations[i][0] == 'C') {
            pop();
        }
        else if (operations[i][0] == 'D') {
            int num = arr[top] * 2;
            push(num);
        }
        else {
            int num = atoi(operations[i]);
            push(num);
        }
    }

    for (int i = 0; i <= top; i++) {
        result += arr[i];
    }

    return result;
}