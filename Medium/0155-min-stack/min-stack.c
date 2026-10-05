


typedef struct {
    int arr[100000];
    int minArr[100000];
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int value) {
    obj->top++;
    obj->arr[obj->top] = value;
    if (obj->top == 0) {
        obj->minArr[obj->top] = value;
    }
    else if (value < obj->minArr[obj->top - 1]) {
        obj->minArr[obj->top] = value;
    }
    else {
        obj->minArr[obj->top] = obj->minArr[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minArr[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/