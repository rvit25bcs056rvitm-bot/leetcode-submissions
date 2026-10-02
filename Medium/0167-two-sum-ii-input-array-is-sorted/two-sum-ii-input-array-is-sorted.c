/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *rarr = malloc(*returnSize*sizeof(int));
    int i;
    int j = numbersSize-1;
    while(i<j){
        if((numbers[i] + numbers[j]) > target){
            j--;
        }
        else if((numbers[i] + numbers[j]) < target){
            i++;
        }
        else{
            rarr[0] = i+1;
            rarr[1] = j+1;
            return rarr;
        }
    }
    *returnSize = 0;
    free(rarr);
    return NULL;
}