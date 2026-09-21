/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int i; //left
    int j = numsSize - 1; //right
    int k = numsSize - 1; // right of the the nums2 array
    int * nums2 = malloc(numsSize * sizeof(int));
    while(i <= j){
        if(abs(nums[i]) > abs(nums[j])){
            nums2[k] = nums[i]*nums[i];
            i++;
        }
        else{
            nums2[k] = nums[j]*nums[j];
            j--; 
        }

        k--;
    }
    
    *returnSize = numsSize; 
    return nums2;

}