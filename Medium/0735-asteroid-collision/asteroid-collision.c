/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int push(int *arr, int top, int value) {
    top++;
    arr[top] = value;
    return top;
}

int pop(int *arr, int top) {
    top--;
    return top;
}

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *arr = (int *)malloc(asteroidsSize*sizeof(int));
    int top = -1;
    int i = 0;
    for(int i = 0; i < asteroidsSize; i++){
        if(asteroids[i] >= 0){
            top = push(arr, top, asteroids[i]);
        }
        else{
            while(top >= 0 && arr[top] > 0 && abs(asteroids[i]) > arr[top]){
                top = pop(arr, top);
            }
            if(top < 0 || arr[top] < 0){
                top = push(arr, top, asteroids[i]);
            }
            else if(abs(asteroids[i]) == arr[top]){
                top = pop(arr, top);
            }
        }
    }
    *returnSize = top+1;
    return arr;
}