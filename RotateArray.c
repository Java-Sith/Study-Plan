/* 

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

A good hint is to reverse the array or parts of it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reverse(int* nums, int start, int end) {
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main() { 

    int nums[] = {-1, -100, 3, 99};

    int k = 2;

    int expectedNums[] = {3, 99, -1, -100};

    int length = sizeof(nums) / sizeof(nums[0]);

    rotate(nums, length, k);

    for (int i = 0; i < length; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    printf("All tests pass!\n");

    return 0;
}
