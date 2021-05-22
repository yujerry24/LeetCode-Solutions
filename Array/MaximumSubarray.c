#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
    int min= INT_MIN;
    int temp=0;
    for(int i=0; i<numsSize; i++) {
        temp+=nums[i];
        if(temp>min) {
            min=temp;
        }
        if(temp<0) {
            temp=0;
        }
    }
    return min;
}