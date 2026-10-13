char arr[100];
int top = -1;
char arr1[100];
int top1 = -1;
char pop(){
    char popped = arr[top];
    top--;
    return popped;
}

void push(char value){
    top++;
    arr[top] = value;
}

char pop1(){
    char popped = arr1[top1];
    top1--;
    return popped;
}

void push1(char value){
    top1++;
    arr1[top1] = value;
}


bool backspaceCompare(char* s, char* t) {
    top = -1;
    top1 = -1;
    //for 1st string
    int i = 0;
    while(s[i]!='\0'){
        if(s[i] == '#'){
            if(top != -1){
                pop();
            }
        }
        else{
            push(s[i]);
        }
        i++;
    }
    char res1[100];
    for(int i = 0; i<=top; i++){
        res1[i] = arr[i];//res[i] = res[i] + arr[i] will give error as ascii value addition 
    }
    res1[top + 1] = '\0';
    
    //for 2nd string
    i = 0;
    while(t[i]!='\0'){
        if(t[i] == '#'){
            if(top1 != -1){
                pop1();
            }
        }
        else{
            push1(t[i]);
        }
        i++;
    }
    char res2[100];
    for(int i = 0; i<=top1; i++){
        res2[i] = arr1[i];
    }
    res2[top1 + 1] = '\0';

    //for comparsion of 1st and 2nd string
    i = 0;
    int j = 0;
    if (top != top1) {
    return false;
    }
    while(res1[i] != '\0' && res2[j] != '\0'){
        if(res1[i] != res2[j]){
            return false;
        }
        i++;
        j++;
    }
    return true;
}