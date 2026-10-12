
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char arr[1000000];
int top = -1;

char pop() {
    char popped = arr[top];
    top--;
    return popped;
}

void push(char value) {
    top++;
    arr[top] = value;
}

bool isValid(char* s) {
    top = -1;  // Reset stack for each test case

    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else {
            if (top == -1) {
                return false;
            }

            char popped = pop();

            if ((s[i] == ')' && popped != '(') ||
                (s[i] == '}' && popped != '{') ||
                (s[i] == ']' && popped != '[')) {
                return false;
            }
        }

        i++;
    }

    return top == -1;
}
