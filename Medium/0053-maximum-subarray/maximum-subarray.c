int maxSubArray(int* nums, int numsSize) {
    int i = 0;
    int j = 0;
    int maxsum = nums[0];
    int currsum = 0;
    while (j < numsSize) {
        if (currsum < 0) {
            i = j;
            currsum = 0;
        }
        currsum += nums[j];
        if (currsum > maxsum) {
            maxsum = currsum;
        }
        j++;
    }

    return maxsum;
}