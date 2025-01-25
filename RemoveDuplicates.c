/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 

The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, return k to finish.

Further challenge: Allow at most one duplicate in the array

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    int pivot = nums[0];
    if (numsSize == 0)
    {
        return 0;
    } else {
        for (int i = 0; i < numsSize - 1; i++)
        {
            if (nums[i] != pivot)
            {
                pivot = nums[i];
                k++;
                nums[k] = pivot;
            } else {
                continue;
            }
        }
    }
    return k + 1;
}

int main() {

    int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};    

    int expectedNums[] = {0, 0, 1, 1, 2, 3, 3};

    int length1 = sizeof(nums) / sizeof(nums[0]);

    int length2 = sizeof(expectedNums) / sizeof(expectedNums[0]);

    int k = removeDuplicates(nums, length1);

    assert(k == length2);

    for (int i = 0; i < length2; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    printf("All test cases pass!\n");

    return 0;
}