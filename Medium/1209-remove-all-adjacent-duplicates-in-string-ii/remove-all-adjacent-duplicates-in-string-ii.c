#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char arr[100000];
int count[100000];
int top = -1;

char pop(){
    char popped = arr[top];
    top--;
    return popped;
}

void push(int value){
    top++;
    arr[top] = value;
}

char* removeDuplicates(char* s, int k) {
    
    top = -1;
    int i = 0;

    while(s[i] != '\0'){
        if (top != -1 && arr[top] == s[i]) {
        push(s[i]);
        count[top] = count[top - 1] + 1;
        }
        else {
            push(s[i]);
            count[top] = 1;
        }

        if (count[top] == k) {
            top = top - k;
        }
        i++;
    }

    char *res = (char *)malloc((top+2)*sizeof(char));
    i = 0;

    while(i<=top){
        res[i] = arr[i];
        i++;
    }

    res[top+1] = '\0';
    return res;
    
}