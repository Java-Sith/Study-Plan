/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 

nums2 has a length of n. */

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int n) {
    int last = nums1Size - 1;
    int first = m - 1;
    int second = n - 1;
    if (n == 0)
    {
        return;
    }
    else if (m == 0 || nums1[first] < nums2[0])
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    } else {
        while (second >= 0)
        {
            if (nums1[first] < nums2[second])
            {
                nums1[last] = nums2[second];
                nums2[second] = 0;
                last--;
                second--;
            } else {
                nums1[first + 1] = nums1[first];
                nums1[first] = nums1[first - 1]; 
                last--;
                first--;
            }
        }
    }
}

int main() {

    int nums1[] = {1, 2, 3, 0, 0, 0};

    int nums2[] = {2, 5, 6};

    int length1 = sizeof(nums1) / sizeof(nums1[0]);

    int length2 = sizeof(nums2) / sizeof(nums2[0]);

    merge(nums1, 6, 3, nums2, 3);

    printf("Doing first test case!\n");

    for (int i = 0; i < length1; i++)
    {
        printf("%d ", nums1[i]);
    }

    printf("\n");
    
    int nums3[] = {1};

    int nums4[] = {0};

    length1 = sizeof(nums3) / sizeof(nums3[0]);

    length2 = sizeof(nums4) / sizeof(nums4[0]);

    merge(nums1, 1, 1, nums2, 0);

    printf("Doing second test case!\n");

    for (int i = 0; i < length1; i++)
    {
        printf("%d ", nums3[i]);
    }

    printf("\n");

    int nums5[] = {0};

    int nums6[] = {1};

    length1 = sizeof(nums5) / sizeof(nums5[0]);

    length2 = sizeof(nums6) / sizeof(nums6[0]);

    merge(nums5, 1, 0, nums6, 1);

    printf("Doing third test case!\n");

    for (int i = 0; i < length1; i++)
    {
        printf("%d ", nums5[i]);
    }

    printf("\n");

    return 0;
}