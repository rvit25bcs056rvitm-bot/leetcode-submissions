/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int *res = (int *)malloc(numsSize*sizeof(int));
    int sum = 0;
    for(int i = 0; i<numsSize; i++){
        sum += nums[i];
        res[i] = sum;
    }
    *returnSize = numsSize;
    return res;
}