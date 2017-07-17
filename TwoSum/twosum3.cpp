#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    
	return arg1>arg2?1:arg1<arg2?-1:0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int nums_back [numsSize];
    memcpy( nums_back, nums, numsSize*sizeof(int) );

    qsort(nums, numsSize, sizeof(int), compare_ints);
    int i = 0, j = numsSize - 1;
    while (nums[i] + nums[j] != target) {
        if (nums[i] + nums[j] > target)
            j--;
        else
            i++;
    }
    int *ans = (int*)malloc(sizeof(int)*2);
    
    int k;
    for (k = 0; k < numsSize; k++) {
        if (nums_back[k] == nums[i]) {
            ans[0] = k;
            break;
        } else if (nums_back[k] == nums[j]) {
            ans[1] = k;
            break;
        } 
    }
    for (k = numsSize - 1; k >=0; k--) {
        if (nums_back[k] == nums[j]) {
            ans[1] = k;
            break;
        } else if (nums_back[k] == nums[i]) {
            ans[0] = k;
            break;
        } 
    }
    return ans;
}

int main(){
	int nums[]={2,7,11,15};
	int *a;
	a = twoSum(nums,4,9);
	for(int i=0;i<2;i++)
		printf("%d\t",a[i]);
	return 0;
}
