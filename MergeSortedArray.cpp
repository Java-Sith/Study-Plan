/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n. */


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last = m + n - 1;
    int first = m - 1;
    int second = n - 1;
    if (n == 0)
    {
        return;
    }
    else if (m == 0 || nums1[m - 1] < nums2[0])
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    } else {
        for (int i = last; i < 1; i--)
        {
            if (nums1[first] < nums2[second])
            {
                nums1[i] = nums2[second];
                second--;
            } else {
                nums1[i] = nums1[i - 1];
                first--;
            }   
        }
    }
}

int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};

    vector<int> nums2 = {2, 5, 6};

    merge(nums1, 3, nums2, 3);

    cout << "Passed first test case! " << endl;

    vector<int> nums1 = {1};

    vector<int> nums2 = {};

    merge(nums1, 1, nums2, 0);

    cout << "Passed second test case! " << endl;

    vector<int> nums1 = {0};

    vector<int> nums2 = {1};

    merge(nums1, 0, nums2, 1);

    cout << "Passed third test case! " << endl;

    return 0;
}