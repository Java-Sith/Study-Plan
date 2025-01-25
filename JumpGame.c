/*

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

bool hasZeroes(int* nums, int numSize) {
    for (int i = 0; i < numSize; i++)
    {
        if (nums[i] == 0)
        {
            return true;
        }
    }
    return false;
}

bool canJump(int *nums, int numSize) {
    int maxReach = nums[0];
    int finalIndex = numSize - 1;
    if (!hasZeroes(nums, numSize))
    {
        return true;
    }
    while (nums[finalIndex - 1] > 0)
    {
        finalIndex--;
    }
    for (int i = 0; i < finalIndex; i++)
    {
        maxReach = nums[i];
        if (i > maxReach)
        {
            return false;
        }
        if (maxReach >= (finalIndex - i))
        {
            return true;
        }
    }
    return false;
}

int main() {

    //int nums[] = {1, 1, 2, 5, 2, 1, 0, 0, 1, 3};
    int nums[] = {3, 2, 1, 0, 4};
    //int nums[] = {2, 3, 1, 1, 4};
    int numSize = sizeof(nums) / sizeof(nums[0]);

    if (canJump(nums, numSize))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}