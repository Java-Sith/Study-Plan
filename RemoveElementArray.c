/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 

The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 

The remaining elements of nums are not important as well as the size of nums. Also return k.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Comparison function for integers
int compare(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    int last = numsSize - 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (last < k)
        {
            break;
        }
        else if (nums[i] == val)
        {
            int temp = nums[i];
            while (nums[last] == val)
            {
                last--;
            }
            nums[i] = nums[last];
            nums[last] = temp;
        } else {
            k++;
        }
    }
    return k;
}

int main() {

    int nums[] = {3, 2, 2, 3};    

    int val = 3;

    int expectedNums[] = {2, 2};

    int length1 = sizeof(nums) / sizeof(nums[0]);

    int length2 = sizeof(expectedNums) / sizeof(expectedNums[0]);

    int k = removeElement(nums, length1, val);

    assert(k == length2);

    qsort(nums, length1, sizeof(nums[0]), compare);

    for (int i = 0; i < length2; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    return 0;
}