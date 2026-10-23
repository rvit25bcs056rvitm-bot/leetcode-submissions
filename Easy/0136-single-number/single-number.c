int singleNumber(int* nums, int numsSize) {

    int value = 0;

    for(int i = 0; i < numsSize; i++) {
        value ^= nums[i];
    }

    return value;
}