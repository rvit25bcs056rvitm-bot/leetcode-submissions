#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// checking whether brackets({,}, (, ), [, ]) are closed or not

char arr[1000000];
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


char* removeDuplicates(char* s) {
    top = -1;
    int i = 0;
    while(s[i] != '\0'){
        if(top != -1 && arr[top] == s[i]){
            pop();
        }
        else{
            push(s[i]);
        }
        i++;
    }
    char *res = (char *)malloc((top+2)*sizeof(char));
    for(int j = 0; j<=top; j++){
        res[j] = arr[j];
    }
    res[top + 1] = '\0';
    return res;
}