#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int arr[100000];
int top = -1;

int pop(){
    return arr[top--];
}

void push(int value){
    top++;
    arr[top] = value;
}

int evalRPN(char** tokens, int tokensSize) {
    top = -1;
    int i = 0;
    while(i<tokensSize){
        if (strcmp(tokens[i], "+") != 0 &&
            strcmp(tokens[i], "-") != 0 &&
            strcmp(tokens[i], "*") != 0 &&
            strcmp(tokens[i], "/") != 0) 
            {
            push(atoi(tokens[i]));
        }
        else{
            if(tokens[i][0] == '+'){
                int a = pop();
                int b = pop(); 
                push(a+b);
            }
            else if(tokens[i][0] == '-'){
                int a = pop();
                int b = pop();  
                push(b-a);
            }
            else if(tokens[i][0] == '*'){
                int a = pop();
                int b = pop();  
                push(a*b);
            }
            else if(tokens[i][0] == '/'){
                int a = pop();
                int b = pop();  
                push(b/a);
            }
        }
        i++;
    }
    return pop();
}