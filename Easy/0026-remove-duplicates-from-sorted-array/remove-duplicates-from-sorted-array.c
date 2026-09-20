int removeDuplicates(int* nums, int numsSize) {
    int j = 0;

    for(int i = 0; i < numsSize; i++){
        if(i == 0){
            nums[j] = nums[i];
            j++;
        }
        else if(nums[i] != nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
        else{
            continue;
        }
    }

    return j;
        
}